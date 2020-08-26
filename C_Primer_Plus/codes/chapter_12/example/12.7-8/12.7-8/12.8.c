// 驱动程序 -- 测试rand0()函数
#include <stdio.h>

extern unsigned int rand0(void);	// 引用12.7.c中的函数

int main(void)
{
	int count;		// 自动变量

	for (count = 0; count < 5; count++)
		printf("%d\n", rand0());
	
	return 0;
}