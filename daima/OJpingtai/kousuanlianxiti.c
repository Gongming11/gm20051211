/*第一行为数值 i
接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。
若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，
b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。
若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

输出 2*i 行。对于每个输入的算式，输出完整的运算式及结果，
第二行输出该运算式的总长度
*/  
#include<stdio.h>//第一种做法
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int a[50][3];
    int tmp=0;
    char ch[20];
    for (int i = 0; i < n; i++)
    {
        gets(ch);
        if (ch[0]<'a'||ch[0]>'c')
        {
            a[i][0]=tmp;
            sscanf(ch,"%d %d",&a[i][1],&a[i][2]);
        }else
        {
            a[i][0]=ch[0];
            tmp=ch[0];
            ch[0] = 'a';
            sscanf(ch,"a %d %d",&a[i][1],&a[i][2]);
        }
    }
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0]=='a')
        {
            k=printf("%d+%d=%d\n",a[i][1],a[i][2],a[i][1]+a[i][2]);
            printf("%d\n",k-1);
        }
        if (a[i][0]=='b')
        {
            k=printf("%d-%d=%d\n",a[i][1],a[i][2],a[i][1]-a[i][2]);
            printf("%d\n",k-1);
        }
        if (a[i][0]=='c')
        {
            k=printf("%d*%d=%d\n",a[i][1],a[i][2],a[i][1]*a[i][2]);
            printf("%d\n",k-1);
        }
    }
    return 0;
}


#include<stdio.h>//第二种做法
#include<stdlib.h>
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int a[50][3];
    int tmp=0;
    char ch[5];
    for (int i = 0; i < n; i++)
    {
        scanf("%s",ch);
        if (ch[0]<'a'||ch[0]>'c')
        {
            a[i][0]=tmp;
            a[i][1]=atoi(ch);
            scanf("%d",&a[i][2]);
        }else
        {
            a[i][0]=ch[0];
            tmp=ch[0];
            scanf("%d %d",&a[i][1],&a[i][2]);
        }
    }
    int k=0;
    for (int i = 0; i < n; i++)
    {
        if (a[i][0]=='a')
        {
            k=printf("%d+%d=%d\n",a[i][1],a[i][2],a[i][1]+a[i][2]);
            printf("%d\n",k-1);
        }
        if (a[i][0]=='b')
        {
            k=printf("%d-%d=%d\n",a[i][1],a[i][2],a[i][1]-a[i][2]);
            printf("%d\n",k-1);
        }
        if (a[i][0]=='c')
        {
            k=printf("%d*%d=%d\n",a[i][1],a[i][2],a[i][1]*a[i][2]);
            printf("%d\n",k-1);
        }
    }
    return 0;
}