#include <stdio.h>

// Hàm hoán đổi hai số
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Nhập số lượng phần tử: ");
    scanf("%d", &n); // Nhập số lượng phần tử

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Nhập các phần tử của mảng
    }

    // Sắp xếp đổi chỗ trực tiếp (Selection Sort)
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i; // Vị trí phần tử nhỏ nhất
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Cập nhật vị trí phần tử nhỏ nhất
            }
        }
        // Đổi chỗ phần tử nhỏ nhất với phần tử ở vị trí i
        swap(&arr[i], &arr[minIndex]);

        // In ra trạng thái mảng sau mỗi bước
        printf("Buoc %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }

    return 0;
}
