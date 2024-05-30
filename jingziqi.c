//实现井字棋
#include<stdio.h>
int player1(char arr[3][3],int count)//玩家1的操作
{
    int n, m;
    scanf("%d%d",&n,&m);
    if (arr[n-1][m-1]=='0')//确保该位置是空的
    {
        arr[n-1][m-1]='X';///玩家一的妻棋子是X
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j]=='X')
                {
                    printf("\033[31m%c  \033[0m",arr[i][j]);
                }else if (arr[i][j]=='O')
                {
                    printf("\033[32m%c  \033[0m",arr[i][j]);//不同的棋子用不同的颜色打印
                }else 
                {
                    printf("%c  ",arr[i][j]);
                }
            }
            printf("\n");
            printf("\n");
        }
        printf("\n");
    }else
    {
        printf("Error in operation.\n");
        return 0;
    }
    for (int a = 0; a < 3; a++)
    {
        if (arr[a][0]=='X'&&arr[a][1]=='X'&&arr[a][2]=='X')//行的胜利条件
        {
            printf("Player1 wins.");
            return 0;
        }else if (arr[0][a]=='X'&&arr[1][a]=='X'&&arr[2][a]=='X')//列的胜利条件
        {
            printf("Player1 wins.");
            return 0;
        }else if ((arr[0][0]=='X'&&arr[1][1]=='X'&&arr[2][2]=='X')||(arr[0][2]=='X'&&arr[1][1]=='X'&&arr[2][0]=='X'))//对角线的胜利条件
        {
            printf("Player1 wins.");
            return 0;
        }
    }
    if (count==5)
        {
            printf("The result of the competition is a tie.");//玩家1 的第五回合代表棋盘已经下满了，还没取胜是平局
            return 0;
        }
    return 0;
}
int player2(char arr[3][3])
{
    int n, m;
    scanf("%d%d",&n,&m);
    if (arr[n-1][m-1]=='0')
    {
        arr[n-1][m-1]='O';
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (arr[i][j]=='X')
                {
                    printf("\033[31m%c  \033[0m",arr[i][j]);
                }else if (arr[i][j]=='O')
                {
                    printf("\033[32m%c  \033[0m",arr[i][j]);
                }else 
                {
                    printf("%c  ",arr[i][j]);
                }
            }
            printf("\n");
            printf("\n");
        }
        printf("\n");
    }else
    {
        printf("Error in operation.\n");
        return 0;
    }
    for (int a = 0; a < 3; a++)
    {
        if (arr[a][0]=='O'&&arr[a][1]=='O'&&arr[a][2]=='O')
        {
            printf("Player2 wins.");
            return 0;
        }else if (arr[0][a]=='O'&&arr[1][a]=='O'&&arr[2][a]=='O')
        {
            printf("Player2 wins.");
            return 0;
        }else if ((arr[0][0]=='O'&&arr[1][1]=='O'&&arr[2][2]=='O')||(arr[0][2]=='O'&&arr[1][1]=='O'&&arr[2][0]=='O'))
        {
            printf("Player2 wins.");
            return 0;
        }
    }
    return 0;
}
int main()
{
    int count=0;
    char arr[3][3]={{'0','0','0'},{'0','0','0'},{'0','0','0'}};//打印棋盘
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%c  ",arr[i][j]);
        }
        printf("\n");
        printf("\n");
    }
    while (count<5)
    {
        count++;
        player1(arr,count);//玩家1的第五回合代表棋盘已经下满了
        player2(arr);
    }
    return 0;
}