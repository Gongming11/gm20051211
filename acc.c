//输入单个英语字符并输出它的图案
#include<stdio.h>
int main()
{
    char letter;
    printf("Enter a letter:");
    scanf("%c",&letter);
    switch (letter)
    {
    case 'F':
        printf("\033[31m*********\n*\n*\n*\n*********\n*\n*\n*\n\033[0m");
        break;
    case 'E':
        printf("\033[32m*********\n*\n*\n*\n*********\n*\n*\n*\n*********\n\033[0m");
        break;
    case 'C':
        printf("\033[33m*********\n*\n*\n*\n*\n*\n*\n*********\n\033[0m");
        break;
    case 'L':
        printf("\033[34m*\n*\n*\n*\n*\n*\n*\n**********\n\033[0m");
        break;
    }
    return 0;
}