#include <stdio.h>
#include <stdlib.h>
void transform2(float *); //�禡�쫬�ŧi

int main(void)
{
float t;

printf("��J���ū�:");
scanf("%f", &t);
printf("���%5.1f ��=", t);
transform2(t);
printf("�ؤ�%5.1f ��\n", t);
system("pause");
return 0;
}
//�w�q�禡
/*****************************/
void transform2(float *f)
{
*f= *f * 9 / 5 + 32;
}
/*****************************/
