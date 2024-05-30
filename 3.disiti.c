#include<stdio.h>
int main()
{
    char character;
    character=getchar();
    printf("\033[s");
    while (character=='F'||character=='E'||character=='L')
    {
        switch (character)
        {
        case 'F':
            printf("\033[u");
            printf("\033[u\033[1B*********\n\033[u\033[2B*\n");
            printf("\033[u\033[3B*\n\033[u\033[4B*\n");
            printf("\033[u\033[5B*********\n\033[u\033[6B*\n");
            printf("\033[u\033[7B*\n\033[u\033[8B*\n\033[u\033[9B*");
            printf("\033[9C\033[9A\033[s");
            break;
        case 'E':
            printf("\033[u");
            printf("\033[u\033[1B*********\n\033[u\033[2B*\n");
            printf("\033[u\033[3B*\n\033[u\033[4B*\n");
            printf("\033[u\033[5B*********\n\033[u\033[6B*\n");
            printf("\033[u\033[7B*\n\033[u\033[8B*\n\033[u\033[9B*********");
            printf("\033[1C\033[9A\033[s");
            break;
        case 'L':
            printf("\033[u");
            printf("\033[u\033[1B*\n\033[u\033[2B*\n");
            printf("\033[u\033[3B*\n\033[u\033[4B*\n");
            printf("\033[u\033[5B*\n\033[u\033[6B*\n");
            printf("\033[u\033[7B*\n\033[u\033[8B*\n\033[u\033[9B*********");
            printf("\033[1C\033[9A\033[s");
            break;
        }
        character=getchar();
    }
    printf("\033[9B");
    return 0;
}