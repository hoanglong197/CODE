#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int a, b, c;
    float area;
} Triangle;

typedef struct TreeNode {
    Triangle data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(Triangle tri) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = tri;
    newNode->left = newNode->right = NULL;
    return newNode;
}

TreeNode* insertNode(TreeNode* root, Triangle tri) {
    if (root == NULL) {
        return createNode(tri);
    }
    if (tri.area < root->data.area) {
        root->left = insertNode(root->left, tri);
    } else {
        root->right = insertNode(root->right, tri);
    }
    return root;
}

void printTriangle(Triangle tri) {
    printf("Tam giac: canh = (%d, %d, %d), dien tich = %.2f\n", tri.a, tri.b, tri.c, tri.area);
}

float tinhDienTich(int a, int b, int c) {
    float s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int laTamGiac(int a, int b, int c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

int main() {
    int n;
    printf("Nhap so luong tam giac: ");
    scanf("%d", &n);

    Triangle danhSachTamGiac[n];
    Triangle stackTamGiac[n];
    int stackTop = -1;
    Triangle queueTamGiac[n];
    int queueDau = 0, queueCuoi = -1;
    TreeNode* bstRoot = NULL;

    for (int i = 0; i < n; ++i) {
        int a, b, c;
        printf("Nhap canh cua tam giac %d (a, b, c): ", i + 1);
        scanf("%d %d %d", &a, &b, &c);

        if (!laTamGiac(a, b, c)) {
            printf("Tam giac khong hop le, khong the luu tru.\n");
            i--;
            continue;
        }

        float dienTich = tinhDienTich(a, b, c);

        Triangle tamGiacMoi = {a, b, c, dienTich};
        danhSachTamGiac[i] = tamGiacMoi;

        stackTamGiac[++stackTop] = tamGiacMoi;

        queueTamGiac[++queueCuoi] = tamGiacMoi;

        bstRoot = insertNode(bstRoot, tamGiacMoi);
    }

    printf("\nCac tam giac duoc luu trong danh sach:\n");
    for (int i = 0; i < n; ++i) {
        printTriangle(danhSachTamGiac[i]);
    }

    printf("\nCac tam giac duoc luu trong Stack:\n");
    for (int i = stackTop; i >= 0; --i) {
        printTriangle(stackTamGiac[i]);
    }

    printf("\nCac tam giac duoc luu trong Queue:\n");
    for (int i = queueDau; i <= queueCuoi; ++i) {
        printTriangle(queueTamGiac[i]);
    }

    printf("\nCac tam giac duoc luu trong Cay nhi phan (theo dien tich tang dan):\n");

    return 0;
}

