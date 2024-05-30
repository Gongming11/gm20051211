/*现有 2^n×2^n(n≤10)名作弊者站成一个正方形方阵等候长官的发落。
长官决定赦免一些作弊者。他将正方形矩阵均分为 4 个更小的正方形矩阵，
每个更小的矩阵的边长是原矩阵的一半。其中左上角那一个矩阵的所有作弊者都将得到赦免，
剩下 3 个小矩阵中，每一个矩阵继续分为 4 个更小的矩阵，
然后通过同样的方式赦免作弊者……直到矩阵无法再分下去为止。
所有没有被赦免的作弊者都将被处以棕名处罚。

给出 n，请输出每名作弊者的命运，其中 0 代表被赦免，1 代表不被赦免。
*/
#include<stdio.h>
int arr[1024][1024]={0};
void fun(int bian,int x ,int y)
{
    if (bian == 2)
    {
        arr[x][y] = 0;
	}
	else
	{
		int i = 0;
		int j = 0;
		for (i = x;i < x + bian/2;i++)
		{
			for (j = y; j < y + bian/2 ;j++)
			{
				arr[i][j] = 0;
			}
		}
		fun(bian / 2, x + bian / 2, y + bian / 2);
		fun(bian / 2, x , y + bian / 2);
		fun(bian / 2, x + bian / 2, y );
	}
}
int main()
{
	int n = 0;
	scanf("%d",&n);
	int j = 0;
	int k = 0;
	int i = 0;
	int bian = 1;
	for (i = 0; i < n;i++)
	{
		bian *= 2;
	}
	for (j = 0; j < bian; j++)
	{
		for (k = 0; k < bian; k++)
		{
			arr[j][k] = 1;
		}
	}
	int x = 0;
	int y = 0;
	fun(bian,x,y);
	for (j = 0; j < bian; j++)
	{
		for (k = 0; k < bian; k++)
		{
			printf("%d ", arr[j][k]);
		}
		printf("\n");
	}
    return 0;
}