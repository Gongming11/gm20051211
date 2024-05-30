//实现黑客帝国中的代码雨效果
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <windows.h>  
  
#define COLUMNS 30 // 控制台宽度  
#define ROWS 20   // 控制台高度  
#define NUM_STARS 135 // 星星数量，应该是9的倍数  
#define GROUP_SIZE 9 // 每组星星的数量
#define DELAY_MS 10 // 下落速度，单位毫秒  
  
struct Star// 定义星星结构体
{  
    int x; // 星星的x坐标  
    int y; // 星星的y坐标  
} ;
int getRandomNumber()
{
    return rand() % 10;
}
typedef struct Star Star;  
int main() 
{  
    srand(time(NULL)); // 初始化随机数生成器  
    Star stars[NUM_STARS/GROUP_SIZE][GROUP_SIZE]; // 同时下落的星星数量  
    int numStars = NUM_STARS;
    int arr[GROUP_SIZE];
    int groupSize = GROUP_SIZE;  
    for (int i = 0; i < numStars/groupSize; i += 1) 
    {  
        int firstStarY = rand() % 10;  
        int x = rand() % COLUMNS; // 为这一组星星选择一个随机的横坐标  
        for (int j = 0; j < groupSize; j++) 
        {    
            stars[i][j].x = x;  
            stars[i][j].y = firstStarY + (groupSize-j-1);// 为这一组星星设置相同的横坐标和不同的纵坐标   
        }  
    }  
    while (1) // 无限循环，直到中断程序
    {  
        system("cls"); // 清屏  
        for (int y = 0; y < ROWS; y++) 
        {  
            for (int x = 0; x < COLUMNS; x++) 
            {  
                int printStar = 0;  
                for (int i = 0; i < numStars/groupSize; i++) 
                {  
                    for (int j = 0; j < groupSize; j++)
                    {
                        if (stars[i][j].x == x && stars[i][j].y == y) 
                        {  
                            printStar = 1;  
                            break;  
                        }  
                    }
                }  
                printf(printStar ? "\033[32m%d\033[0m" : " ",getRandomNumber());  
            }  
            printf("\n");  
        }
        for (int i = 0; i < numStars/groupSize; i++) 
        {  
            for (int j = 0; j < groupSize; j++)
            {
                stars[i][j].y++; // 星星下落  
                if (stars[i][j].y >= ROWS) // 如果星星下落到屏幕底部
                {   
                    stars[i][j].y = 0;
                    if (j==0)
                    {
                        arr[i]=rand() % COLUMNS;
                        stars[i][j].x+=arr[i];
                        if ( stars[i][j].x>=COLUMNS)
                        {
                            stars[i][j].x-=COLUMNS;
                        }
                    }else
                    {
                        stars[i][j].x+=arr[i];
                        if ( stars[i][j].x>=COLUMNS)
                        {
                            stars[i][j].x-=COLUMNS;
                        }
                    }
                }  
            }
        }  
        Sleep(DELAY_MS);// 暂停一段时间以模拟下落效果 
    }      
    return 0;
}   
  
