#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void tim_va_luu_so_nguyen_to(FILE *input_file, FILE *output_file) {
    int num;
    while (fscanf(input_file, "%d", &num) != EOF) {
        if (is_prime(num)) {
            fprintf(output_file, "%d\n", num);
        }
    }
}

void tron_tu_nhien(int arr[], int n) {
    srand(time(NULL)); 

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int isExist(int num, int arr[], int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *input_file, *output_file, *file_songuyen, *file_kgtk, *file_kqtk;
    int n, n_songuyen, n_kgtk, num_to_check;

    input_file = fopen("songuyen.dat", "w");
    if (input_file == NULL) {
        printf("Khong the mo file de ghi.");
        return 1;
    }

    printf("Nhap so luong so nguyen: ");
    scanf("%d", &n);

    printf("Nhap cac so nguyen:\n");
    for (int i = 0; i < n; i++) {
        int num;
        printf("So nguyen %d: ", i + 1);
        scanf("%d", &num);
        fprintf(input_file, "%d\n", num);
    }

    fclose(input_file);

    input_file = fopen("songuyen.dat", "r");
    if (input_file == NULL) {
        printf("Khong the mo file de doc.");
        return 1;
    }

    output_file = fopen("songto.dat", "w");
    if (output_file == NULL) {
        printf("Khong the mo file de ghi.");
        fclose(input_file);
        return 1;
    }

    tim_va_luu_so_nguyen_to(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Noi dung cua file songto.dat:\n");
    output_file = fopen("songto.dat", "r");
    if (output_file == NULL) {
        printf("Khong the mo file de doc.");
        return 1;
    }

    int num;
    while (fscanf(output_file, "%d", &num) != EOF) {
        printf("%d\n", num);
    }

    fclose(output_file);

    output_file = fopen("songto.dat", "r+");
    if (output_file == NULL) {
        printf("Khong the mo file de sap xep.");
        return 1;
    }

    int *arr_songto = (int*)malloc(n * sizeof(int));
    if (arr_songto == NULL) {
        printf("Khong du bo nho.");
        fclose(output_file);
        return 1;
    }

    int i = 0;
    while (fscanf(output_file, "%d", &arr_songto[i]) != EOF) {
        i++;
    }

    tron_tu_nhien(arr_songto, n);

    freopen("songto.dat", "w", output_file);
    if (output_file == NULL) {
        printf("Khong the mo file de ghi.");
        free(arr_songto);
        fclose(output_file);
        return 1;
    }

    for (int j = 0; j < n; j++) {
        fprintf(output_file, "%d\n", arr_songto[j]);
    }

    fclose(output_file);
    free(arr_songto);

    file_songuyen = fopen("songuyen.dat", "r");
    if (file_songuyen == NULL) {
        printf("Khong the mo file songuyen.dat de doc.");
        return 1;
    }

    fscanf(file_songuyen, "%d", &n_songuyen);

    int *arr_songuyen = (int*)malloc(n_songuyen * sizeof(int));
    for (int i = 0; i < n_songuyen; i++) {
        fscanf(file_songuyen, "%d", &arr_songuyen[i]);
    }

    fclose(file_songuyen);

    file_kqtk = fopen("sapxep.dat", "w");
    if (file_kqtk == NULL) {
        printf("Khong the mo file sapxep.dat de ghi.");
        free(arr_songuyen);
        return 1;
    }

    bubbleSort(arr_songuyen, n_songuyen);

    for (int i = 0; i < n_songuyen; i++) {
        fprintf(file_kqtk, "%d\n", arr_songuyen[i]);
    }

    fclose(file_kqtk);

    printf("Noi dung cua file sapxep.dat:\n");
    file_kqtk = fopen("sapxep.dat", "r");
    if (file_kqtk == NULL) {
        printf("Khong the mo file sapxep.dat de doc.");
        free(arr_songuyen);
        return 1;
    }

    while (fscanf(file_kqtk, "%d", &num) != EOF) {
        printf("%d\n", num);
    }

    fclose(file_kqtk);

    printf("Nhap so can kiem tra: ");
    scanf("%d", &num_to_check);

    if (isExist(num_to_check, arr_songuyen, n_songuyen)) {
        file_kgtk = fopen("kgtk.dat", "a");
        if (file_kgtk == NULL) {
            printf("Khong the mo hoac tao file kgtk.dat de ghi.");
            free(arr_songuyen);
            return 1;
        }

        // Ghi so can kiem tra vao file "kgtk.dat"
        fprintf(file_kgtk, "%d\n", num_to_check);

        fclose(file_kgtk);

        printf("Noi dung cua file kgtk.dat:\n");
        file_kgtk = fopen("kgtk.dat", "r");
        if (file_kgtk == NULL) {
            printf("Khong the mo file kgtk.dat de doc.");
            free(arr_songuyen);
            return 1;
        }

        while (fscanf(file_kgtk, "%d", &num) != EOF) {
            printf("%d\n", num);
        }

        // Dong file "kgtk.dat"
        fclose(file_kgtk);

    } else {
        printf("So %d khong ton tai trong file songuyen.dat.\n", num_to_check);
    }

    // Giai phong bo nho da cap phat cho mang
    free(arr_songuyen);

    return 0;
}

