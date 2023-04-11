#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = 0;

void addToBST(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->left =0;
    _new->right = 0;
    _new->data = _v;

    // BST에 노드를 추가
    // 1. BST가 텅텅 비어있는 경우
    if (root == 0) {
        root = _new;
        return;
    }

    // 2. BST에 뭐가 있는 경우,
    // 이 때는 자기 위치를 찾아 가야 한다. 어디가서 붙어야 하는지
    // root를 움직일 수 없으니, 별도의 포인터 필요
    struct node* spear = root;
    while (1) {

        if (spear->data < _new->data) { // _new는 오른쪽으로 가야하는데,,,,
            // 1. 그 자리가 비었네,
            if (spear->right == 0) {
                spear->right = _new;
                return;
            }
            else { // 2. 아, 누군가 그 자리를 차지하고 있어서, 더 내려가 봐야 하는 상황
                spear = spear->right;
            }

        }
        else {  // 왼쪽으로 가야하는데
            
            // 1. 그 자리가 비었네,
            if (spear->left == 0) {
                spear->left = _new;
                return;
            }
            else { // 2. 아, 누군가 그 자리를 차지하고 있어서, 더 내려가 봐야 하는 상황
                spear = spear->left;
            }

        }
    }

}



void traversal_preorder(struct node* _cur) {

    if(_cur == 0) {
        return;
    }

    printf("%d\n", _cur->data);
    traversal_preorder(_cur->left);
    traversal_preorder(_cur->right);
}

void traversal_inorder(struct node* _cur) {
    
    if (_cur == 0 ){
        return;
    }
    
    traversal_inorder(_cur->left);
    printf("%d\n", _cur->data);
    traversal_inorder(_cur->right);
}

void traversal_postorder (struct node* _cur) {
    
    if (_cur == 0 ){
        return;
    }
    
    traversal_postorder(_cur->left);
    traversal_postorder(_cur->right);
    printf("%d\n",_cur->data);
}

#if 1   // stack
#define STACK_SZ 10

struct node* stack[STACK_SZ];
int top = -1;

void push(struct node* _cur){
    if ( top == (STACK_SZ-1)) {
        // stack full
        return;
    }
    top++;
    stack[top] = _cur;
}

struct node* pop(void) {
    if (top == -1){
        return 0;
    }
    struct node* temp = stack[top];
    top--;
    return temp;
}

#endif

// 재귀함수는 위험해!!!,
// 재귀함수 없이 inorder를 구현해 보자.
// 어떻게?

void nonrecurcive_inorder(struct node* _cur) {
    
    while(1) {
        
        while(1) {  // 왼쪽으로 내려가면서 push

            if(_cur != 0) {
                push(_cur);
                _cur = _cur->left;
            }
            else {
                break;
            }
        }
        _cur = pop();
        if(_cur == 0) {
            break;
        }
        printf("%d\n", _cur->data);
        _cur = _cur->right;



    }
}

int main(void) {

    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);

    // printf("%d\n", (root->data == 20));
    // printf("%d\n", (root->left->data == 10));
    // printf("%d\n", (root->right->data == 30));
    // printf("%d\n", (root->left->left->data == 5));
    // printf("%d\n", (root->right->right->data == 40));

    struct node* spear = root;

    // traversal_inorder(spear);
    // traversal_preorder(spear);
    // traversal_postorder(spear);

    nonrecurcive_inorder(root);
    return 0;
}