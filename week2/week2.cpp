#include <stdio.h>
#include <stdlib.h>


// pointer, p.91
#if 0
int main(void){

    // int a = 10;

    // 변수가 저장된 위치(주)를 접근하기 위한
    // 수단 ====> point type

    // 주소를 저장하기 위한 데이터형, pointer type

    // int* // *: 주소를 저장하는 타입 의미, 
            // int: 포인터를 이용해서 그 위치에서 1번에 읽고 쓸 수 있는 데이터량, int == 4 byte


    // pa, pc가 차지하는 메모리 공간의 크기는 다를까?

    // int* pa;
    char* pc;
    float* pf;

    // p.91 null pointer
    // 아무 것도 가리키지 않는 포인터.
    // NULL, 0  ===> 포인터 변수 안에 저장된 주소가 올바른 것인지, 아닌지 구분해 주는 역할
    // int* pa = 0;
    // int* pb = NULL;

    // p.90 포인터 연산자
    // 1. 주소 연산자
    // int a = 10;
    // &a  // 변수 a가 저장되어있는 메모리상의 주소
    // &pa

    // 2. 간접참조연산자, *
    // 주의!!! 포인터 변수애 대해서만 적용가능!!!!!!!!
    int a = 20;
    int* pa = &a;
    printf("%d  %d\n", a, *pa);
    printf("%p  %p  %p\n", &a, pa, &pa);


    return 0;
}
#endif

#if 0
// p. 91 함수 매개변수로 포인터 사용하기

void change_two_num(int a, int b) { // call by value
    int temp;
    temp = b;
    b = a;
    a = temp;
    return;
}

// call by reference <---- 포인터를 이용해서 가능
void real_change(int* x, int* y){
    int temp;
    temp = *y;
    *y = *x;
    *x = temp; 
}

int main(void) {
    int a = 10;
    int b = 20;

    printf("%d %d\n", a, b);
    change_two_num(a, b);
    printf("%d %d\n", a, b);
    real_change(&a, &b);
    printf("%d %d\n", a, b);

    return 0;
}
#endif

// p.92 배열과 포인터
// 친밀한 관계
// 배열: 같은 데이터형의 값들이 메모리의 "연속된 공간"에 저장되어 있는 것
// int a[10]; 10개 공간이 쭈루룩....

#if 0
int main(void){
    int a[10];

    printf("%d %d\n", a[0], a[9]);

    // 배열 이름은 포인터 그 자체
    printf("%p\n", a);

    // a === &a[0]

    // a + 1 == &a[1]

    return 0;
}
#endif

#if 0
int main(void){
    // p.94, 동적 메모리 할당
    // 정적메모리: 컴파일할 때 사용하는 메모리양이 모두 결정,
    // 동적메모리: 수행하면서 메모리 할당, 속도가 느려 운영체제가 대빵, 그러나 원하는 만큼 딱,
    //          단, free를 안하면 메모리 낭비
    //          프로그램이 계속 수행되면, malloc만 계속하고, free를 안 하면, memory leak
    // malloc (memory allocation)
    // free (메모리 해제)

    // char* p = (char *)malloc(100);    // 100 바이트 공간을 할당해서, 시작주소를 반환한다.
    // if(p == 0) {
    //     printf("메모리 없음!!\n");
    //     return -100;
    // }
    // p = (char*)malloc(200);           // unreferenced space problem. 우주 미아
    // free(p);

    // dangli

    // char* p = (char*)malloc(100);
    // char* q = p;
    // free(q);                          // 할당받은 공간을 운영체제에게 반환

    // *p = 20;

    // p.96 구조체와 포인터
    
    typedef struct AAA{
        int a;
        char b;
    };

    AAA a;
    a.a = 10;
    a.b = 'a';
    
    AAA* pa;
    pa = &a;
    pa->a = 40;
    pa->b = 'c';

    pa = (AAA *)malloc(sizeof(AAA));
    pa->a = 50;
    pa->b = 'd';
    free(pa);

    return 0;
}
#endif
// chapter 4
// Stack

