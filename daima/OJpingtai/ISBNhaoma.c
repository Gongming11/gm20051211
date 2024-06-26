/*ISBN 码包括9位数字、1位识别码和3位分隔符，其规定格式如 x-xxx-xxxxx-x
最后一位是识别码
识别码的计算方法如下：
首位数字乘以1加上次位数字乘以2……以此类推，用所得的结果除以11，
所得的余数即为识别码，如果余数为10，则识别码为大写字母X。
例如 ISBN 号码 0-670-82162-4 中的识别码4是这样得到的：
对 067082162 这9个数字，从左至右，分别乘以1,2,...,9再求和，
即0×1+6×2+……+2×9=158，然后取158除以11的结果4作为识别码。
你的任务是编写程序判断输入的 ISBN 号码中识别码是否正确，如果正确，
则仅输出 Right；如果错误，则输出你认为是正确的 ISBN 号码。
*/
#include<stdio.h>
int main()
{
    char arr[13]={0};
    int sum=0,j=1,m;
    scanf("%s",arr);
    for (int i = 0; i < 11; i++)
    {
        if (arr[i]!='-')
        {
            sum+=(arr[i]-'0')*j;
            j++;
        }
    }
    m=sum%11;
    if ((m==arr[12]-'0')||(m==10&&arr[12]=='X'))
    {
        printf("Right");
    }else
    {
        if (m==10)
        {
            arr[12]='X';
            for (int i = 0; i < 13; i++)
            {
                printf("%c",arr[i]);
            }
        }else
        {
            for (int i = 0; i < 12; i++)
            {
                printf("%c",arr[i]);
            }
            printf("%d",m);
        }
    }
    return 0;
}