//编写可以实现矩阵的相乘的函数的函数体，并测试其正确性
#include<stdio.h>
void matrix_multi(double A[3][4],double B[4][5],double C[3][5])
{
    int m;
    for (int i = 0; i < 3; i++) 
    {   
        for (int j = 0; j < 5; j++) 
        {   
            C[i][j]=0;   
            for ( m = 0; m < 4; m++) 
            {   
                C[i][j] += A[i][m] * B[m][j];//根据矩阵的运算法则，计算乘积的和并赋值对应的C数组   
            }  
        }  
    }
}
int main()
{
    double A[3][4];
    double B[4][5];
    double C[3][5]={0};
    for (int  i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%lf",&A[i][j]);//double类型的输入要用%lf,输出则是%f和%lf均可
        }
    }
    for (int  i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            scanf("%lf",&B[i][j]);
        }
    }//对A数组和B数组分别赋值
    matrix_multi(A, B, C);//调用函数
    for (int i = 0; i < 3; i++) 
    {  
        for (int j = 0; j < 5; j++) 
        {  
            printf("%f ", C[i][j]);//打印C数组的值  
        }  
        printf("\n");//换行输出形成矩阵形式  
    }
    return 0;
}