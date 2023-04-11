// Doubly Linked List
// 팔이 두개, next, prev
// head
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node* next;
    struct node* prev;  // DLL에서 추가 된 부분
};

struct node* head = 0;

// node를 만드는  함수
struct node* createNode(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;
    return _new;
}

void addToDLL(int _v) {
    struct node* _new = createNode(_v); // 새로운 구조체 주소 할당
    if(head == 0) {
        head = _new;
        return;
    }

    struct node* spear = head;
    while (spear->next != 0) {
        spear = spear->next;
    }

    // 이 순간, spear는 마지막 노드를 콕 찌르고 있음.

    // 팔 연결, 악수
    spear->next = _new;
    _new->prev = spear;


    return;
}

void displayReverseDLL(void) {

    if (head == 0) {
        return;
    }

    struct node* spear = head;
    while (spear->next != 0) {
        spear = spear->next;
    }
    while (spear != 0) {
        printf("%d\n", spear->data);
        spear = spear->prev;
    }

    // 거꾸로 오면서

    
    return;
}

struct node* findNode(int _t) {

    struct node* spear = head;
    while (spear != 0){
        if (spear->data == _t) {
                return spear;
        }
        spear = spear->next;
    }
    return spear;
}

void insertIntoDLL(int _t, int _v) {
    
    struct node* spear = findNode(_t);
    
    if (spear == 0) {
        return;
    }
    struct node* _new = createNode(_v);

    // 아쉬운 애가 손을 연결한다.
    _new->prev = spear;
    _new->next = spear->next;   // null인 경우도 상관없음
    spear->next = _new;

    if (_new->next != 0) {
        _new->next->prev = _new;
    }

    return;
    
}

void delFromDLL(int _t) {

    // _t를 가진 노드를 찾는다.
    struct node* spear = findNode(_t);
    if (spear == 0) {   // thank you.
        return;
    }
    // 인생 꼬이는 경우

    // 1. 하필 spear == head, head 주의
    if (spear == head) {
        // head 대피
        head = head->next;
        // 폭파
        free(spear);
        if (head != 0) {
            head->prev = 0;
        }
        return;
    }
    // 2. 중간 혹은 끝에 있는 노드
    spear->prev->next = spear->next;    // 죽겠지.... ㅎ 힘들지...
    if (spear->next != 0) { // 내 뒤에 누가 있을 때만 없으면 memory access violation
        spear->next->prev = spear->prev;
    } 
    free(spear);
}





int main(void) {

    addToDLL(10);
    addToDLL(20);
    addToDLL(30);

    // displayDLL();



    // 20을 가진 노드를 찾아서, 90을 가진 노드를 뒤에 추가
    insertIntoDLL(20, 90);

    delFromDLL(90);

    displayReverseDLL();



    return 0;

}