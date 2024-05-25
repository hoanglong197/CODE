#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TreeNode {
    int ma_so_sv;
    char ho_ten[50];
    int tuoi;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int ma_so_sv, char ho_ten[], int tuoi) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->ma_so_sv = ma_so_sv;
    strcpy(newNode->ho_ten, ho_ten);
    newNode->tuoi = tuoi;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct TreeNode* insertNode(struct TreeNode* root, int ma_so_sv, char ho_ten[], int tuoi) {
    if (root == NULL) {
        return createNode(ma_so_sv, ho_ten, tuoi);
    }

    if (ma_so_sv < root->ma_so_sv) {
        root->left = insertNode(root->left, ma_so_sv, ho_ten, tuoi);
    } else if (ma_so_sv > root->ma_so_sv) {
        root->right = insertNode(root->right, ma_so_sv, ho_ten, tuoi);
    }

    return root;
}

void NLR_traverse(struct TreeNode* root) {
    if (root != NULL) {
        printf("Ma so SV: %d - Ho ten: %s - Tuoi: %d\n", root->ma_so_sv, root->ho_ten, root->tuoi);
        NLR_traverse(root->left);
        NLR_traverse(root->right);
    }
}

void LRN_traverse(struct TreeNode* root) {
    if (root != NULL) {
        LRN_traverse(root->left);
        LRN_traverse(root->right);
        printf("Ma so SV: %d - Ho ten: %s - Tuoi: %d\n", root->ma_so_sv, root->ho_ten, root->tuoi);
    }
}

void LNR_traverse(struct TreeNode* root) {
    if (root != NULL) {
        LNR_traverse(root->left);
        printf("Ma so SV: %d - Ho ten: %s - Tuoi: %d\n", root->ma_so_sv, root->ho_ten, root->tuoi);
        LNR_traverse(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Them sinh vien\n");
        printf("2. Duyet cay theo phuong phap NLR\n");
        printf("3. Duyet cay theo phuong phap LRN\n");
        printf("4. Duyet cay theo phuong phap LNR\n");
        printf("5. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                int ma_so_sv, tuoi;
                char ho_ten[50];
                printf("Nhap ma so SV: ");
                scanf("%d", &ma_so_sv);
                printf("Nhap ho ten SV: ");
                scanf("%s", ho_ten);
                printf("Nhap tuoi: ");
                scanf("%d", &tuoi);
                root = insertNode(root, ma_so_sv, ho_ten, tuoi);
                break;
            }
            case 2:
                printf("Duyet cay theo phuong phap NLR:\n");
                NLR_traverse(root);
                break;
            case 3:
                printf("Duyet cay theo phuong phap LRN:\n");
                LRN_traverse(root);
                break;
            case 4:
                printf("Duyet cay theo phuong phap LNR:\n");
                LNR_traverse(root);
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 5);

    return 0;
}

