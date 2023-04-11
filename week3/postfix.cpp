#include <stdio.h>

#define STACK_SZ 20

int stack[STACK_SZ];
int top = -1;   // 현재 스택의 맨 꼭대기 위치 index

// stack이 full인지 검사
// full --> 1을 반환
// 아니면 --> 0을 반환

int isFull(void) {
    return (top == (STACK_SZ - 1));
}

int isEmpty(void) {
    return (top == -1);
}
// push, pop

void push(int _v) {

    if( isFull()) { //  더이상 push가 불가능
        printf("에러, stack full\n");
        return;
    }

    top++;
    stack[top] = _v;

    return;
}
int pop(void) {
    if(isEmpty()){
        printf("스택 empty\n");
        return -999;    //     -999는 에러상황을 나타내는

    }
    int result = stack[top];
    top--;
    return result;
}
/*
    v1과 v2를 받아서 , op 연산을 한 결과를 반환
*/
int calc_expr(char op, int v1, int v2){
    switch (op) {
        case '+':
            return(v1 + v2);
        case '-':
            return(v2 - v1);    // 순서 주의
        case '*':
            return(v1 * v2);
        case '/':
            return(v2 / v1);    // 순서 주의
        default:
        break;
    }
}

int main() {
    
    char postfix[] = "235*+";   // postfix expression
    int idx = 0;

    // 왼쪽에서 오른쪽으로 한글자씩 읽는 코드
    // expression 끝에 도달할 때까지... \0 은 expression 끝인 null 을 의미
    while (postfix[idx] != '\0'){
        
        // 숫자, 연산자. 둘 중 하나가 나온다.
        // 숫자인 경우 처리

        char _c = postfix[idx];    // 일단 복사, 이거 안해도 되지만,,

        if ((_c >= '0') && (_c <= '9')) {   // 숫자 확인
            push((int)(_c - '0'));
        }
        else {  // 숫자 아니면 연산자라고 생각
                // 그러나 이렇게 짜면 안됨!!!
            int v1 = pop();
            int v2 = pop(); 
            int res = calc_expr(_c, v1, v2);
            push(res);

        }
        idx++;
    }

    // 여기에 왔다면, 스택에는 숫자 1개가 있어야함!!

    printf("연산결과는 %d \n");

    return 0;
}