#include <stdio.h>
#include <stdlib.h>

#if 0   // 3 
struct node {
    int data;
    struct node* next;
};
struct node* head = 0;

void addToSLL(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;

    if(head == 0){
        head = _new;
        return;
    }
    struct node*temp = head;
    if(_v % 2 != 0){
        if(head->data % 2 == 0){
            _new->next = head;
            head = _new;
        }
        else {
            while(temp->next->data % 2 != 0){
                temp = temp->next;
            }
            _new->next = temp->next;
            temp->next = _new;
        }
    }
    else {
        while(temp->next != 0){
            temp = temp->next;
        }
        temp->next = _new;
    }
    return;
}

int main() {
    int n;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        addToSLL(n);
    }
    while(head != 0) {
        printf("%d ", head->data);
        head = head->next;
    }
}
#endif

#if 0   // 4
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;

struct node* createNode(int _v){
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;

    return _new;
}

void addToDLL(int _v){
    struct node* _new = createNode(_v);
    
    if(head == 0){
        head = _new;
        return;
    }

    if(_v % 2){
        if(head->data % 2 == 0){
            _new->next = head;
            head->prev = _new;
            head = _new;
        }
        else {
            struct node* spear = head;
            while((spear->next) && (spear->next->data % 2)) {
                spear = spear->next;
            }

            _new->next = spear->next;
            _new->prev = spear;
            spear->next = _new;
            if(_new->next){
                _new->next->prev = _new;
            }
            
            
        }
    }
    else {
        struct node* spear = head;
        while(spear->next != 0){
            spear = spear->next;
        }
        spear->next = _new;
        _new->prev = spear;
    }

    return;
}

void printFromRear(void) {
    struct node* spear = head;
    while(spear->next != 0){
        spear = spear->next;
    }
    while(spear != 0){
        printf("%d ", spear->data);
        spear = spear->prev;
    }
}

int main(void) {
    int n = 0;
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        addToDLL(n);
    }
    printFromRear();
}
#endif

#if 0   // 6

int main() {
    int n, result = 0, prev = 1, prevprev = 0;
    scanf("%d", &n);
    if(n == 0) {
        printf("0");
        return 0;
    }
    if(n == 1) {
        printf("1");
        return 0;
    }
    for (int i = 0; i < n-1; i++){
        result = prev + prevprev;
        prevprev = prev;
        prev = result;
    }
    printf("%d", result);
}
#endif

#if 0   // 7 [데이터구조] Stack by SLL 연습문제 - 7
struct node{
    int data;
    struct node* next;
};
struct node* head = 0;


int isEmpty() {
    return !head;
}

