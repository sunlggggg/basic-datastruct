#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	string data;
	int prio;
	struct Node *next;
}Node, * PtrNode;

struct PriorityQueue {
	PtrNode front, rear;
};

PriorityQueue *initque();
int emptyque(PriorityQueue *q);
void insertNode(PriorityQueue *q, string data, int prio);
void deleteNode(PriorityQueue *q);
void display(PriorityQueue *q);


PriorityQueue *initque() {
	PriorityQueue *q = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	q->front = NULL;
	return q;
}

int emptyque(PriorityQueue *q) {
	return q->front == NULL;
}

void insertNode(PriorityQueue *q, string data, int prio) {
	//node *n = (node*)malloc(sizeof(node));
	PtrNode cur;
	PtrNode pre;
	//n->prio = prio;
	//n->next = NULL;
	pre = q->front;
	if (q->front == NULL) {
		q->front = (PtrNode)malloc(sizeof(Node));
		q->front->next = NULL;
		q->front->data = data;
        q->front->prio = prio;
	}
	else {
        cur = pre->next;
		// prio 2 
		// 4 3 3 1 
		// 
		while (pre != NULL) {
			if (cur == NULL) {
				pre->next = (PtrNode)malloc(sizeof(Node));
                pre->next->data = data;
                pre->next->prio = prio;
				pre->next->next = NULL;
				break;
			}
			else {
				if (prio <= cur->prio) {
					pre = pre->next;
					cur = cur->next;
				}
				else {
					pre->next = (PtrNode)malloc(sizeof(Node));
                    pre->next->data = data;
                    pre->next->prio = prio;
					pre->next->next = cur;
					break;
				}
			}
		}
	}
}

void deleteNode(PriorityQueue *q) {
	if (q->front == NULL)
		return;
	PtrNode frontTmp = q->front;
	q->front = q->front->next;
	free(frontTmp);
}


void display(PriorityQueue *q) {
    PtrNode cur = q->front;
    while(cur != NULL){
		cout << "人员: "<< cur->data << " 优先级: " << cur->prio << endl; 
		cur = cur->next;
	}
}

int main(){
	PriorityQueue *q;
	q = initque();
    // 排队人数
	int num;
	cout << "请输入排队的人数: "<<endl;
    cin >> num ;
    // 排队数据
	string data;
    // 优先级
	int prio;
	cout << "请输入排队人员信息: " << endl ;
    // 输入排队信息
	for (int i = 0; i < num; i++) {
        cin >> data >> prio;
		insertNode(q,data,prio);
		display(q);
	}
    // 删除节点
    while(q->front != NULL){
        deleteNode(q);
        cout << "删除节点后..."<<endl;
        display(q);
        cout <<endl;
    }
    return 0;
}
