#include <stdio.h>
#include <malloc.h>

int main(int argc, char const *argv[])
{
	int i,j,n,*a,diff,p,q;
	printf("Enter the N Value\n");
	scanf("%d",&n);
	a=(int*)calloc(n,sizeof(int));
	printf("Enter the Array Values\n");
	for(i=0;i<n;i++)
		scanf("%d",(a+i));
	diff=*(a+n-1)-*a;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
			if(diff<(*(a+j)-*(a+i)))
			{
				diff=*(a+j)-*(a+i);
				p=i;
				q=j;
			}

	printf("Largest Difference is %d\nP = %d\nQ = %d\n",diff,p,q);
	return 0;
}