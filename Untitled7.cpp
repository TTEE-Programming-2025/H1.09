#include <stdio.h>
#include <stdlib.h>
void transform2(float *); //函式原型宣告

int main(void)
{
float t;

printf("輸入攝氏溫度:");
scanf("%f", &t);
printf("攝氏%5.1f 度=", t);
transform2(t);
printf("華氏%5.1f 度\n", t);
system("pause");
return 0;
}
//定義函式
/*****************************/
void transform2(float *f)
{
*f= *f * 9 / 5 + 32;
}
/*****************************/
