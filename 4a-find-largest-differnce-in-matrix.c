#include <stdio.h>
#include <malloc.h>
int main(int argc, char const *argv[])
{
	int i,n,*a,max,min;
	printf("Enter the N Value:\n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("Enter the array Values(N Values)\n");
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	max=min=*a;
	for(i=1;i<n;i++)
	{
		if(*(a+i)>max)
			max=*(a+i);
		if(*(a+i)<min)
			min=*(a+i);
	}
	if(max>0)
		printf("The Largest Difference is %d\n",max-min);
	else
		printf("Invalid Input\n");
	return 0;
}