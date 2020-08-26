// ʹ��Queue�ӿ� -- ģ���̳��Ŷ�
#include <stdio.h>
#include "17.6_queue.h"
#include <time.h>				// ����time()
#include <stdlib.h>				// ����rand() �� srand()
#define MIN_PER_HR 60.0

bool newcustomer(double x);		// �Ƿ��й˿͵�����
Item customertime(long when);	// ���ù˿Ͳ���

int main(void)
{
	/* �������� */
	Queue line;					// ����
	Item temp;					// �µĹ˿�����
	int hours;					// ģ���Сʱ��
	int perhour;				// ÿСʱƽ������λ�˿�
	long cycle, cyclelimit;		// ѭ����������������������
	long turnaways = 0;			// ��������ʱ�ܽӵĹ˿�����
	long customers = 0;			// ������еĹ˿�����
	long served = 0;			// ��ģ���ڼ���ѯ���������˵Ĺ˿�����
	long sum_line = 0;			// �ۻ��Ķ����ܳ�
	int wait_time = 0;			// �ӵ�ǰ���������˿��������ʱ��
	double min_per_cust;		// �˿͵�����ƽ��ʱ��
	long line_wait = 0;			// �����ۼƵĵȴ�ʱ��

	// ****************************************************

	/* ��Ϣ׼�� */
	InitializeQueue(&line);			// ��ʼ������
	srand((unsigned int)time(0));	// �������
	puts("����ģ��: ����������ѯ");
	printf("������ģ���Сʱ��: ");
	scanf("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;	// �ó�ģ��ķ����� -- Ҳ����ѭ��������
	printf("������ÿСʱƽ���ж��ٹ˿ͻ���: ");
	scanf("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	// ****************************************************

	/* ģ����� */
	for (cycle = 0; cycle < cyclelimit; cycle++) {
		if (newcustomer(min_per_cust)) {
			if (QueueIsFull(&line))			// ���������� -- ���ܿ�����+1
				turnaways++;
			else {
				customers++;				// ����û�� -- �����п�����+1
				temp = customertime(cycle);	// �����¼���Ĺ˿͵Ĳ��� -- ����cycle���ӵ����Ŀ��˺�������ѯʱ��
				AddItem(temp, &line);		// ���˿���ӵ�������
			}
		}
		if (wait_time <= 0 && !QueueIsEmpty(&line)) {		// ��������û�п���ʱ�䣬�Ҷ��в��ǿյ�
			DeleteItem(&temp, &line);
			wait_time = temp.processtime;					// ��ɵ�ǰ�˿͵���ѯ����Ҫ�೤ʱ��
			line_wait += cycle - temp.arrive;				// ��ĿǰΪֹ���й˿͵ȴ�����ʱ��
			served++;										// ����Ĺ˿���+1
		}
		
		if (wait_time > 0)
			wait_time--;
		sum_line += QueueItemCount(&line);
	}
	printf("\n\n%ld\n\n", sum_line);
	if (customers > 0) {
		printf("���� %ld λ�˿�\n", customers);
		printf("������ %ld λ�˿�\n", served);
		printf("�ܽ��� %ld λ�˿�\n", turnaways);
		printf("ƽ�����г���: %.2f\n", (double)sum_line / cyclelimit);
		printf("ƽ���ȴ�ʱ��: %.2f ����\n", (double)line_wait / served);
	}
	else
		puts("û�й˿�����̫���˰�!\n");
	EmptyQueue(&line);
	puts("Bye!");
	
	return 0;
}

// x�ǹ˿͵�����ƽ��ʱ��(��λ������)
// ���1�������й˿͵������򷵻�true
bool newcustomer(double x) {
	if (rand() * x / RAND_MAX < 1)		// �������һ������0С��x����
		return true;
	else
		return false;
}

// when�ǹ˿͵�����ʱ��
// �ú�������һ��Item�ṹ���ù˿͵����ʱ������Ϊwhen
// ��ѯʱ������Ϊ1~3�����ֵ
Item customertime(long when) {
	Item cust;

	cust.processtime = rand() % 3 + 1;
	cust.arrive = when;

	return cust;
}