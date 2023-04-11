#include <stdio.h>

// linked list의 기본 요소인 node
struct node {
    int data;
    struct node* next;
};
struct node* head  = 0;
// stack에 top, queue에는 front/rear, linked list에는 head