// 구현?
// 입력되는 숫자를 저장하는 stack을 구현해 보자.

// 입력: push <-- stack에 값을 저장하는 operation
// 출력: pop <-- stack에서 값을 꺼내는 operation

#if 0
int main(void){

    push(4);
    push(5);
    push(1);
    
    printf("%d\n", pop());  // ---> 1
    printf("%d\n", pop());  // ---> 5


    return 0;
}

#endif
#if 0

#define STACK_SZ 10

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
int main(){
    push(4);
    push(5);
    push(6);
    push(7);

    pop();
    printf("%d\n", pop());

    return 0;
}

#endif

#if 1
#include <stdio.h>

// 미로부터 그려보자
// 2차원 배열, char
// '1'이 저장되어 있으면, 벽
// '0'가 저장되어 있으면, 공간

// 미로의 크기, 가로 6칸, 세로 6칸
#define MAZE_SIZE 6
#define STACK_SIZE MAZE_SIZE*MAZE_SIZE

// row, column 좌표를 저장하는 데이터형
typedef struct {
   int r;
   int c;
} LOC;

LOC stack[STACK_SIZE];
int top = -1;

char maze[MAZE_SIZE][MAZE_SIZE] = {
   {'1','1','1','1','1','1'},
   {'e','0','1','0','0','1'},  // e : entrance
   {'1','0','0','0','1','1'},
   {'1','0','1','0','1','1'},
   {'1','0','1','0','0','x'},  // x : exit
   {'1','1','1','1','1','1'}
};

// 미로를 예쁘게 출력해보는 함수
void printMaze(void) {
   for (int i = 0; i < MAZE_SIZE; i++) {
      for (int j = 0; j < MAZE_SIZE; j++) {
         printf("%c ", maze[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int isFull(void) {
   return (top == (STACK_SIZE - 1));
}

int isEmpty(void) {
   return (top == -1);
}

// push할 좌표 (_r, _c)를 받아서,
// 앞으로 갈 곳들만 stack에 push한다.
// 벽('1'), 지나온 곳('.'), 음수 좌표등은 모두 제외.
void push(int _r, int _c) {

   // 음수 좌표를 거르자
   if ((_r < 0) || (_c < 0)) {
      return; // 개무시
   }
   // 벽, 지나온 곳 걸러내자
   if ((maze[_r][_c] == '1') || (maze[_r][_c] == '.')) {
      return;
   }

   // full인지 검사
   if (isFull()) {
      return;
   }

   // 이제 진짜로 push
   LOC temp = { _r, _c };
   top++;
   stack[top] = temp;
   return;
}

LOC pop(void) {
   // 에러조건
   if (isEmpty()) {
      LOC err_loc = { -1, -1 };  // 스택이 비었다는 의미
      return err_loc;
   }
   // 정상상태
   LOC result = stack[top];
   top--;
   return result;
}


int main(void) {

   LOC cur = { 1, 0 };  // 시작위치

   while (1) {

      // 탈출 조건==> x에 도착하면 끝
      if (maze[cur.r][cur.c] == 'x') {
         printf("길 찾았음... 집간다. \n");
         return 0;
      }
      // 내가 다녀갔음을 표시
      maze[cur.r][cur.c] = '.'; // 나의 발자국을 남긴다.왜냐? 다시 오지 않기 위해서

      // 잠깐, 지도를 보자
      printMaze();

      // 현재 위치에서 갈 수 있는 곳들을 모두 stack에 집어 넣는다.
      // 모두 4군데, 상/하/좌/우
      push(cur.r - 1, cur.c);
      push(cur.r + 1, cur.c);
      push(cur.r, cur.c - 1);
      push(cur.r, cur.c + 1);

      // 스택에 저장된 좌표를 꺼내서 현재 위치로 삼는다.
      cur = pop();

      // 스택이 비어있는지 확인, 만약 비었다면 ===> 길없음.
      if ((cur.r == -1) && (cur.c == -1)) {
         printf("길없음!!!!");
         return -1;
      }
   }
   return 0;
}

#endif

