#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct sv {
    char hoten[40];
    int tuoi;
} sv;

typedef struct node {
    sv data;
    struct node *left;
    struct node *right;
} node;

typedef struct node *TREE;

void taocay(TREE *goc) {
    sv x;
    printf("\nNhap thong tin sinh vien ('n' de dung):\n");
    printf("Nhap ho ten: ");
    fgets(x.hoten, sizeof(x.hoten), stdin);
    x.hoten[strcspn(x.hoten, "\n")] = '\0';  
    if (strcmp(x.hoten, "n") != 0) {
        printf("Nhap tuoi: ");
        scanf("%d", &x.tuoi);
        getchar();  
        *goc = (node *)malloc(sizeof(node));
        if (*goc == NULL) {
            printf("Khong du bo nho.\n");
            exit(1);
        }
        (*goc)->data = x;
        printf("Cay con trai cua %s:", x.hoten);
        taocay(&((*goc)->left));
        printf("Cay con phai cua %s:", x.hoten);
        taocay(&((*goc)->right));
    } else {
        *goc = NULL;
    }
}

void duyetNLR(TREE goc) {
    if (goc != NULL) {
        printf("\nHo ten: %s", goc->data.hoten);
        printf("\nTuoi: %d", goc->data.tuoi);
        duyetNLR(goc->left);
        duyetNLR(goc->right);
    }
}

void duyetLNR(TREE goc) {
    if (goc != NULL) {
        duyetLNR(goc->left);
        printf("\nHo ten: %s", goc->data.hoten);
        printf("\nTuoi: %d", goc->data.tuoi);
        duyetLNR(goc->right);
    }
}

void duyetLRN(TREE goc) {
    if (goc != NULL) {
        duyetLRN(goc->left);
        duyetLRN(goc->right);
        printf("\nHo ten: %s", goc->data.hoten);
        printf("\nTuoi: %d", goc->data.tuoi);
    }
}

int demLa(TREE goc) {
    if (goc == NULL)
        return 0;
    else if (goc->left == NULL && goc->right == NULL)
        return 1;
    else
        return demLa(goc->left) + demLa(goc->right);
}

int main() {
    TREE goc = NULL;
    taocay(&goc);
    printf("\n\nDuyet cay theo NLR:\n");
    duyetNLR(goc);
    printf("\n\nDuyet cay theo LNR:\n");
    duyetLNR(goc);
    printf("\n\nDuyet cay theo LRN:\n");
    duyetLRN(goc);
    printf("\n\nSo nut la: %d\n", demLa(goc));
    return 0;
}
