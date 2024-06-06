//实现非递归版本的一维整数型数组的选择排序算法
#include<stdio.h>
int main()
{
    int i, j;
    int a[6];
    int min, m;
    for ( i=0; i<6; i++)
    {
        scanf("%d",&a[i]);//依次输入六个数
    }
    for ( i=0; i<5; i++)
    {
        min=a[i];//依次假设当前数为最小值
        m=i;//记录当前位置
        for ( j=i+1; j<6; j++)
        {
            if (a[j]<min)
            {
                min=a[j];
                m=j;//重新确定最小值
            }
        }
        a[m]=a[i];
        a[i]=min;//将假设的最小数与其后面的数进行比较，如果有更小的则进行交换位置
    }
    for ( i=0; i<6; i++)
    {
        printf("%d\t",a[i]);//输出排序后的数
    }
    return 0;
}

//实现非递归版本的一维整数型数组的冒泡排序算法
#include<stdio.h>
int main()
{
    int i, j;
    int a[6];
    int min;
    for ( i=0; i<6; i++)
    {
        scanf("%d",&a[i]);//依次输入数据
    }
    for ( i=0; i<6; i++)
    {
        for (j=5; j>=i; j--)
        {
            if (a[j]<a[j-1])
            {
                min=a[j-1];
                a[j-1]=a[j];
                a[j]=min;
            }//如同冒泡一般，第一次先将最小的数移到第一位，第二次将剩余数中最小的移到第二位，依次进行
        }
    }
    for ( i=0; i<6; i++)
    {
        printf("%d\t",a[i]);//最后输出排序后的数
    }
    return 0;
}