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

// p.283
// 8.7 트리의 응용: 수식 트리 처리
// 그림 8-32

// BST노드의 삭제

// 1. 무자식 노드 (terminal node) 삭제는 쉽다.
//    다만, 부모 노드만 영향을 받는다. 해당 link = null로 설정
//    !!!! 무자식 노드 == root ==> root를 null로 변환


// 2. 홑(1개)자식,
//    자식에게 자기 자리를 물려주고, 나의 부모에게 '그 자식'을 연결시켜준다.
//    ** 내가 부모의 '어떤 자식'인지 잘 기억했다가, 그렇게 '그 자식'연결해준다.
//    !!!! 홑자식 노드 == root,
//              root로 하여금 남은 자식을 가리키게 한다.

// 3. 쌍(2개)자식,
//    왼쪽집안에서 가장 큰 노드가 올라오거나, 오른쪽 집안에서 가장 작은 노드가 올라와서 대체
//    !!!! 쌍자식 노드 == root

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
