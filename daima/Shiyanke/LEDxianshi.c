//实现LED滚动显示
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <unistd.h>  
  
#define WINDOW_WIDTH 70 // 滚动窗口的宽度  
#define DELAY_MS 200    // 滚动间隔，以毫秒为单位  
void clear_line() 
{  
    printf("\r\033[K"); // \r 回到行首，\033[K 清除从光标到行尾的内容  
}  
  
void led_scroll(const char *str) 
{  
    int len = strlen(str);  
    char buffer[WINDOW_WIDTH + 1]; 
    while (1) // 无限循环，模拟LED持续滚动
    {   
        for (int i = 0; i < WINDOW_WIDTH - len + 1; ++i) // 循环直到字符串完全移出窗口
        {      
            memset(buffer, ' ', WINDOW_WIDTH);// 填充空格和字符串  
            buffer[WINDOW_WIDTH - len] = '\0'; // 设置字符串结束符  
            strncpy(buffer + i, str, len);   
            printf("\r\033[34m%s", buffer); // \r 回到行首  
            fflush(stdout); // 刷新输出缓冲区  
            usleep(DELAY_MS * 1000); // 暂停一段时间，模拟滚动效果  
            clear_line(); // 清除当前行以便下一次打印  
        }    
        usleep(DELAY_MS * 1000);  
    }  
}  
int main() 
{  
    char str[100];    
    fgets(str, sizeof(str), stdin); // 读取输入的字符串，包括换行符  
    str[strcspn(str, "\n")] = 0; // 去除字符串末尾的换行符  
    led_scroll(str); // 调用函数  
    return 0;  
}