#include <stdio.h>
int main() {
    int arr[100];
    int n, position, newValue;

    printf("Nhap so luong phan tu cua mang : ");
    scanf("%d", &n);


    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Mang ban dau: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Nhap vi tri can sua (tu 1 den %d): ", n);
    scanf("%d", &position);

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    arr[position - 1] = newValue;

    printf("Mang sau khi sua: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

