#include <stdio.h>
int main() {
    int arr[100];
    int n;
    int value, index;

    printf("Nhap so luong phan tu ban muon nhap (toi da 100): ");
    scanf("%d", &n);

    printf("Nhap %d phan tu:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi chen: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen (tu 1 den %d): ", n + 1);
    scanf("%d", &index);

    if (index < 1 || index > n + 1) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    for (int i = n; i >= index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index - 1] = value;
    n++;

    printf("Mang sau khi chen: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

