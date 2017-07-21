#include <stdio.h>
#include <malloc.h>

int stringLength(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++);
	return i;
}


char* removeSpace(char *a)
{
	int i,len=stringLength(a);
	if(a[0]==' ')
	{
		for(i=0;i<=len;i++)
			a[i]=a[i+1];
	}
	if(a[len-2]==' ')
		a[len-2]='\0';
	else
		a[len-1]='\0';
	return a;
}

int main(int argc, char const *argv[])
{
	char *a;
	a=(char*)malloc(100*sizeof(char));
	printf("Enter the String\n");
	scanf("%[^\n]s",a);
	a=removeSpace(a);
	printf("Trimmed Sentence is \n%s\n",a);
	return 0;
}