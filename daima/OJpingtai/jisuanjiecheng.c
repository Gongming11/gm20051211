//计算一个数的阶乘
#include<stdio.h>
int main()
{
    int n;
    int m=1;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        m*=i;
    }
    printf("%d",m);
    return 0;
}