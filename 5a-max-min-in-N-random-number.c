#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int i,n,max=0,min=9,tmp;
	printf("Enter the N Value\n");
	scanf("%d",&n);
	srand((unsigned)time(NULL));
	printf("Random Numbers are\n");
	for(i=0;i<n;i++)
	{
		tmp=rand()%10;
		if(tmp>max)
			max=tmp;
		if(tmp<min)
			min=tmp;
		printf("%d\n",tmp);
	}
	printf("Largest Number is %d\nSmallest Number is %d\n",max,min);
	return 0;
}