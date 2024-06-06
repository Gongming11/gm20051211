#include<stdio.h>
int main()
{
    long sum=0;
    int a,n,i;
    while (scanf("%d",&n)!=EOF)
    {
        for ( i = 0; i < n; i++)
        {
            scanf("%d",&a);
            sum=sum+a;
        }
        printf("%ld\n",sum);
        sum=0;
    }
    return 0;
}