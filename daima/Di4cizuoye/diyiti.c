/*C:67:01000011
  !:33:00100001
  Y:89:01011001
  D:68:01000100
  S:83:01010011
  0:00000000*///9380227253346627


/*#include<stdio.h>
int main()
{
    char a[]="C!YYDS!";
    long long *b=a;
    printf("%lld",*b);//输出的是9380227253346627
    return 0;
}*/

#include<stdio.h>
int main()
{
    long long x =9380227253346627;
    printf("%s",&x);
    return 0;
}
