// 驱动程序 -- 测试接口函数
#include <stdio.h>
#include "17.6_queue.h"

Queue queue;
Item item;

int main(void)
{
	char ch;

	puts("测试队列接口函数, 输入a来添加项");
	puts("输入d来删除一个项, 输入q退出");
	
	while ((ch = getchar()) != 'q') {
		while (getchar() != '\n')
			continue;

		switch (ch) {
			case 'a':
				if (!QueueIsFull(&queue)) {
					printf("请输入一个整数: ");
					scanf("%d", &item);
					while (getchar() != '\n') continue;
					// 添加项
					AddItem(item, &queue);
					// 打印队列信息
					printf("已经把%d放入队列\n", item);
					printf("队列里现在有%d项\n", queue.items);
				}
				else
					puts("队列已满!");
				break;
			case 'd':
				if (DeleteItem(&item, &queue)) {
					printf("已将%d从队列中删除\n", item);
					printf("队列里现在有%d项\n", queue.items);
				}
				else
					printf("列表为空, 无法执行删除操作!\n");
				break;
			case 'q':
				break;
			default:
				puts("输入有误!");
		}
		puts("输入a添加项, 输入d删除队列中的第一项, 输入q退出程序");
	}
	EmptyQueue(&queue);
	puts("Bye!");

	return 0;
}