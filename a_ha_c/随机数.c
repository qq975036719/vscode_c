#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int a, b, sum=10;
    srand((unsigned)time(NULL));
    a = rand()%100;
    
    printf("--------��Ϸ��ʼ������10�λ���-------------------------------------\n");
    printf("--------��Ϸ����:ÿ������һ��0~99֮������֣����м����ʤ��--------\n");
    
    while(1)
    {
        sum--;
        scanf("%d", &b);
        
        if (b>a){
            printf("���ˣ������!\n");
            printf("�㻹��%d�λ���\n", sum);
        }
        
        if (b<a){
            printf("С�ˣ������!\n");
            printf("�㻹��%d�λ���\n", sum);
        }
        
        if (a==b)
        {
            printf("��ϲ�����ˣ�\n");
            break;
        }
        
        if (sum == 0){
            printf("���ź�����Ļ����Ѿ��þ��� -->_<--");
            break;
        }
    }
    return 0;
}