void push(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;

    if(isEmpty()){
        head = _new;
        return;
    }

    struct node* temp = head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = _new;


    return;
}
int pop(void) {
    struct node* spear = head;

    if(head == 0) {
        return -999;
    }

    if (head->next == 0) {
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }
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

int main() {
    int n;

    while(1){
        scanf("%d", &n);
        if(n == -1) {
            pop();
        }
        else if(n == 0){
            if(isEmpty()) {
                printf("0");
                return 0;
            }
            else {
                int sum = 0;
                while(head != 0){
                    sum += pop();
                }
                printf("%d", sum);
                return 0;
            }
        }
        else push(n);
    }
}
#endif

#if 0   // 8 [데이터구조] Stack by DLL 연습문제 - 8
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;


int isEmpty() {
    return !head;
}

void push(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;
    _new->prev = 0;

    if(isEmpty()){
        head = _new;
        return;
    }

    struct node* temp = head;

    while(temp->next){
        temp = temp->next;
    }
    temp->next = _new;
    _new->prev = temp;
    

    return;
}

int pop(void) {
    struct node* spear = head;

    if(head == 0) {
        return -999;
    }

    if (head->next == 0) {
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }
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

void printFromLast(){
    struct node* spear = head;
    while(spear->next){
        spear = spear->next;
    }
    while(spear){
        printf("%d ", spear->data);
        spear = spear->prev;
    }
}
void printFromFirst(){
    struct node* spear = head;
    while(spear){
        printf("%d ", spear->data);
        spear = spear->next;
    }
}
int main() {
    int n;

    while(1){
        scanf("%d", &n);
        if(
            n == -1) {
            pop();
        }
        else if(n == 0){
            if(isEmpty()) {
                printf("-999");
                return 0;
            }
            else {
                printFromLast();
                printFromFirst();
                return 0;
            }
        }
        else push(n);
    }
}
#endif

#if 0   // 9 [데이터구조] Queue by SLL 연습문제 - 9
struct node{
    int data;
    struct node* next;
};
struct node* head = 0;

int isEmpty(void){
    return !head;
}
void enqueue(int _v){
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;

    if(head == 0){
        head = _new; 
        return;
    }
    struct node* spear = head;
    while(spear->next){
        spear = spear->next;
    }
    spear->next =_new;

    return;
}

int dequeue(void){
    if(head == 0){
        return -999;
    }
    struct node* spear = head;

    int res = spear->data;
    head = head->next;
    free(spear);
    return res;
}

int findMax(){
    struct node* spear = head;

    int max = spear->data;
    while(spear->next){
        spear = spear->next;
        if(max < spear->data){
            max = spear->data;
        }
    }

    return max;
}

int main() {
    int n = 0;
    while(1) {
        scanf("%d", &n);
        if(n == -1) {
            dequeue();
        }
        else if (n == 0) {
            if(isEmpty()){
                printf("0");
                return 0;
            }
            printf("%d",findMax());
            return 0;
        }
        else {
            enqueue(n);
        }
    }
}
#endif

#if 0   // Queue by DLL 10 가장 큰 값과 가장 작은 값을 제외하고, 나머지 값들을 오름차순으로 출력한다.
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;

struct node* createNode(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;
    return _new;
}


void enqueue(int _v) {
    struct node* _new = createNode(_v);
    if(head == 0){
        head = _new;
        return;
    }

    struct node* spear = head;
    while(spear->next) {
        spear = spear->next;
    }
    spear->next = _new;
    _new->prev = spear;
}


int dequeue(void) {
    if(head == 0){
        return -999;
    }
    
    if(head->next == 0){
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }

    struct node* spear = head;
    int res = head->data;
    head = head->next;
    head->prev = 0;
    
    free(spear);
    spear = 0;
    
    return res;
}
int findMax(){
    struct node* spear = head;
    int max = head->data;
    while(spear->next){
        spear = spear->next;
        if(max < spear->data){
            max = spear->data;
        } 
    }
    return max;
}

int findMin() {
    struct node* spear = head;
    int min = head->data;
    while(spear->next){
        spear = spear->next;
        if(min > spear->data){
            min = spear->data;
        } 
    }
    return min;
}
void asc() {
    struct node* spear = head;
    struct node* compare = spear->next;
    struct node* minNode = spear;
    int tmp = 0;
    int min = minNode->data;
    while(spear->next){
        minNode = spear;
        min = spear->data;
        while(1){
            if(min > compare->data){
                min = compare->data;
                minNode = compare;
            }
            compare = compare->next;
            if(!compare){
                break;
            }
        }
        tmp = minNode->data;
        minNode->data = spear->data;
        spear->data = tmp;

        spear = spear->next;
        compare = spear->next;
    }
}
void printAmong(){
    struct node* spear = head->next;
    while(1){
        printf("%d ", spear->data);
        spear = spear->next;
        if(!spear->next) break;
    }
}
int main(){
    int n = 0;
    while(1){
        scanf("%d", &n);
        if(n == -1){
            dequeue();
        }
        else if(n == 0){
            if(!head){
                printf("0");
                return 0;
            }
            else if(findMax == findMin){
                printf("-999");
                return 0;
            }
            else {
                printAmong();
                return 0;
            }
        }
        else{
            enqueue(n);
            asc();
        }
    }
}
#endif

#if 0   // 11 [데이터구조] 중복숫자 사라지는 Stack 연습문제 - 11
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;


int isEmpty() {
    return !head;
}

void push(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = 0;
    _new->prev = 0;

    if(isEmpty()){
        head = _new;
        return;
    }

    struct node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = _new;
    _new->prev = temp;
    

    return;
}

int pop(void) {
    struct node* spear = head;

    if(head == 0) {
        return -999;
    }

    if (head->next == 0) {
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }
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

void delFromDLL(int _t) {

    struct node* spear = findNode(_t);
    if (spear == 0) {
        return;
    }

    if (spear == head) {
        head = head->next; 
        free(spear);
        if (head != 0) {
            head->prev = 0;
        }
        return;
    }

    spear->prev->next = spear->next;
    if (spear->next != 0) { 
        spear->next->prev = spear->prev;
    } 
    free(spear);
}

void printFromLast(){
    struct node* spear = head;
    while(spear->next){
        spear = spear->next;
    }
    while(spear){
        printf("%d ", spear->data);
        spear = spear->prev;
    }
}


int main() {
    int n;

    while(1){
        scanf("%d", &n);
        if(
            n == -1) {
            pop();
        }
        else if(n == 0){
            if(isEmpty()) {
                printf("0");
                return 0;
            }
            else {
                printFromLast();
                return 0;
            }
        }
        else {
            delFromDLL(n);
            push(n);
        }
    }
}
#endif

#if 1   // 12 이미 A가 저장되어 있다면, 기존 A앞에 A가 하나 더 생기고,  새로운 A는 enqueue된다.
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;

struct node* createNode(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;
    return _new;
}


void enqueue(int _v) {
    struct node* _new = createNode(_v);
    if(head == 0){
        head = _new;
        return;
    }

    struct node* spear = head;
    while(spear->next) {
        spear = spear->next;
    }
    spear->next = _new;
    _new->prev = spear;
}


int dequeue(void) {
    if(head == 0){
        return -999;
    }
    
    if(head->next == 0){
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }

    struct node* spear = head;
    int res = head->data;
    head = head->next;
    head->prev = 0;
    
    free(spear);
    spear = 0;
    
    return res;
}
void frontToRear(){
    struct node* spear = head;
    while(1){
        printf("%d ",spear->data);
        spear = spear->next;
        if(!spear) break;
    }
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

    if (spear->prev == 0){
        head = _new;
    }
    // 아쉬운 애가 손을 연결한다.
    _new->next = spear;
    _new->prev = spear->prev;   // null인 경우도 상관없음
    spear->prev = _new;

    if (_new->prev != 0) {
        _new->prev->next = _new;
    }

    return;
    
}

int main(){
    int n = 0;
    while(1){
        scanf("%d", &n);
        if(n == -1){
            dequeue();
        }
        else if(n == 0){
            if(!head){
                printf("0");
                return 0;
            }
            else{
                frontToRear();
                return 0;
            }
        }
        else{
            insertIntoDLL(n,n);
            enqueue(n);
        }
    }
}
#endif
#if 0   // 13
struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = 0;

struct node* createNode(int _v) {
    struct node* _new = (struct node*)malloc(sizeof(struct node));
    _new->data = _v;
    _new->next = _new->prev = 0;
    return _new;
}


void enqueue(int _v) {
    struct node* _new = createNode(_v);
    if(head == 0){
        head = _new;
        return;
    }

    struct node* spear = head;
    while(spear->next) {
        spear = spear->next;
    }
    spear->next = _new;
    _new->prev = spear;
}


int dequeue(void) {
    if(head == 0){
        return -999;
    }
    
    if(head->next == 0){
        int res = head->data;
        free(head);
        head = 0;
        return res;
    }

    struct node* spear = head;
    int res = head->data;
    head = head->next;
    head->prev = 0;
    
    free(spear);
    spear = 0;
    
    return res;
}
int findMax(){
    struct node* spear = head;
    int max = head->data;
    while(spear->next){
        spear = spear->next;
        if(max < spear->data){
            max = spear->data;
        } 
    }
    return max;
}

int findMin() {
    struct node* spear = head;
    int min = head->data;
    while(spear->next){
        spear = spear->next;
        if(min > spear->data){
            min = spear->data;
        } 
    }
    return min;
}
void asc() {
    struct node* spear = head;
    struct node* compare = spear->next;
    struct node* minNode = spear;
    int tmp = 0;
    int min = minNode->data;
    while(spear->next){
        minNode = spear;
        min = spear->data;
        while(1){
            if(min > compare->data){
                min = compare->data;
                minNode = compare;
            }
            compare = compare->next;
            if(!compare){
                break;
            }
        }
        tmp = minNode->data;
        minNode->data = spear->data;
        spear->data = tmp;

        spear = spear->next;
        compare = spear->next;
    }
}
void printFromBack(){
    struct node* spear = head;
    while(spear->next){
        spear = spear->next;
    }
    while(1){
        printf("%d ", spear->data);
        spear = spear->prev;
        if(!spear) break;
    }
}
int main(){
    int n = 0;
    while(1){
        scanf("%d", &n);
        if(n == -1){
            dequeue();
        }
        else if(n == 0){
            if(!head){
                printf("0");
                return 0;
            }
            else {
                printFromBack();
                return 0;
            }
        }
        else{
            enqueue(n);
            asc();
        }
    }
}

#endif