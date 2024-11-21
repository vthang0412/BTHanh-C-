#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100000   // Số ký tự tối đa cho input
#define MAX_NUMBERS 10000  // Số lượng số tối đa

// Struct lưu trữ số và số lần xuất hiện
typedef struct {
    char number[10];
    int count;
} NonDecreasing;

// Hàm kiểm tra số không giảm
int isNonDecreasing(const char *num) {
    for (int i = 0; num[i + 1] != '\0'; i++) {
        if (num[i] > num[i + 1]) return 0;
    }
    return 1;
}

// Hàm so sánh để sắp xếp theo số lần xuất hiện giảm dần
int compare(const void *a, const void *b) {
    NonDecreasing *x = (NonDecreasing *)a;
    NonDecreasing *y = (NonDecreasing *)b;
    if (x->count != y->count) {
        return y->count - x->count; // Số lần xuất hiện giảm dần
    }
    return strcmp(x->number, y->number); // Sắp xếp số tăng dần nếu số lần bằng nhau
}

// Hàm loại bỏ ký tự không mong muốn (ví dụ: \n hoặc khoảng trắng)
void cleanInput(char *str) {
    size_t len = strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r' || str[len - 1] == ' ')) {
        str[len - 1] = '\0';
        len--;
    }
}

int main() {
    char input[MAX_INPUT];             // Lưu toàn bộ input
    NonDecreasing results[MAX_NUMBERS]; // Mảng lưu các số không giảm
    int resultCount = 0;               // Số lượng số không giảm trong mảng

    // Đọc toàn bộ input
    printf("Nhập các số: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        fprintf(stderr, "Lỗi khi đọc input.\n");
        return 1;
    }

    // Tokenize input bằng khoảng trắng hoặc xuống dòng
    char *token = strtok(input, " \n");
    while (token != NULL) {
        // Loại bỏ ký tự không mong muốn trong token
        cleanInput(token);

        // Kiểm tra nếu là số không giảm
        if (isNonDecreasing(token)) {
            // Kiểm tra nếu số đã tồn tại trong danh sách
            int found = 0;
            for (int i = 0; i < resultCount; i++) {
                if (strcmp(results[i].number, token) == 0) {
                    results[i].count++;
                    found = 1;
                    break;
                }
            }
            // Nếu không tồn tại, thêm vào danh sách
            if (!found) {
                if (resultCount >= MAX_NUMBERS) {
                    fprintf(stderr, "Quá nhiều số không giảm.\n");
                    return 1;
                }
                strcpy(results[resultCount].number, token);
                results[resultCount].count = 1;
                resultCount++;
            }
        }
        // Lấy token tiếp theo
        token = strtok(NULL, " \n");
    }

    // Sắp xếp danh sách
    qsort(results, resultCount, sizeof(NonDecreasing), compare);

    // In kết quả
    for (int i = 0; i < resultCount; i++) {
        printf("%s %d\n", results[i].number, results[i].count);
    }

    return 0;
}
