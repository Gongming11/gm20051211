#include<stdio.h>
int main()
{
    int n,m;
    int a,i,j,k;
    scanf("%d",&n);
    long sum[n];
    for ( i = 0; i < n; i++)
    {
        sum[i]=0;
        scanf("%d",&m);
        for ( j = 0; j < m; j++)
        {
            scanf("%d",&a);
            sum[i]=sum[i]+a;
        }
    }
    for ( k = 0; k < n; k++)
    {
        printf("%ld\n",sum[k]);
    }
    return 0;
}

