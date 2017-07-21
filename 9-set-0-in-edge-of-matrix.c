#include <stdio.h>
#include <malloc.h>

void printMatrix(int **a,int row,int col)
{
	int i,j;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
			printf("%d ", *(*(a+i)+j));
		printf("\n");
	}

}


int main(int argc, char const *argv[])
{
	int row,col,**a,i,j,k=0;
	printf("Enter the no. of Rows\n");
	scanf("%d",&row);
	printf("Enter the no. of Columns\n");
	scanf("%d",&col);
	a=(int**)malloc(row*sizeof(int*));
	for(i=0;i<row;i++)
	{
		*(a+i)=(int*)malloc(col*sizeof(int));
		for(j=0;j<col;j++)
			*(*(a+i)+j)=k++;
	}

	printf("Given Matrix\n");
	printMatrix(a,row,col);
	
	for(i=0;i<row;i++)
	{
		**(a+i)=0;
		*(*(a+i)+(col-1))=0;
	}

	for(i=1;i<col-1;i++)
	{
		*(*a+i)=0;
		*(*(a+row-1)+i)=0;
	}

	printf("Result Matrix\n");
	printMatrix(a,row,col);

	return 0;
}