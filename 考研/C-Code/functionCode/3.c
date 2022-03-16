#include <stdio.h>

int calc()
{
    int sum=0;
    for(int i=3;i<=1100;i++)
    {
        for(int j=2;j<i;j++)
        {
            if(i%j==0)
                continue;
            if(j==i-1)
                sum++;
        }
    }
    return sum;
}

int main()
{

    printf("%d",calc());
}