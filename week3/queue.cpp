#include <stdio.h>

#define Q_SZ 10 // 최대 9개
int que[Q_SZ];
int front = 0;  // 중요한 위치 변수,
int rear = 0;

int isEmpty() {
    return (front == rear);
}

int isFull() {  // rear 뒤에 front가 있으면, full
    return (((rear + 1) % Q_SZ) == front);
}

void enqueue(int _v) {
    if (isFull()) {
        printf("error");
        return;
    }
    // rear가 가리키고 있는 현재 위치에 넣는다.
    que[rear] = _v;
    // rear를 1개 증가시킨다,, 항상 한바퀴 돌아가는 경우를 생각
    rear = (rear + 1) % Q_SZ;
    return;
}

int dequeue(void) {
    // empty 체크
    if(isEmpty()) {
        return -999;    // error 표시, -999
    }
    // front 위치에 있는 것 뽑기
    int result = que[front];
    // front 조정
    front = (front + 1) % Q_SZ;

    // 뽑아 놓은 것 반환
    return result;

}

int main(void) {

    enqueue(4);
    enqueue(5);
    enqueue(7);

    while(!isEmpty()) {
        printf("%d\n", dequeue());  // 4, 5, 7
    }

    return 0;
}