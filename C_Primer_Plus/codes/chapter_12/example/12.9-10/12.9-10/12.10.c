// 驱动程序 -- 测试rand1()和srand1()函数
#include <stdio.h>

extern int rand1(void);
extern void srand1(unsigned int seed);

int main(void)
{
	int count = 0;
	unsigned int seed;

	printf("请输入一个数字最为种子: ");
	while (scanf("%u", &seed) == 1) {
		srand1(seed);	// 重置种子，生成不同的随机数序列
		for (count = 0; count < 5; count++)
			printf("%d\n", rand1());
		printf("请输入一个数字最为种子: ");
	}
	printf("程序已退出!");

	return 0;
}