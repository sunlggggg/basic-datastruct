#include<iostream>
using namespace std; 
struct Node {
    int data; 
    Node * left; 
    Node * right; 
    Node(int _data ){
        data = _data;
        left = right = NULL; 
    }
}; 
int arrData[10]= {1, 2, -1, 4 , -1, -1, 3 , -1, -1 } ; 
// 构建二叉树 
void build(Node *& node, int * pIndex ){
    if(arrData[*pIndex] == -1) {
        (*pIndex)++;
    } else {
        node = new Node(arrData[*pIndex]) ; 
        (*pIndex)++;
        build(node->left, pIndex);
        build(node->right, pIndex);
    }
}
void buildTree(Node *& node , int * arrData ){
    int data = 0 ;     
    int * pIndex = &data;
    build(node, pIndex); 
}

// 遍历二叉树
void traverse(Node * node ){
    if(node == NULL ){
        return;
    }
    cout<< node->data << endl; 
    traverse(node->left );
    traverse(node->right );
}
// 交换二叉树
void exchange(Node * node ){
    if(node == NULL ){
        return ; 
    } else {
        Node * tmp ; 
        tmp = node->right;
        node->right = node->left;
        node->left = tmp; 
        exchange(node->left);
        exchange(node->right);
    }
}
int main(){
    Node * node;
    buildTree(node,arrData);
    traverse(node);
    exchange(node);
    traverse(node);
    return 0 ; 
}