#include<stdio.h>
int tianshu[12]={31,28,31,30,31,30,31,31,30,31,30,31};      
void yuefen(int n,int month,int firstday)
{
    printf("\n%dyear%dmonth\n",n,month);
    printf(" SUN MON TUE WED THU FRI SAT\n");
    for ( int i=0; i<firstday%7; i++)
    {
        printf("    ");
    }
    int day=1;  
    while (day<=tianshu[month-1]) 
    {  
        printf("%3d ", day++);  
        if ((firstday+day-1)%7==0) 
        {  
            printf("\n");  
        }  
    }  
    printf("\n");
}
void printrili(int n, int w, int m) 
{    
    if (m) 
    {  
        tianshu[1]=29;  
    }    
    for (int month=1; month<=12; month++) 
    {  
        int firstday=w;
        int i=0;
        while (month>1&&i<month-1)
        {
            firstday=firstday+tianshu[i];
            i++;
        }
        yuefen(n, month, firstday);  
    }  
}  
int main()
{
    int n, m;
    int x, y, w;
    scanf("%d",&n);
    if (n>1582)
    {
        x=(n-1)/100;
        y=(n-1)%100;
        w=y+y/4+x/4-2*x+36;
        if (w<0)
        {
            while (w<0)
            {
                w=w+7;
            }
        }else if (w>6)
        {
            w=w%7;
        }
        if (((n%4==0)&&(n%100!=0))||(n%400==0))
        {
            m=1;
        }else
        {
            m=0;
        }
    }else if (n<1582)
    {
        x=(n-1)/100;
        y=(n-1)%100;
        w=y+y/4+x/4-2*x+38;
        if (w<0)
        {
            while (w<0)
            {
                w=w+7;
            }
        }else if (w>6)
        {
            w=w%7;
        }
        if (((n%4==0)&&(n%100!=0))||(n%400==0))
        {
            m=1;
        }else
        {
            m=0;
        }
    }
    printrili(n, w, m);
    return 0;
}



