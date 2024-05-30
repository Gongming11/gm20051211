//实现黑客帝国中的代码雨效果
#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>  
#include <windows.h>  
  
#define COLUMNS 30 // 控制台宽度  
#define ROWS 18    // 控制台高度  
#define NUM_STARS 135 // 数字数量，应该是9的倍数  
#define GROUP_SIZE 9 // 每组数字的数量
#define DELAY_MS 10 // 下落速度，单位毫秒  
  
typedef struct // 定义数字结构体 
{  
    int x; // 数字的x坐标  
    int y; // 数字的y坐标  
} Star; 
int getRandomNumber()
{
    return rand() % 10;
}
void printFallingStars(Star stars[], int numStars ,int arr[]) 
{  
    int groupSize = GROUP_SIZE;  
    for (int i = 0; i < numStars; i += groupSize) 
    {  
        int firstStarY = rand() % 9;  
        int x = rand() % COLUMNS; // 为这一组数字选择一个随机的横坐标  
        for (int j = 0; j < groupSize && i + j < numStars; j++)  // 为这一组数字设置相同的横坐标和不同的纵坐标
        {    
            stars[i + j].x = x;  
            stars[i + j].y = firstStarY + (groupSize-j-1);   
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
                for (int i = 0; i < numStars; i++) 
                {  
                    if (stars[i].x == x && stars[i].y == y) 
                    {  
                        printStar = 1;  
                        break;  
                    }  
                }  
                printf(printStar ? "\033[32m%d\033[0m" : " ",getRandomNumber());  
            }  
            printf("\n");  
        }   
        for (int i = 0; i < numStars; i++) 
        {  
            stars[i].y++; // 数字下落  
            if (stars[i].y >= ROWS) // 如果数字下落到屏幕底部
            {   
                stars[i].y = 0; // 重置到顶部  
                if (i%groupSize==0)//每一组随机分配纵坐标
                {
                    arr[i/9]=rand() % 10;
                    stars[i].x+=arr[i/9];
                }else
                {
                    stars[i].x+=arr[i/9];
                    if (stars[i].x>=COLUMNS)
                    {
                        stars[i].x-=30;
                    }
                }      
            }  
        }  
        Sleep(DELAY_MS);// 暂停一段时间以模拟下落效果   
    }  
}  
int main() 
{  
    srand(time(NULL)); // 初始化随机数生成器  
    Star stars[NUM_STARS]; // 同时下落的数字数量  
    int arr[NUM_STARS/GROUP_SIZE]={0};
    int numStars = 135;
    printFallingStars(stars,numStars,arr);  
    return 0;  
}