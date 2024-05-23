//输入一个整数判断其是不是素数，并输出Yes或者No
#include<stdio.h>
int main()
{
    int a,b;
    printf("Please enter a positive number:");
    scanf("%d",&a);
    if (a==1)
    {
        printf("No");//1不是素数，输出No
    }    
    else if(a==2)
    {
        printf("Yes");//2是素数，输出Yes
    }
    else
    {
        for (b=2; b<a; b++)
        {
            if(a%b==0)
            {
                printf("No");//如果可以被不是1和本身之外的数整除则不是素数，输出No
                return 0;
            }
        }
        printf("Yes");//否则是素数，输出Yes
    }
    return 0;
}