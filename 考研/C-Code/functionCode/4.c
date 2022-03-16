#include <stdio.h>

void zhuan()
{
    
}

int main()
{
    int a[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("Please Enter a[%d][%d]:",i,j);
            scanf("%d", &a[i][j]);
            printf("\n");
        }
    }

    zhuan();

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("a[%d][%d]:%d\n",i,j,a[i][j]);
        }
    }    
}