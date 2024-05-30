/*编写一个程序对一个char类型的二维数组进行排序，并满足每行的字符按ASCII码的大小从小到大排序
并且上一行的字符的ASCII码之和不能超过下一行*/
#include<stdio.h>
void shuzu()
{
    int i, j, g, h;
    int k, s;
    int m, x, y;
    scanf("%d%d\n",&k,&s);//确定输入的二维数组的行和列
    char a[k][s];
    int b[k];
    int c[k];
    for ( g = 0; g < k; g++)
    {
        b[g]=0;//定义一个一维数组并按二维数组的行数确定大小，用来计算二维数组每行字符的ASCII码之和并比较
    }
    for ( h = 0; h < k; h++)
    {
        c[h]=h;//定义一个一维数组并按二维数组的行数确定大小，方便在后续的二维数组的行的互换中作为索引
    }
    for ( i = 0; i < k; i++)
    {
        /*for ( j = 0; j < s; j++)
        {
            a[i][j]=getchar();//依次将字符输入到数组之中
        }*/
        scanf("%s",a[i]);
    }
    char min;
    int mi;
    for ( m = 0; m < k; m++)
    {
        for (int i = 0; i < s-1; i++)
        {
            min=a[m][i];
            mi=i;
            for (j = i+1; j < s; j++)
            {
                if (a[m][j]<min)
                {
                    min=a[m][j];
                    mi=j;
                }
            }
            a[m][mi]=a[m][i];
            a[m][i]=min;
        }
    }//先用选择排序法将二维数组每一行的字符按照ASCII码的大小进行从小到大的排序
    for ( x = 0; x < k; x++)
    {
        for ( y = 0; y < s; y++)
        {
            b[x]=b[x]+(int)a[x][y];//计算二维数组每一行的字符的ASCII码之和
        }
    }
    int min1,m1,p,q;
    for ( p = 0; p < k; p++)
    {
        for ( q = k-1; q >= p; q--)
        {
            if (b[q]<b[q-1])
            {
                min1=b[q-1];
                b[q-1]=b[q];
                b[q]=min1;
                m1=c[q-1];
                c[q-1]=c[q];//同时将作为索引的数组中的元素进行对应的互换
                c[q]=m1;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < s; j++)
        {
            printf("%c ",a[c[i]][j]);//c[i]作为索引，明确没进行行互换的二维数组的每一行的输出顺序
        }
        printf("\n");//进行换行
    }
}
int main()
{
    shuzu();//调用函数
    return 0;
}