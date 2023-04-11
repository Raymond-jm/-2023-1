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
// deque이 되기 위한, 2가지 함수
// 1. add_to_front
// 우선, full인지 체크하고, 아니면,
// 먼저 front를 -1 움직여,,, 한바퀴 도는 것은 좀 생각
//     front위치에 _v를 넣는다.
void add_to_front(int _v) {
    if (isFull()) {
        printf("queue full\n");
        return;
    }
    front = (front - 1 + Q_SZ) % Q_SZ; // <-------- 한바퀴 역으로 도는 거
    que[front] = _v;
    
    return;
}
// 2. del_from_rear
int del_from_rear() {
    // empty 인지 체크
    if(isEmpty()) {
        return -999;
    }
    // rear를 조정
    rear = (rear - 1 + Q_SZ) % Q_SZ;
    // rear위치의 값을 반환
    return que[rear];

}
int main(void) {
    add_to_front(10);
    enqueue(20);
    enqueue(30);
    add_to_front(40);

    while (!isEmpty()) {
        printf("%d\n", del_from_rear());
    }


    return 0;
}