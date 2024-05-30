//实现计时功能
#include<stdio.h>
#include<unistd.h>
int main()
{
    int i, j, k;
    while (1) 
    {
        for (i = 0; i < 24; i++) 
        {
            for ( j = 0; j < 60; j++)
            {
                for ( k = 0; k < 60; k++)
                {
                    printf("\033[H\033[J");
                    printf("\033[31m%02d:%02d:%02d",i,j,k);
                    usleep(1000000);//间隔1秒
                }
            } 
        }
    }
    return 0;
}