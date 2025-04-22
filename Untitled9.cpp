#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 計算 my_fun(n) = 1/1! + 1/2! + ... + 1/n!
double my_fun(int n) {
    if (n <= 0) return -1;

    double sum = 0.0, factorial = 1.0;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
        sum += 1.0 / factorial;
    }
    return sum;
}

int main() {
    int n;

    printf("=== 題目 (a)：輸入三個正整數，每次計算並輸出 my_fun(n) ===\n");

    for (int i = 1; i <= 3; i++) {
        do {
            printf("請輸入第 %d 個正整數 n：", i);
            scanf("%d", &n);
            if (n <= 0) {
                printf("錯誤：n 必須大於 0，請重新輸入。\n");
            }
        } while (n <= 0);

        printf("my_fun(%d) = %.8f\n", n, my_fun(n));
    }

    // 題目 (b)
    printf("\n=== 題目 (b)：尋找最小 n，使 my_fun(n) 與 my_fun(n-1) 的差 < 0.00001 ===\n");

    int k = 2;
    double prev = my_fun(1);
    double curr = my_fun(2);

    while (fabs(curr - prev) >= 0.00001) {
        k++;
        prev = curr;
        curr = my_fun(k);
    }

    printf("最小的 n，使 my_fun(n) - my_fun(n-1) < 0.00001 為：%d\n", k);

    system("pause");
    return 0;
}

