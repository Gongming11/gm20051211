//输入一个字符，输出每个字节的值
//先把字符转换成整型，除以该位字节所占的权重得到的便是该位字节的值，
//然后取余以进行下一位字节的求值，从高位依次进行，求第二位字节的值后取的余就是第一位字节的值
#include<stdio.h>
int main()
{
    char input;
    printf("Please enter a character:");
    scanf("%c",&input);
    int a = (int)input;//把字符转换成整型
    printf("The eighth bit is %d,\n",a/128);//得到该位字节的值
    a = a%128;//取余方便进行下一位字节的求值 
    printf("The seventh bit is %d,\n",a/64);
    a = a%64; 
    printf("The sixth bit is %d,\n",a/32);
    a = a%32;
    printf("The fifth bit is %d,\n",a/16);
    a = a%16;
    printf("The fourth bit is %d,\n",a/8);
    a = a%8;
    printf("The third bit is %d,\n",a/4);
    a = a%4;
    printf("The second bit is %d,\n",a/2);
    a = a%2;
    printf("The first bit is %d.\n",a);//上一位取的余就是第一位字节的值      
    return 0;
}