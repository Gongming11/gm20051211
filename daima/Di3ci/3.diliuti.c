#include<stdio.h>
int two_dim_array_access(int *x,int i,int j,int m,int n,int C)
{
    int e, f;
    e=m-i;//行的偏移量
    f=n-j;//列的偏移量
    int pianyiliang=e*C+f;//访问的元素的总偏移量 
    int *Aaddres=x+pianyiliang;
    return *Aaddres;//返回地址
}
int main()
{
    int s, k;
    scanf("%d%d",&s,&k);//输入数组的大小
    int A[s][k];
    for (int i = 0; i < s; i++)
    {
        for (int j = 0; j < k; j++)
        {
            scanf("%d",&A[i][j]);//输入数组中的数据
        }
    }
    int q, p;
    int g, h;
    int a, b;
    int shuchu1, shuchu2;
    scanf("%d%d",&q,&p);
    scanf("%d%d",&g,&h);
    scanf("%d%d",&a,&b);
    shuchu1=two_dim_array_access(&A[q][p],q,p,a,b,k);
    shuchu2=two_dim_array_access(&A[g][h],g,h,a,b,k);//调用函数并令探索的元素相同，即下标相同
    printf("%d\n",shuchu1);
    printf("%d\n",shuchu2);//输出返回值的值
    if (shuchu1==shuchu2)
    {
        printf("Right");//如果返回值相同则说明函数正确
    }
    return 0;
}