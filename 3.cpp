#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define N 20

typedef struct sinhvien {
    char hoten[40];
    int tuoi;
} sinhvien;

typedef struct node {
    sinhvien data;
    struct node *link;
} node;

typedef struct stack {
    node *top;
} stack;

typedef struct queue {
    node *front;
    node *rear;
} queue;

void khoitaoStack(stack &s) {
    s.top = NULL;
}

int emptyStack(stack s) {
    return s.top == NULL ? 1 : 0;
}

void push(stack &s, sinhvien x) {
    node *p;
    p = new node;
    p->data = x;
    p->link = s.top;
    s.top = p;
}

sinhvien pop(stack &s) {
    node *p;
    sinhvien x;
    if (!emptyStack(s)) {
        p = s.top;
        s.top = p->link;
        x = p->data;
        delete p;
    }
    return x;
}

void khoitaoQueue(queue &q) {
    q.front = q.rear = NULL;
}

int emptyQueue(queue q) {
    if (q.front == NULL)
        return 1;
    else
        return 0;
}

void enqueu(queue &q, node *new_ele) {
    if (q.front == NULL) {
        q.front = new_ele;
        q.rear = q.front;
    } else {
        q.rear->link = new_ele;
        q.rear = new_ele;
    }
}

sinhvien dequeu(queue &q) {
    node *p;
    sinhvien x;
    if (!emptyQueue(q)) {
        p = q.front;
        x = p->data;
        q.front = p->link;
        delete p;
    }
    return x;
}

int main() {
    int n;
    stack s;
    queue q;
    sinhvien x;
    node *new_ele;

    printf("\nNhap so phan tu: ");
    scanf("%d", &n);

    khoitaoStack(s);
    khoitaoQueue(q);

    printf("\nNhap thong tin sinh vien:\n");

    for (int i = 0; i < n; i++) {
        printf("\nNhap ho ten: ");
        fflush(stdin);
        gets(x.hoten);
        printf("Nhap tuoi: ");
        scanf("%d", &x.tuoi);
        push(s, x);

        new_ele = new node;
        new_ele->data = x;
        new_ele->link = NULL;
        enqueu(q, new_ele);
    }

    printf("\nStack:\n");
    while (!emptyStack(s)) {
        x = pop(s);
        printf("Ho ten: %s\tTuoi: %d\n", x.hoten, x.tuoi);
    }

    printf("\nQueue:\n");
    while (!emptyQueue(q)) {
        x = dequeu(q);
        printf("Ho ten: %s\tTuoi: %d\n", x.hoten, x.tuoi);
    }

    getch();
    return 0;
}

