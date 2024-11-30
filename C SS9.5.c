#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void inputArray(int arr[], int *n) {
    printf("Nhap so luong phan tu (toi da 100): ");
    scanf("%d", n);
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < *n; i++) scanf("%d", &arr[i]);
}

void displayArray(int arr[], int n) {
    printf("Mang hien tai: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void displayEvenAndSum(int arr[], int n) {
    int sum = 0;
    printf("Cac so chan: ");
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so chan: %d\n", sum);
}

void findMinMax(int arr[], int n) {
    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }
    printf("Gia tri lon nhat: %d\n", max);
    printf("Gia tri nho nhat: %d\n", min);
}

void displayPrimesAndSum(int arr[], int n) {
    int sum = 0;
    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("%d ", arr[i]);
            sum += arr[i];
        }
    }
    printf("\nTong cac so nguyen to: %d\n", sum);
}

void countOccurrences(int arr[], int n) {
    int x, count = 0;
    printf("Nhap so can thong ke: ");
    scanf("%d", &x);
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) count++;
    }
    printf("So %d xuat hien %d lan trong mang.\n", x, count);
}

void addElement(int arr[], int *n) {
    int value, pos;
    printf("Nhap gia tri va vi tri can them (1-%d): ", *n + 1);
    scanf("%d%d", &value, &pos);
    
    for (int i = (*n)++; i >= pos; i--) arr[i] = arr[i - 1];
    arr[pos - 1] = value;
    printf("Da them phan tu thanh cong.\n");
}

int main() {
    int arr[100], n = 0, chon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat\n");
        printf("5. In ra cac so nguyen to va tinh tong\n");
        printf("6. Nhap mot so va thong ke so lan xuat hien\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1: inputArray(arr, &n); break;
            case 2: displayArray(arr, n); break;
            case 3: displayEvenAndSum(arr, n); break;
            case 4: findMinMax(arr, n); break;
            case 5: displayPrimesAndSum(arr, n); break;
            case 6: countOccurrences(arr, n); break;
            case 7: addElement(arr, &n); break;
            case 8: printf("Thoat chuong trinh.\n"); break;
            default: printf("Hay thu lai.\n");
        }
    } while (chon != 8);
    return 0;
}

