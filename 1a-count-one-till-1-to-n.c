#include <stdio.h>
#include <stdlib.h>
int countOne(int n)
{
	int rem,count=0;
	while(n!=0)
	{
		rem=n%2;
		n/=2;
		if(rem)
			count++;
	}
	return 	count;
}

int main()
{
	int n,i,ans=0;
	printf("Enter the N Value:\n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Invalid Input\n");
		exit(1);
	}
	for(i=1;i<=n;i++)
	{
		ans+=countOne(i);
	}
	printf("Answer is %d\n",ans);
	return 0;
}