//输入一个比较大的正数n，输出[1,n]之间的素数
#include<stdio.h>
int main()
{
    int n, a, b;
    printf("Please enter a positive number: ");
    scanf("%d",&n);//输入这个正数
    for (a=2; a<=n; a++)//因为是[],包括输入的正数本身，所以是a<=n
    {
        for (b=2;b<a; b++)
        {
           if (a%b==0)
           break;
        }
        if (b==a)//如果是素数，则最后b==a,不满足b<a跳出for循环,并满足if选择语句的条件
        printf("%d ",a);
    }
    return 0;
}