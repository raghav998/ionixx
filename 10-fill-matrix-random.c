#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isDistinct(int **a,int row,int col,int no)
{
	int i,j;
	for(i=0;i<row;i++)
		for(j=0;j<col;j++)
			if(*(*(a+i)+j)==no)
				return 0;
	return 1;
}

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


int calcRandom(int **a,int max,int min,int row,int col)
{
	int tmp;
	srand((unsigned)time(NULL));
	do
	{
		tmp=min+(rand()%(max+1-min));
	}while(!isDistinct(a,row,col,tmp));
	return tmp;
}

int** fillMatrixRandom(int **a,int row,int col,int max,int min)
{
	int i,j,tmp;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			*(*(a+i)+j)=calcRandom(a,max,min,row,col);
		}
	}
	return a;
}

int main(int argc, char const *argv[])
{
	int **a,row,col,i,j,max,min;
	printf("Enter the no. of rows\n");
	scanf("%d",&row);
	printf("Enter the no. of columns\n");
	scanf("%d",&col);
	printf("Enter the Min Value\n");
	scanf("%d",&min);
	printf("Enter the Max Value\n");
	scanf("%d",&max);
	if((max-min)>(row*col))
	{
		printf("Invalid Input\n");
		return 0;
	}
	a=(int**)malloc(row*sizeof(int*));
	for(i=0;i<row;i++)
		*(a+i)=(int*)calloc(col,sizeof(int));

	a=fillMatrixRandom(a,row,col,max,min);

	printf("Result Matrix is \n");
	printMatrix(a,row,col);

	return 0;
}