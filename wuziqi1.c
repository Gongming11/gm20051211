//五子棋
#include<stdio.h>
void qipan(int map[15][15])//打印棋盘
{
	int i, j;
	printf("   ");
	for ( i = 1; i < 16; i++)
	{
		printf("%3d ",i);
	}
	printf("\n   ");
	for ( i = 1; i < 16; i++)
	{
		printf("+---");
	}
	printf("+\n");
	for ( i = 1; i < 16; i++)
	{
		printf("%2d |",i);
		for ( j = 1; j < 16; j++)
		{
			if (map[i-1][j-1]==1)
			{
				printf("\033[31m %d \033[0m",map[i-1][j-1]);
			}else if (map[i-1][j-1]==2)
			{
				printf("\033[32m %d \033[0m",map[i-1][j-1]);
			}else
			{
				printf(" %d ",map[i-1][j-1]);
			}
			if (j<15)
			{
				printf("|");
			}
		}
		printf("|\n");
		if (i<15)
		{
			printf("   |");
		}
		if (i==15)
		{
			printf("   +");
		}
		for ( j = 1; j < 16; j++)
		{
			printf("---");
			if (j<15)
			{
				printf("+");
			}
		}
		printf("+\n");
	}
}
int player1(int map[15][15],int count)//玩家1的回合
{
	int n, m;
	scanf("%d%d",&n,&m);
	if (map[n-1][m-1]==0)
	{
		map[n-1][m-1]=1;
		qipan(map);
		printf("\n\n");
	}else 
	{
		printf("Error in operation.\n");
		return 0;
	}
	for (int a = 0; a < 15; a++)
	{
		for (int b = 4; b < 15; b++)
		{
			if (map[a][b-4]==1&&map[a][b-3]==1&&map[a][b-2]==1&&map[a][b-1]==1&&map[a][b]==1)
			{
				printf("Player1 wins.");
            	return 0;
			}else if (map[b-4][a]==1&&map[b-3][a]==1&&map[b-2][a]==1&&map[b-1][a]==1&&map[b][a]==1)
			{
				printf("Player1 wins.");
            	return 0;
			}
		}
	}
	for (int a = 4; a < 15; a++)
	{
		for (int b = 4; b < 15; b++)
		{
			if (1==map[a-4][b-4]&&1==map[a-3][b-3]&&1==map[a-2][b-2]&&1==map[a-1][b-1]&&1==map[a][b])
			{
				printf("Player1 wins.");
            	return 0;
			}
		}
	}
	for (int a = 4; a < 15; a++)
	{
		for (int b = 10; b > -1; b--)
		{
			if (1==map[a-4][b+4]&&1==map[a-3][b+3]&&1==map[a-2][b+2]&&1==map[a-1][b+1]&&1==map[a][b])
			{
				printf("Player1 wins.");
            	return 0;
			}
		}	
	}
	if (count==113)
        {
            printf("The result of the competition is a tie.");
            return 0;
        }
    return 0;
}
int player2(int map[15][15])//玩家2的回合
{
	int n, m;
	scanf("%d%d",&n,&m);
	if (map[n-1][m-1]==0)
	{
		map[n-1][m-1]=2;
		qipan(map);
		printf("\n\n");
	}else 
	{
		printf("Error in operation.\n");
		return 0;
	}
	for (int a = 0; a < 15; a++)
	{
		for (int b = 4; b < 15; b++)
		{
			if (map[a][b-4]==2&&map[a][b-3]==2&&map[a][b-2]==2&&map[a][b-1]==2&&map[a][b]==2)
			{
				printf("Player2 wins.");
            	return 0;
			}else if (map[b-4][a]==2&&map[b-3][a]==2&&map[b-2][a]==2&&map[b-1][a]==2&&map[b][a]==2)
			{
				printf("Player2 wins.");
            	return 0;
			}
		}
	}
	for (int a = 4; a < 15; a++)
	{
		for (int b = 4; b < 15; b++)
		{
			if (2==map[a-4][b-4]&&2==map[a-3][b-3]&&2==map[a-2][b-2]&&2==map[a-1][b-1]&&2==map[a][b])
			{
				printf("Player2 wins.");
            	return 0;
			}
		}
	}
	for (int a = 4; a < 15; a++)
	{
		for (int b = 10; b > -1; b--)
		{
			if (2==map[a-4][b+4]&&2==map[a-3][b+3]&&2==map[a-2][b+2]&&2==map[a-1][b+1]&&2==map[a][b])
			{
				printf("Player2 wins.");
            	return 0;
			}
		}	
	}
	return 0;
}
int main()
{
	int map[15][15];
	int count=0;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			map[i][j]=0;
		}
	}
	qipan(map);
	while (count<113)
	{
		count++;
		player1(map,count);
        player2(map);
	}
	return 0;
}