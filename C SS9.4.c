#include <stdio.h>
void nhapMang(int arr[100], int *n) {
    printf("Nhap so luong phan tu cua mang (toi da 100): ");
    scanf("%d", n);

    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void hienMang(int arr[], int n) {
    printf("Cac phan tu trong mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void themPhanTu(int arr[], int *n) {
    int value, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);
    printf("Nhsp vi tri muon chen (tu 1 den 100): ", *n + 1);
    scanf("%d", &position);

    if (position < 1 || position > *n + 1) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = *n; i >= position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position - 1] = value;
    (*n)++;
    printf("Ða them phan tu thanh cong!\n");
}

void suaPhanTu(int arr[], int n) {
    int position, newValue;
    printf("Nhap vi tri can sua (tu 1 den 100): ", n);
    scanf("%d", &position);

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    arr[position - 1] = newValue;
    printf("Ða sua phan tu thanh cong!\n");
}

void xoaPhanTu(int arr[], int *n) {
    int position;
    printf("Nhap vi tri can xoa (tu 1 den 100): ", *n);
    scanf("%d", &position);
    
    for (int i = position - 1; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Da xoa phan tu thanh cong!\n");
}

int main() {
    int arr[100];
    int n = 0;
    int chon;

    do {
        printf("\nMENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);

        switch (chon) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                hienMang(arr, n);
                break;
            case 3:
                themPhanTu(arr, &n);
                break;
            case 4:
                suaPhanTu(arr, n);
                break;
            case 5:
                xoaPhanTu(arr, &n);
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Hay thu lai.\n");
        }
    } while (chon != 6);

    return 0;
}

