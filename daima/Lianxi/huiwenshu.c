//判断一个数是否为回文数
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num = 0;
    int m = n;
    while (n != 0)
    {
        num = num*10+n%10;//将对应的位数上的数互换-
        n=n/10;
    }
    if (m==num)//判断互换的数和原来的数是否相等
    {
        printf("Yes");
    }
    else
        printf("No");
    return 0;
}