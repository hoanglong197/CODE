#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define N 20

typedef struct node {
    long maso;
    char hoten[40];
    char diachi[100];
} node;

typedef struct stack {
    int top;
    node list[N];
} stack;

typedef struct Queue {
    int front, rear;
    node list[N];
} Queue;

void khoitaoStack(stack *s) {
    s->top = -1;
}

int emptyStack(stack s) {
    return s.top == -1 ? 1 : 0;
}

int fullStack(stack s) {
    return s.top == N - 1 ? 1 : 0;
}

void push(stack *s, node x) {
    if (!fullStack(*s))
        s->list[++s->top] = x;
}

node pop(stack *s) {
    node x;
    if (!emptyStack(*s))
        x = s->list[s->top--];
    return x;
}

void khoitaoQueue(Queue *q) {
    q->front = q->rear = -1;
}

int emptyQueue(Queue q) {
    if ((q.front == -1) && (q.rear == -1))
        return 1;
    else
        return 0;
}

int fullQueue(Queue q) {
    if (q.front == 0 && q.rear == N - 1)
        return 1;
    if (q.front == q.rear + 1)
        return 1;
    else
        return 0;
}

void enqueu(Queue *q, node x) {
    if (!fullQueue(*q)) {
        if (emptyQueue(*q))
            q->front = q->rear = 0;
        else if (q->rear == N - 1)
            q->rear = 0;
        else
            q->rear = q->rear + 1;
        q->list[q->rear] = x;
    }
}

node dequeue(Queue *q) {
    node t;
    if (!emptyQueue(*q)) {
        t = q->list[q->front];
        if (q->front == q->rear)
            khoitaoQueue(q);
        else if (q->front == N - 1)
            q->front = 0;
        else
            q->front = q->front + 1;
        return t;
    }
}

int main() {
    int n;
    stack s;
    Queue q;
    node x;

    printf("Nhap vao so phan tu: ");
    scanf("%d", &n);
    
    khoitaoStack(&s);
    khoitaoQueue(&q);
    
    for (int i = 0; i < n; i++) {
        printf("\nNhap ma so: ");
        scanf("%ld", &x.maso);
        printf("\nNhap ho ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("\nNhap dia chi: ");
        fflush(stdin);
        gets(x.diachi);
        push(&s, x);
        enqueu(&q, x);
    }
    
    printf("\nStack:\n");
    while (!emptyStack(s)) {
        x = pop(&s);
        printf("Ma so: %ld\tHo ten: %s\tDia chi: %s\n", x.maso, x.hoten, x.diachi);
    }
    
    printf("\nQueue:\n");
    while (!emptyQueue(q)) {
        x = dequeue(&q);
        printf("Ma so: %ld\tHo ten: %s\tDia chi: %s\n", x.maso, x.hoten, x.diachi);
    }
    
    getch();
    return 0;
}

