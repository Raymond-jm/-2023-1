

#include <stdio.h>


// factorial을 계산하는 프로그램

// 3! == 3 * 2 * 1

// recursion을 이용해서 factorial을 계산해 보자
// recursion : 함수가 자기 자신을 호출하는 것.

void function_a(void) {
    function_a();
}

// 인수 n을 받아서, n!을 계산해서 반환
int factorial (int n) {

    // 탈출조건
    if (n == 1) {
        return 1;
    }
    return n * factorial(n-1);
}


// 반복을 이용한 factorial 계산

int factorial2 (int n){
    int result = 1;
    int i;
    for(i = 1; i <= n; i++){
        result = result * i;
    }
    return result;
}

// 거듭제곱 power

int my_power(int a, int b) {
    int res = 1;
    int i;
    for(i = 1; i<= b; i++) {
        res = res * a;
    }
    return res;
    
}

int my_power_recursion(int a, int b) {
    // 탈출 조건
    if(b == 1) {
        return a;
    }
    return a * my_power_recursion(a, b-1);
}

// O(log_2 n)
int my_power_fast(int a, int b){
    // b 짝수
    if (b % 2 == 0) {
        return my_power_fast(a * a, b / 2);
    }

    // b 홀수
    else {
        return a * my_power_fast(a * a, (b - 1) / 2);
    }
}

// 피보나치 수열의 계산

// n번째 피보나치 값을 반환하는 함수
// 0번째 : 0
// 1번째 : 1
// 2번째 : 1

int fibo(int n) {
    // 반복을 이용한 계산
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int pp = 0;     // previous-previous
    int p = 1;      // previous
    int result = 0; // 결과값

    for (int i = 2; i <= n; i++) {
        result = pp + p;
        pp = p;
        p = result;
    }
    return result;
}

// recursion을 이용한 fibonacci 계산 --> O(2^n)

int fibo_r(int n) { 
    // 탈출조건
    if (n == 0){
        return 0;
    }
    if (n == 1){
        return 1;
    }
    return fibo_r(n - 2) + fibo_r(n - 1);
}

// recursion 개선 배열에 중복되는 값 저장 --> O(n)


// 하노이 타워

// n : 몇 개의 접시를 옮기는지.,,, n개의 접시를 옮겨라
// from 폴대에서
// temp 폴대를 임시로 사용해서
// to 폴대로 옮기시오
void hanoi_tower(int n, int from, int temp, int to) {
    // 탈출
    if (n == 1) {
        return;
    }


    hanoi_tower(n-1, from, to, temp);
    // 마음 가볍게 돌 하나만, from에서 to로 옮긴다.
    printf("%d에서 %d로 돌을 한 개 움직입니다.\n", from, to);
    hanoi_tower(n-1, temp, from, to);
    return;
}
// 구조체
// 사람에 한 데이터를 저장하고 싶다.
// 사람마다 고유 번호가 있고, 나이 정보를 저장하고 싶다.

struct Person {
    int id;
    int age;
    float height;   // 키정보
};

typedef int aaa;

typedef struct{
    int id;
    int age;
    float height;
} PersonA;


int main(void) { 

    PersonA a;
    a.id = 1;
    a.age = 20;
    a.height = 170.0;

    printf("%d %d %.1lf", a.id, a.age, a.height);

    return 0;
}
