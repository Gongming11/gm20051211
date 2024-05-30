/*n(n<=100)名同学去参加歌唱比赛并接受 m(m≤20)名评委的评分，评分范围是0到10分。
这名同学的得分就是这些评委给分中去掉一个最高分，去掉一个最低分，
剩下 m−2个评分的平均数。请问得分最高的同学分数是多少？评分保留 2 位小数。
*/
#include<stdio.h>
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    double A[n][m];
    double B[n];
    for (int i = 0; i < n; i++)
    {
        B[i]=0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%lf",&A[i][j]);
        }
    }
    int min;
    int mi;
    for ( int a = 0; a < n; a++)
    {
        for (int b = 0; b < m-1; b++)
        {
            min=A[a][b];
            mi=b;
            for (int j = b+1; j < m; j++)
            {
                if (A[a][j]<min)
                {
                    min=A[a][j];
                    mi=j;
                }
            }
            A[a][mi]=A[a][b];
            A[a][b]=min;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            B[i]=B[i]+A[i][j];
        }
    }
    int min1;
    for ( int i=0; i<n; i++)
    {
        for (int j=n-1; j>=i; j--)
        {
            if (B[j]<B[j-1])
            {
                min1=B[j-1];
                B[j-1]=B[j];
                B[j]=min1;
            }
        }
    }
    printf("%.2f",B[n-1]/(m-2));
    return 0;
}

