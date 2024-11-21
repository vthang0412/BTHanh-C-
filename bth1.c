#include <stdio.h>
#include <string.h>

#define MAX 30001 // Giá trị tối đa của số trong dãy

int main() {
    int n;
    scanf("%d", &n);

    int arr[n], count[MAX] = {0}; // Mảng lưu dãy số và mảng đếm tần suất
    int maxFreq = 0;              // Tần suất lớn nhất

    // Nhập mảng và đếm tần suất
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[arr[i]]++;
        if (count[arr[i]] > maxFreq) {
            maxFreq = count[arr[i]]; // Cập nhật tần suất lớn nhất
        }
    }

    // In ra các số có tần suất bằng maxFreq theo thứ tự xuất hiện ban đầu
    int printed[MAX] = {0}; // Đánh dấu các số đã in
    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == maxFreq && !printed[arr[i]]) {
            printf("%d ", arr[i]);
            printed[arr[i]] = 1; // Đánh dấu là đã in
        }
    }

    return 0;
}
