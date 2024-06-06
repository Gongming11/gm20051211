//实现LED滚动
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main() 
{
    int i;
    int position = 0;
    char arr[50];
    fgets(arr, sizeof(arr), stdin);
    system("clear");
    for (;;) 
    {
        printf("\033[H\033[J");
        for (i = 0; i < position; i++) 
        {
            printf(" ");
        }
        printf("\033[31m%s",arr);
        position+=1;
        if (position >= 40) 
        {
            position = 0;
        }
        usleep(100000);
    }
    return 0;
}