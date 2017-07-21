#include <stdio.h>
#include <malloc.h>

int stringLength(char *a)
{
	int i;
	for(i=0;*(a+i)!='\0';i++);
	return i;
}

int main(int argc, char const *argv[])
{
	char *a,*b;
	int i,j,lena,lenb,flag=0;
	a=(char*)malloc(50*sizeof(char));
	b=(char*)malloc(50*sizeof(char));
	printf("Enter the String 1\n");
	scanf("%s",a);
	printf("Enter the String 2\n");
	scanf("%s",b);
	lena=stringLength(a);
	lenb=stringLength(b);
	for(i=0;i<lena;i++)
	{
		for(j=0;j<lenb;j++)
		{
			if(*(a+i)==*(b+j))
			{
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
	if(flag)
		printf("Character found in both String is %c\n",*(a+i));
	else
		printf("No Same Character found\n");
	return 0;
}