#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int n,i,j,*a,tmp;
	printf("Enter the N Value\n");
	scanf("%d",&n);
	a=(int*)calloc(10,sizeof(int));
	srand((unsigned)time(NULL));
	for(i=0;i<n;i++)
	{
		tmp=rand()%10;
		a[tmp]++;
	}
	for(i=0;i<10;i++)
	{
		printf("%d(%d):",i,*(a+i));
		for(j=0;j<*(a+i);j++)
			printf("*");
		printf("\n");
	}
	return 0;
}