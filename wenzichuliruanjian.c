/*东东刚刚学完计算导论，老师给他安排了一个任务：开发一个文字处理程序。
程序最开始时输入一个字符串作为初始文档。可以认为文档开头是第 0 个字符。程序需要支持以下操作：
1 str：后接插入，在文档后面插入字符串 str，并输出文档的字符串。
2 a b：截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串。
3 a str：插入片段，在文档中第 a 个字符前面插入字符串 str，并输出文档的字符串。
4 str：查找子串，查找字符串 str 在文档中第一次出现的下标并输出；如果找不到输出 -1。
为了简化问题，规定初始的文档和每次操作中的 str 都不含有空格或换行。

第 1 行输入一个整数 q (q<=100) 表示操作次数。
第 2 行输入一行字符串。
紧接着 q 行，每行输入一个操作，操作格式如题目描述所述。

输出 q 行，分别对应着每个操作的操作结果。
*/
#include<stdio.h>
#include<string.h>
int main()
{
    char temp[1000];
    char a[400];
    char b[200];
    int n,m;
    int l,r;
    int k;
    scanf("%d",&n);
    scanf("%s",a);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&m);
        if(m==1)
        {
            scanf("%s",b);
            strcat(a,b);
            printf("%s\n",a);
        }
        else if(m==2)
        {
            scanf("%d%d",&l,&r);
            a[l+r]='\0';//另r后面的那一个为结束输出的标志
            strcpy(temp, &a[l]);//将temp的内容换成a[l]的地址
            strcpy(a, temp);//将a的内容换成a[l]的地址
            printf("%s\n",a);//从a[l]开始输出，直到'\0'结束
        }
        else if(m==3)
        {
            scanf("%d%s",&k,temp);
            strcat(temp,&a[k]);
            a[k]='\0';
            strcat(a, temp);
            printf("%s\n",a);
        }
        else if(m==4)
        {
            int flag=0;
            char keep[1000]={0};
            scanf("%s",temp);
            for(int i=0;a[i]!='\0';i++)
            {
                if(a[i]==temp[0])
                {
                    for(int j=0;j<strlen(temp);j++)
                    {
                        keep[j]=a[i+j];
                    }
                    if(strcmp(keep,temp)==0)
                    {
                        printf("%d\n",i);
                        flag++;
                        break;
                    }
                }   
            }
            if(!flag)printf("-1\n");
        }
    }
}