//在屏幕输入以下文字并且字符表示只用转义字符
//因为只能用转义字符，所以要把其从十进制改为八进制并用ASCII码打出
#include<stdio.h>
int main()
{
    printf ("\42\110\157\160\145\40\151\163\40\141\40\147");//没有换行
    printf ("\157\157\144\40\164\150\151\156\147\40\141\156\144\40");
    printf ("\155\141\171\142\145\40\164\150\145\40\142\145\163\164");
    printf ("\40\157\146\40\164\150\151\156\147\163\56\101\156\144");
    printf (" \40\156\157\40\147\157\157\144\40\164\150\151\156\147\40");
    printf ("\145\166\145\162\40\144\151\145\163\42\56");//代码分行写保证美观，放在一行太过于丑陋
    return 0;
}