#include<stdio.h>
#include<malloc.h>
//initiater
char** initiater(char **a,int ***ans)
{
    a=(char**)malloc(10*sizeof(char*));
    for(int i=0;i<10;i++)
        *(a+i)=(char*)malloc(10*sizeof(char));
    *ans=(int**)malloc(10*sizeof(int*));
    for(int i=0;i<10;i++)
        *(*ans+i)=(int*)calloc(10,sizeof(int));
    a[0]="WWWMILAZSD";
    a[1]="DYTRYGWSOH";
    a[2]="PRWAJBQOOO";
    a[3]="BZAFRMEBKE";
    a[4]="RVGZKAFTYI";
    a[5]="MNOOILUOBO";
    a[6]="XODQNLVWTW";
    a[7]="LIOGORFOLC";
    a[8]="HJLSVZRRXD";
    a[9]="VJKOEWUGEF";
    return a;
}

int** ansResetter(int **a)
{
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            a[i][j]=0;
    return a;
}

int stringLength(char a[])
{
    int i;
    for(i=0;a[i]!='\0';i++);
    return i;
}

int stringCompare(char a[],char b[])
{
    for(int i=0;(b[i]!='\0');i++)
        if(a[i]!=b[i])
            return 0;
    return 1;
}

int** search(char **a,char in[],int **ans)
{
    int len=stringLength(in),k,j;
    int edge=10-len;
    char tmp[len];
    tmp[len]='\0';
    ans=ansResetter(ans);
   // printf("\nlen %d edge %d len of tmp %d\n",len,edge,stringLength(tmp));
    for(int i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            if(a[i][j]==in[0])
            {
                //right
                if(j<=edge)
                {
                    for(k=0;k<len;k++)
                        tmp[k]=a[i][j+k];
                    
                    
                    if(stringCompare(tmp,in))
                    {
                        for(k=0;k<len;k++)
                            ans[i][j+k]=1;
                    }
                }
                
                //left
                if(j>=len-1)
                {
                    //get string
                    for(k=0;k<len;k++)
                        tmp[k]=a[i][j-k];
                    //compare
                    if(stringCompare(tmp,in))
                        for(k=0;k<len;k++)
                            ans[i][j-k]=1;
                }
                
                
                //down
                if(i<=edge)
                {
                    //get string
                    for(k=0;k<len;k++)
                        tmp[k]=a[i+k][j];
                    if(stringCompare(tmp,in))
                        for(k=0;k<len;k++)
                            ans[i+k][j]=1;
                }
                
                //up
                if(i>=len-1)
                {
                    //get string
                    for(k=0;k<len;k++)
                        tmp[k]=a[i-k][j];
                    //compare
                    if(stringCompare(tmp,in))
                        for(k=0;k<len;k++)
                            ans[i-k][j]=1;
                }
            }
        }
    }
    return ans;
}

void printResult(char **a,int **ans)
{
    printf("Result is \n");
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(ans[i][j]==0)
                printf("- ");
            else
                printf("%c ",a[i][j]);
                
        }
        printf("\n");
    }
}


void printMatrix(char **a)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            printf("%c ",a[i][j]);
        printf("\n");
    }
}

void printMenu()
{
    printf("1.Search Word\n");
    printf("2.Exit\n");
}

//main
int main()
{
    char **a,inp[10];
    int **ans;
    a=initiater(a,&ans);
    int ch=0;
    do
    {
        printMatrix(a);
        printMenu();
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter the word to be serached\n");
            scanf("%s",inp);
            ans=search(a,inp,ans);
            printResult(a,ans);
        }
    }while(ch!=2);
    return 0;
}