#include <stdio.h> 
#include <stdlib.h> 

int main()
{
	int n;
	do
	{
		printf("�п�J�@�Ӥj�󵥩�1�����:");
		scanf("%d", &n);
	}
	while( n<1 || n%2 != 0 );
	
	int sum = 0;
	for (int i=2;i<=n;i+=2)
	{
		sum += i; 
	}
	
	printf("2+4+...+%d ���`�M�O:%d\n", n, sum);
	
	system("pause");
	return 0;
	
}
