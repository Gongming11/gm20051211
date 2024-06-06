//给出一组数，统计其中的正负数的个数，并输出其中较大的统计数
#include<stdio.h>
int Max(int a, int b)
{
    if (a < b)
    {
        return b;
    }
    else 
        return a;
}
int main()
{
    int max, a, n;
    int numbers[50]={0};
    int posnums=0;
    int netnums=0;
    scanf("%d",&n);//输入该组数的个数
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a);//依次输入该组数
        numbers[i] = a;
    }
    for (int i = 0; i < n; i++)
    {
        if (numbers[i]>0)
        {
            posnums++;
        }
        else if (numbers[i]<0)
        {
            netnums++;
        }   
    }
    max=Max(posnums,netnums);
    printf("%d",max);
    return 0;
}