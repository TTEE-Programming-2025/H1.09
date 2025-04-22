#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �p�� my_fun(n) = 1/1! + 1/2! + ... + 1/n!
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

    printf("=== �D�� (a)�G��J�T�ӥ���ơA�C���p��ÿ�X my_fun(n) ===\n");

    for (int i = 1; i <= 3; i++) {
        do {
            printf("�п�J�� %d �ӥ���� n�G", i);
            scanf("%d", &n);
            if (n <= 0) {
                printf("���~�Gn �����j�� 0�A�Э��s��J�C\n");
            }
        } while (n <= 0);

        printf("my_fun(%d) = %.8f\n", n, my_fun(n));
    }

    // �D�� (b)
    printf("\n=== �D�� (b)�G�M��̤p n�A�� my_fun(n) �P my_fun(n-1) ���t < 0.00001 ===\n");

    int k = 2;
    double prev = my_fun(1);
    double curr = my_fun(2);

    while (fabs(curr - prev) >= 0.00001) {
        k++;
        prev = curr;
        curr = my_fun(k);
    }

    printf("�̤p�� n�A�� my_fun(n) - my_fun(n-1) < 0.00001 ���G%d\n", k);

    system("pause");
    return 0;
}

