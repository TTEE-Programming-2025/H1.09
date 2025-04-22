#include <stdio.h>
#include <stdlib.h> 
int main()
{
	int n, i=1,fact=1;
	do
	{
		printf("½Ð¿é¤J n ­È (n>0):");
		scanf("%d", &n);
	}
	while (n<=0);
	do
	   fact*=i++;
	while (i <= n);
	printf("%d!=%d\n",n,fact);
	
	system("pause");
	return 0;   
}
