#include <stdio.h>
#define MAX_SIZE 100

void inputMatrix(int matrix[MAX_SIZE][MAX_SIZE], int *rows, int *cols) {
    printf("Nhap so dong: ");
    scanf("%d", rows);
    printf("Nhap so cot: ");
    scanf("%d", cols);

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void displayOddAndSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int sum = 0;
    printf("Cac phan tu la: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] % 2 != 0) {
                printf("%d ", matrix[i][j]);
                sum += matrix[i][j];
            }
        }
    }
    printf("\nTong cac phan tu la: %d\n", sum);
}

void displayBoundaryAndProduct(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int product = 1;
    printf("Cac phan tu tren duong bien: ");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                printf("%d ", matrix[i][j]);
                product *= matrix[i][j];
            }
        }
    }
    printf("\nTich cac phan tu tren duong bien: %d\n", product);
}

void displayMainDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Cac phan tu tren duong cheo chinh: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");
}

void displaySecondaryDiagonal(int matrix[MAX_SIZE][MAX_SIZE], int size) {
    printf("Cac phan tu tren duong cheo phu: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", matrix[i][size - i - 1]);
    }
    printf("\n");
}

void displayRowWithMaxSum(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    int maxSum = 0, maxRow = 0;
    for (int i = 0; i < rows; i++) {
        int sum = 0;
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxRow = i;
        }
    }

    printf("Dong co tong lon nhat (%d): ", maxSum);
    for (int j = 0; j < cols; j++) {
        printf("%d ", matrix[maxRow][j]);
    }
    printf("\n");
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows = 0, cols = 0, choice;

    do {
        printf("\nMENU\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh ting\n");
        printf("4. In cac phan tu tren duong bien va tinh tich\n");
        printf("5. In cac phan tu tren duong cheo chinh\n");
        printf("6. In cac phan tu tren duong cheo phu\n");
        printf("7. In dong co tong gia tri lon nhat\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputMatrix(matrix, &rows, &cols);
                break;
            case 2:
                displayMatrix(matrix, rows, cols);
                break;
            case 3:
                displayOddAndSum(matrix, rows, cols);
                break;
            case 4:
                displayBoundaryAndProduct(matrix, rows, cols);
                break;
            case 5:
                if (rows == cols)
                    displayMainDiagonal(matrix, rows);
                else
                    printf("Khong phai ma tran vuong, khong co duong cheo chinh.\n");
                break;
            case 6:
                if (rows == cols)
                    displaySecondaryDiagonal(matrix, rows);
                else
                    printf("Khong phai ma tran vuong, khong co duong cheo phu.\n");
                break;
            case 7:
                displayRowWithMaxSum(matrix, rows, cols);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Hay thu lai.\n");
        }
    } while (choice != 8);

    return 0;
}

