#include <stdio.h>
#include <stdlib.h>

// linked list의 기본 요소인 Node
// Linked List : LL
// singly Linked List : SLL
struct node {
    int data;
    struct node* next;
};
struct node* head  = 0;

void addToSLL(int _v) {

    // _v값을 저장할 node를 메모리에 마련한다.
    // data type을 casting 하는 이유
    // malloc의 반환값은 void*
    // type이 없으므로 (void), 적절한 type으로 casting
    // _new는 새로 할당받은 node 구조체의 주소를 가리키고 있다.

    // 주의!! _new를 잃어버리면, 할당받은 공간을 다시 찾아갈 방법이 없음.
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0; // 신규 노드는 뒤에 오는 노드가 없으므로, 0(null)로 초기화\

    // _new를 기존 SLL에 추가

    // 경우의 수, 2가지
    // 1. 빈 SLL일 경우
    if(head == 0) {
        head = _new;
        return;
    }
    // 2. 아닌 경우

    // 2.1 기존 SLL에서 맨 끝의 노드의 주소를 알아낸다.
    struct node*temp = head;
    while(temp->next != 0){
        temp = temp->next;
    }

    // 2.2 맨끝 노드의 next에 새로운 노드의 주소를 집어넣는다.
    temp->next = _new;
    return;
}

void displaySLL(void) {
    
    struct node* temp = head;

    while(1){
        if(temp ==0) break;
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
}

int countSLL(void) {
    struct node*temp = head;
    int cnt = 0;
    while (temp != 0) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

struct node* findSLL(int _v) {

    struct node* temp = head;

    while (temp != 0) {

        if (temp->data == _v){
            return temp;
        }
        temp = temp->next;
    }
    return temp;
}

void destroySLL(void) {
    struct node* spear = head;

    while(head != 0){
        head = head->next;
        free(spear);
        spear = head;
    }
    return;
}

void addToFront(int _v) {
    // 새로운 node를 1개 할당받아서, _v를 저장, 그 노드를 _new가 가리킨다.
    struct node* _new = (struct node *)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;

    // 경우의 수. 1 SLL == empty
    if (head == 0) {
        head = _new;
        return;
    }    

    // 경우의 수. 2, SLL에 뭔가 있을 때.
    _new->next = head;  // SLL의 대원칙 == 인생의 대원칙 == 새로 온 사람이 아쉽다. == 아쉽손
    head = _new;
    return;
}

int delFromFront(void) {

    if (head == 0) {
        return -999;
    }

    struct node* spear = head;
    // head 대피
    head = head->next;
    // 데이터 복사 보관
    int res = spear->data;
    // 폭파
    free(spear);
    // 저장값 반환
    return res;
}

int delFromLast(void) {
    // thank you. 1
    if (head == 0) {
        return -999;
    }

    // thank you.2, single node
    if (head->next == 0) {
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }

    // oh my god. 3
    // 1. 맨 뒤에서 두 번째 노드에 창을 꼽는다.
    struct node* spear = head;

    while(spear->next->next != 0) {
        spear = spear->next;
    }
    int res = spear->next->data;    // 데이터 대피
    // 폭파
    free(spear->next);
    // 끝단 처리
    spear->next = 0;

    return res;
}

// _findv값을 가진 노드를 찾아서,
// 그 뒤에 _addv를 가진 세로운 노드를 추가한다.
void insertInto(int _findv, int _addv) {

    // _findv를 가진 노드가 없다면,
    struct node* target = findSLL(_findv);
    if (target == 0) {  // findv를 가진 노드가 없다. thank you.
        return;
    }
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _addv;
    _new->next = 0;

    // 붙여넣기
    // SLL의 대원칙. 아쉽손
    _new->next = target->next;
    target->next = _new;
    return;

}

void delFromSLL(int _v) {

    // _v값을 가진 노드를 찾는닫.
    struct node* spear = findSLL(_v);

    if(spear == 0) {    // 못 찾으면, thank you
        return;
    }
    // 주의할 케이스.
    // 지워야 하는 것이 head인 경우
    if (head == spear) {
        // head 대피
        head = head->next;
        // 폭파
        free(spear);
        return;
    }

    // 나머지 케이스.
    // spear 꽂힌 노드가 중간에 있는 경우.

    struct node* prev = head;
    // prev가 창꽂힌 노드의 직전 노드가 될 때까지 이동
    while (prev->next != spear) {
        prev = prev->next;
    }
    
    prev->next = spear->next;
    free(spear);
    return;





}


int main(void) {
    addToSLL(10);
    addToSLL(20);
    addToSLL(30);
    addToSLL(40);


    // addToFront <--- 맨 앞 추가
    addToFront(90);
    addToFront(100);

    // delFromFront <--- 맨 앞 것을 제거
    delFromFront();
    delFromFront();

    // delFromLast <--- 맨 끝 것을 제거  
    delFromLast();




    // countSLL <--- SLL 안에 있는 노드 개수를 반환
    printf("SLL안의 노드 개수: %d\n", countSLL());

    // findSLL <--- SLL 안에 있는 특정 노드 위치를 검색
    printf("20을 가진 노드의 주소 %x\n", findSLL(20));
    struct node* temp = findSLL(20);
    printf("%d\n", temp->data);
    


    if (head != 0) {
        printf("제대로 destroy 하지 못했음.\n");
    }


    // insertInto <--- 특정 노드를 찾아서, 그 뒤에 추가
    insertInto(20, 99);


    // delFromSLL <--- 특정 노드를 찾아서 제거
    
    displaySLL();
    // destroySLL <--- SLL 노드를 모두 제거
    destroySLL();
    return 0;
}