#include<stdio.h>
int main()
{
    int a,b;
    int i=0;
    int arr[1000]={0};
    while (scanf("%d%d",&a,&b)!=EOF)
    {
        arr[i]=a+b;
        i++;
    }
    for ( int j = 0; j < i; j++)
    {
        printf("%d\n",arr[j]);
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int a,b;
    while (~scanf("%d%d",&a,&b))
    {
        printf("%d\n",a+b);
    }
    return 0;
}