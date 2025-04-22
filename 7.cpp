#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int n, i=1,fact=1;
	do
	{
		printf("�п�J n �� (n>0):");
		scanf("%d", &n);
	}
	while (n<=0);
	do
	   fact*=i++;
	while (i <= n);
	printf("%d!=%d\n",n,fact);
	
	return 0;   
}
