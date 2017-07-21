#include <stdio.h>
#include <malloc.h>

int stringLength(char *a)
{
	int i;
	for(i=0;*(a+i)!='\0';i++);
	return i;
}

int stringCompare(char *a,char *b,int pos)
{
	int i;
	for(i=0;(*(b+i)!='\0');i++)
		if(*(a+i+pos)!=*(b+i))
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	char *a,*b;
	int i,lena,lenb,flag=0;
	a=(char*)malloc(50*sizeof(char));
	b=(char*)malloc(50*sizeof(char));
	printf("Enter the String\n");
	scanf("%s",a);
	printf("Enter the SubString\n");
	scanf("%s",b);
	lena=stringLength(a);
	lenb=stringLength(b);
	for(i=0;i<lena;i++)
	{
		if(stringCompare(a,b,i))
		{
			flag=1;
			break;
		}
	}
	if(flag)
		printf("String Present at Index %d\n",i);
	else
		printf("String Not Found\n");
	return 0;
}