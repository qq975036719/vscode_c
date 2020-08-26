// 演示不同的存储类别
#include <stdio.h>

void report_count();
void accumulate(int k);

int count = 0;		// 文件作用域、外部链接、静态存储期

int main(void)
{
	int value;		// 自动变量
	register int i;	// 寄存器变量

	printf("请输入一个正整数(输入0退出程序): ");
	while (scanf("%d", &value) == 1 && value > 0) {
		++count;	// 使用文件作用域变量(全局变量)
		for (i = value; i >= 0; i--)
			accumulate(i);
		printf("请输入一个正整数(输入0退出程序): ");
	}
	report_count();

	return 0;
}

void report_count()
{
	printf("循环执行了%d次", count);
}