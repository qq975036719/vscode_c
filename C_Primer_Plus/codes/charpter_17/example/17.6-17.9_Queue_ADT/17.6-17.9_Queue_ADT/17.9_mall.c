// 使用Queue接口 -- 模拟商场排队
#include <stdio.h>
#include "17.6_queue.h"
#include <time.h>				// 包含time()
#include <stdlib.h>				// 包含rand() 和 srand()
#define MIN_PER_HR 60.0

bool newcustomer(double x);		// 是否有顾客到来？
Item customertime(long when);	// 设置顾客参数

int main(void)
{
	/* 数据声明 */
	Queue line;					// 队列
	Item temp;					// 新的顾客数据
	int hours;					// 模拟的小时数
	int perhour;				// 每小时平均多少位顾客
	long cycle, cyclelimit;		// 循环计数器、计数器的上限
	long turnaways = 0;			// 队列已满时拒接的顾客数量
	long customers = 0;			// 加入队列的顾客数量
	long served = 0;			// 在模拟期间咨询过商铺主人的顾客数量
	long sum_line = 0;			// 累积的队列总长
	int wait_time = 0;			// 从当前到商铺主人空闲所需的时间
	double min_per_cust;		// 顾客到来的平均时间
	long line_wait = 0;			// 队列累计的等待时间

	// ****************************************************

	/* 信息准备 */
	InitializeQueue(&line);			// 初始化队列
	srand((unsigned int)time(0));	// 随机种子
	puts("队列模拟: 商铺主人咨询");
	printf("请输入模拟的小时数: ");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;	// 得出模拟的分钟数 -- 也就是循环的轮数
	printf("请输入每小时平均有多少顾客会来: ");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	// ****************************************************

	/* 模拟过程 */
	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line))			// 队列满人了 -- 被拒客人数+1
				turnaways++;
			else {
				customers++;				// 队列没满 -- 队列中客人数+1
				temp = customertime(cycle);	// 设置新加入的顾客的参数 -- 即第cycle分钟到来的客人和他的咨询时长
				AddItem(temp, &line);		// 将顾客添加到队列中
			}
		}
		if (wait_time <= 0 && !QueueIsEmpty(&line)) {		// 店铺主人没有空余时间，且队列不是空的
			DeleteItem(&temp, &line);
			wait_time = temp.processtime;					// 完成当前顾客的咨询还需要多长时间
			line_wait += cycle - temp.arrive;				// 到目前为止所有顾客等待的总时间
			served++;										// 服务的顾客数+1
		}
		
		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}
	printf("\n\n%ld\n\n", sum_line);
	if (customers > 0) {
		printf("来了 %ld 位顾客\n", customers);
		printf("服务了 %ld 位顾客\n", served);
		printf("拒接了 %ld 位顾客\n", turnaways);
		printf("平均队列长度: %.2f\n", (double)sum_line / cyclelimit);
		printf("平均等待时间: %.2f 分钟\n", (double)line_wait / served);
	}
	else
		puts("没有顾客来，太惨了吧!\n");
	EmptyQueue(&line);
	puts("Bye!");
	
	return 0;
}

// x是顾客到来的平均时间(单位：分钟)
// 如果1分钟内有顾客到来，则返回true
bool newcustomer(double x) {
	if (rand() * x / RAND_MAX < 1)		// 随机生成一个大于0小于x的数
		return true;
	else
		return false;
}

// when是顾客到来的时间
// 该函数返回一个Item结构，该顾客到达的时间设置为when
// 咨询时间设置为1~3的随机值
Item customertime(long when) {
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}