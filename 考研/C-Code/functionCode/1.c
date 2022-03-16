#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    
    if(n==2)
    {
        printf("Yes");
    }
    else
    {
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        {
            printf("No");
            break;
        }
        if(i==n-1)
        {
            printf("Yes");
        }
    }
    }
}