#include <stdio.h>
#include <stdlib.h>
int sum(int, int, int); //�禡�쫬�ŧi
int main()
{
sum(1, 100, 1); //�I�s�禡
sum(1, 101, 2); //�I�s�禡
sum(4, 100, 3); //�I�s�禡
system("pause");
return 0;
} 
//�禡�w�q
/********************************/
void sum(int m, int n, int add)
{
int i, total=0;

for (i = m; i <= n; i = i + add)
total = total +i;
printf("%d+%d+%d+�K+",m, m+add, m+2*add);
printf("%d= %d\n", n, total);
}
