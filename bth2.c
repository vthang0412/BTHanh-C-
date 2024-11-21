#include <stdio.h>

// Hàm hoán đổi hai số
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp nổi bọt tăng dần
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n); // Nhập số phần tử của mảng

    int arr[n], even[n], odd[n];
    int evenCount = 0, oddCount = 0;

    // Nhập mảng
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        // Phân loại số chẵn và lẻ
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i]; // Số chẵn
        } else {
            odd[oddCount++] = arr[i];  // Số lẻ
        }
    }

    // Sắp xếp mảng chẵn và lẻ
    bubbleSort(even, evenCount);
    bubbleSort(odd, oddCount);

    // In kết quả
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }

    return 0;
}
