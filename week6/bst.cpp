// 레벨 순회

#include <stdio.h>
#include <stdlib.h>
#define Q_SZ 10


struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = 0;
struct node* que[Q_SZ];
int front = 0;
int rear = 0;

void enqueue(struct node* _cur) {
    if((rear + 1) % Q_SZ == front){
        return;
    }
    que[rear] = _cur;

    rear = (rear+1) % Q_SZ;
    return; 
}

struct node* dequeue(void) {
    if(front == rear) {
        return 0;
    }
    struct node* result = que[front];
    front = (front+1) % Q_SZ;

    return result;
}

void level_order(struct node* _cur) {   // 레벨 순회 위부터 아래로 왼쪽에서 오른쪽으로 차근차근 출력
    if(_cur == 0) {
        return;
    }

    enqueue(_cur);

    while(1) {
        if (front == rear) {
            break;
        }
        _cur = dequeue();
        printf("%d\n", _cur->data);
        if(_cur->left != 0){
            enqueue(_cur->left);
        }
        if(_cur->right != 0){
            enqueue(_cur->right);
        }

    }
}


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

int which_is_bigger(int a, int b) {

    if(a > b) {
        return a;
    }
    else {
        return b;
    }
}

// 높이 구하기,
int get_height(struct node* _cur) {
    
    if(_cur == 0) {     // NULL
        return 0;       // height
    }
    
    return 1 + which_is_bigger(get_height(_cur->left), get_height(_cur->right));
}

int get_node_count(struct node* _cur) {
    if(_cur == 0){
        return 0;
    }
    return 1 + get_node_count(_cur->left) + get_node_count(_cur->right);
}

int get_terminalnode_count (struct node* _cur) {
    if(_cur == 0) {
        return 0;
    }
    else if(_cur->left == 0 && _cur->right == 0) {
        return 1;
    }
    return get_terminalnode_count(_cur->left) + get_terminalnode_count(_cur->right);
}



int main() {
    
    addToBST(20);
    addToBST(10);
    addToBST(30);
    addToBST(40);
    addToBST(5);

    level_order(root);
    printf("%d\n", get_height(root));
    printf("%d\n", get_node_count(root));
    printf("%d\n", get_terminalnode_count(root));

}
