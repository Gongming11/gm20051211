//解决八皇后问题，并输出所有的方案
#include<stdio.h>
int Queen(int n,int qipan[8][8])
{
    int count=0;
    if (n!=0)
    {
        int qipan1[8][8];
        for ( int i=0; i<8; i++)
        {
            for (int k=0; k<8; k++)
            {
                for (int j=0; j<8; j++)
                {
                    qipan1[k][j]=qipan[k][j];
                }
            }
            if (qipan[n][i]==0)
            {
                for (int j=0; j<8; j++)
                {
                    qipan1[n][j]=1;//令皇后所在的这一行全为1
                    qipan1[j][i]=1;//令皇后所在的这一列全为1
                    int q=n,p=i;
                    while (q>=0&&p<8)
                    {
                        qipan1[q--][p++]=1;//令皇后所在的右对角线的这列全为1
                    }
                    q=n,p=i;
                    while (q>=0&&p>=0)
                    {
                        qipan1[q--][p--]=1;//令皇后所在的左对角线的这列全为1
                    }
                }
                qipan1[n][i]=0;//令皇后的位置重新为0，方便输出方案时辨认皇后的位置
                count=count+Queen(n-1,qipan1);
            }
        }
        return count;
    }else 
    {
        for (int j=0; j<8; j++)
        {
            if(qipan[0][j]==0)
            {
                count=count+1;
                for(int i = 0 ; i < 8 ; i++)
                {
                    for(int j = 0 ; j < 8 ; j++)
                    {
                        if (qipan[i][j] == 1)
                        {
                            printf("1 ");
                        }else
                        {
                            printf("\033[31m0 \033[0m");//输出棋盘，1代表无法占领即空位，0代表可以占领即皇后的位置
                        }
                    }
                    printf("\n");//进行换行
                }
                printf("\n");//每次方案输出间留有空行
            }
        }
    }
    return count;
}

int main()
{
    int qipan[8][8]={0};
    printf("%d",Queen(7,qipan));//调用函数，输出一共有多少种方案
    return 0;
}