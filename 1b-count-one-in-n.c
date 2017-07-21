#include <stdio.h>

int countOne(int n)
{
	if(n==0)
		return 0;

	return n%2+countOne(n/2);
}

int main(int argc, char const *argv[])
{
	int ino;
	printf("Enter the N Value\n");
	scanf("%d",&ino);
	if(ino<0)
		printf("Invalid Input\n");
	else
		printf("Number of 1 in %d is %d\n",ino,countOne(ino));
	return 0;
}