#include<stdio.h>
int main()
{
    int a,b,i;
    int n=0;
    int sum[100000]={0};
    for ( i = 0; i < 100000; i++)
    {
        scanf("%d%d",&a,&b);
        if (a==0&&b==0)
        {
            break;
        }
        sum[i]=a+b;
        n++;
    }
    for ( i = 0; i < n; i++)
    {
        printf("%d\n",sum[i]);
    }
    return 0;
}