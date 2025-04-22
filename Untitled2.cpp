#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int n;
	do
	{
		printf("請輸入一個大於等於1的整數:");
		scanf("%d", &n);
	}
	while( n<1 || n%2 != 0 );
	
	int sum = 0;
	for (int i=2;i<=n;i+=2)
	{
		sum += i; 
	}
	
	printf("2+4+...+%d 的總和是:%d\n", n, sum);
	
	system("pause");
	return 0;
	
}
