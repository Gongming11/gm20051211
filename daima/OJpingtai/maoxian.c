#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    long long arr[n];
    long long arr1[n];
    long long min=0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&arr[i]);
        if (i==0)
        {
            arr1[i]=arr[i];
        }else
        {
            arr1[i]=arr[i]+arr1[i-1];
        }
    }
    long long a=0;
    for (int i = 1; i < n; i++)
    {
        a=(1+arr1[i])*(arr1[i])/2+(1+arr1[n-1]-arr1[i])*(arr1[n-1]-arr1[i])/2;
        if (min==0)
        {
            min=a;
        }else if (min>a)
        {
            min=a;
        }
    }
    printf("%lld",min);
    return 0;
}