#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=1;i<n;i++)
    {
        if(n/i==0)
            printf("No");
        else
            printf("Yes");
    }
}