//编写一个程序探索二维数组是按行存放，还是按列存放
#include<stdio.h>
int main()
{
    int arrA[2][3]={{1,2,3},{4,5,6}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%p\n",&arrA[i][j]);
        }
    }
    return 0;
}
/*按照行依次输入每个数组中元素的地址，如果是一次的则说明是按行，
如果是跳转的则说明是案列的*/
