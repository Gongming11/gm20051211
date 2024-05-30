//判断一组数中出现次数最多的数
#include<stdio.h>
int main() 
{
    int n, c, i, j;
    int max = 0;
    int count[10001]={0};
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        scanf("%d",&c);
        count[c]++;
    }
    for (j = 0; j < 10001; j++)
    {
        if (count[j]>count[max])
        {
            max=j;
        }
    }
    printf("%d\n",max);
    return 0;
}