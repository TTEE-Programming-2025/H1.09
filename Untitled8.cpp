#include <stdio.h>
#include <stdlib.h>

// �禡�쫬
double f(double x);

// �D�{��
int main(void)
{
    printf("f(-3.2) = %.2f\n", f(-3.2));
    printf("f(-2.1) = %.2f\n", f(-2.1));
    printf("f(0) = %.2f\n", f(0));
    printf("f(2.1) = %.2f\n", f(2.1));

    system("pause");
    return 0;
}

// �禡�w�q�Gf(x) = 3x^3 + 2x - 1
double f(double x)
{
    return 3 * x * x * x + 2 * x - 1;
}


