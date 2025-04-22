#include <stdio.h>
#include <stdlib.h>

// 函式原型
double f(double x);

// 主程式
int main(void)
{
    printf("f(-3.2) = %.2f\n", f(-3.2));
    printf("f(-2.1) = %.2f\n", f(-2.1));
    printf("f(0) = %.2f\n", f(0));
    printf("f(2.1) = %.2f\n", f(2.1));

    system("pause");
    return 0;
}

// 函式定義：f(x) = 3x^3 + 2x - 1
double f(double x)
{
    return 3 * x * x * x + 2 * x - 1;
}


