//获取不同基本数据类型所占的字节数
#include<stdio.h>
int main()
{
	printf("The size of int is %d bytes.\n", sizeof(int));
	printf("The size of char is %d bytes.\n", sizeof(char));
	printf("The size of float is %d bytes.\n", sizeof(float));
	printf("The size of long is %d bytes.\n", sizeof(long));
	printf("The size of double is %d bytes.\n", sizeof(double));
	printf("The size of long long is %d bytes.\n", sizeof(long long));
	return 0;
}