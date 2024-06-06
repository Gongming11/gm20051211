#include<stdio.h>
int main()
{
    int n;
    int i,j;
    int a,b;
    int sum[100]={0};
    scanf("%d",&n);
    for ( i = 0; i < n; i++)
    {
        scanf("%d%d",&a,&b);
        sum[i]=a+b;
    }
    for ( j = 0; j < n; j++)
    {
        printf("%d\n",sum[j]);
    }
    return 0;
}