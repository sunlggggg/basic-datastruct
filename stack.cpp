#include<iostream>
#include<string>
using namespace std;

typedef int T;

static const int stackEmptyCode = 1;

struct Node {
    T data;
    Node * next;
    Node(T _data){
        data = _data;
        next = NULL;
    }
};

class AccessEmptyStackException:public exception {
    public:
    const char* what()const throw(){
        return "stack is empty";
    }
};

class Stack {
    public:
    Stack(){
        pTop = NULL;
    }

    void push(T data){
        Node *node = new Node(data);
        cout << node->data << endl;
        node->next = pTop;
        pTop = node;
    }

    T pop(){
        if(pTop != NULL){
            Node * node = pTop; 
            pTop = pTop->next; 
            free(node);
        } else {
            throw AccessEmptyStackException();
        } 
        T d;
        return d;
    }

    T top(){
        if (pTop != NULL){
            return pTop->data;
        } else {
            throw AccessEmptyStackException();
        }    
        T d;
        return d;
    }

    bool empty(){
        return pTop == NULL ? true : false; 
    }

    private: 
    Node * pTop;
};

int main(){
    Stack stack; 
    stack.push(1);
    stack.push(2);
    stack.push(3);

    cout << stack.top() << endl; 

    stack.pop();

    cout << stack.top() << endl;

    stack.pop();

    cout << stack.top() << endl;

    stack.pop();

    stack.top();

    return 0;
}
