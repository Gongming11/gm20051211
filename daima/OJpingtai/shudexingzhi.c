/*一些数字可能拥有以下的性质：

性质 1：是偶数；
性质 2：大于 4 且不大于 12。
小 A 喜欢这两个性质同时成立的数字；
Uim 喜欢这至少符合其中一种性质的数字；
八尾勇喜欢刚好有符合其中一个性质的数字；
正妹喜欢不符合这两个性质的数字。

输出这 4 个人是否喜欢这个数字，如果喜欢则输出 1，否则输出 0，用空格分隔。
*/
#include<stdio.h>
void Student1(int n)
{
    if (n%2==0&&n>4&&n<=12)
    {
        printf("1 ");
    }else
    {
        printf("0 ");
    }
}
void Student2(int n)
{
    if (n%2==0||(n>4&&n<=12))
    {
        printf("1 ");
    }else
    {
        printf("0 ");
    }
}
void Student3(int n)
{
    if ((n%2==0&&(n<=4||n>12))||(n%2!=0)&&(n>4&&n<=12))
    {
        printf("1 ");
    }else
    {
        printf("0 ");
    }
}
void Student4(int n)
{
    if (n%2!=0&&(n<=4||n>12))
    {
        printf("1 ");
    }else
    {
        printf("0 ");
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    Student1(n);
    Student2(n);
    Student3(n);
    Student4(n);
    return 0;
}