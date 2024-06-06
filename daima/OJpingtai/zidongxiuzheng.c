/*输入一个长度不超过 100 且不包括空格的字符串。
要求将该字符串中的所有小写字母变成大写字母并输出。
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char S[100];
    scanf("%s",S);
    for (int i = 0; i<strlen(S); i++)
    {
        if (S[i]>='a'&&S[i]<='z')
        {
            printf("%c",S[i]-32);//大写字母的ASCII码的值比小写字母小32
        }else
        {
            printf("%c",S[i]);
        }
    }
    return 0;
}