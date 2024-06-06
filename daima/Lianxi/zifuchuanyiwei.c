//将一个字符串按照26位字母表移动n位
#include<stdio.h>
#include<string.h>
int main()
{
    int m, n, h;
    scanf("%d",&m);//移动m位
    getchar();
    n=m%26;//相当于移动n位
    h=26-n;//如果移动后不超过z，就是加上n，但如果超过了z，就采用减去的方式，后移n位相当于前移26-n位
    char str[50]={};
    gets(str); 
    int i, j;
    j=strlen(str);//判断字符串的长度
    for (i = 0; i < j; i++)
    {
        if (str[i]>='a'&&str[i]<='z')//小写字母的位移
        {
            if (str[i]<='z'-n)
            {
                str[i]+=n;
            }
            else
            str[i]-=h;
        }
        if (str[i]>='A'&&str[i]<='Z')//大写字母的位移
        {
            if (str[i]<='Z'-n)
            {
                str[i]+=n;
            }
            else
            str[i]-=h;
        }
    }
    printf("%s",str);
}
