//实现字符串动画
#include <stdio.h>  
#include <stdlib.h>  
#include <unistd.h> 

#define REGION_WIDTH 60  
#define REGION_HEIGHT 15  
#define STAR_WIDTH 11  
  
struct position 
{  
    int x;  
    int y;  
};//用结构体来存储位置  
  
void clear_screen() 
{  
    printf("\033[H\033[J");   
}  
  
void draw_star(struct position pos) 
{  
    printf("\033[31m\033[%d;%dH*****\033[0m\n", pos.y + 1, pos.x + 1);
    printf("\033[32m\033[%d;%dH  *  \033[0m\n", pos.y + 2, pos.x + 1);
    printf("\033[32m\033[%d;%dH  *  \033[0m\n", pos.y + 3, pos.x + 1);
    printf("\033[32m\033[%d;%dH  *  \033[0m\n", pos.y + 4, pos.x + 1);
    printf("\033[31m\033[%d;%dH*****\033[0m\n", pos.y + 5, pos.x + 1);
    printf("\033[33m\033[%d;%dH*****\033[0m\n", pos.y + 1, pos.x + 7);
    printf("\033[33m\033[%d;%dH*   *\033[0m\n", pos.y + 2, pos.x + 7);
    printf("\033[33m\033[%d;%dH*   *\033[0m\n", pos.y + 3, pos.x + 7);
    printf("\033[33m\033[%d;%dH*   *\033[0m\n", pos.y + 4, pos.x + 7);
    printf("\033[33m\033[%d;%dH*****\033[0m\n", pos.y + 5, pos.x + 7);   
}//打印图画  
  
void move_star(struct position *pos, char direction)//移动字符串 
{  
    switch (direction) 
    {  
        case 'w':  
        case 'W':  
            if (pos->y > 0) 
            {  
                pos->y--;  
            }  
            break;  
        case 's':  
        case 'S':  
            if (pos->y < REGION_HEIGHT - 1) 
            {  
                pos->y++;  
            }  
            break;  
        case 'a':  
        case 'A':  
            if (pos->x > 0) 
            {  
                pos->x--;  
            }  
            break;  
        case 'd':  
        case 'D':  
            if (pos->x < REGION_WIDTH - STAR_WIDTH) 
            {  
                pos->x++;  
            }  
            break;  
        default:  
            printf("Invalid move command.\n");  
            break;  
    }  
}  
  
int main() 
{  
    struct position star_pos = {REGION_WIDTH / 2 - STAR_WIDTH / 2, REGION_HEIGHT / 2}; 
    char move;  
  
    clear_screen();  
    draw_star(star_pos);  
  
    while (1) 
    {  
        printf("Enter move (w/a/s/d for up/left/down/right, q to quit): ");  
        scanf(" %c", &move); 
  
        if (move == 'q' || move == 'Q') 
        {  
            break;  
        }  
        move_star(&star_pos, move);  
        clear_screen();   
        draw_star(star_pos);  
        usleep(100000); 
    }  
    printf("Exiting the program.\n");  
    return 0;  
}