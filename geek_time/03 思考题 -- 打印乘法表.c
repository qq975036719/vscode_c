#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=i; j++) {
            j == 1 || printf("\t");        // �������ң�����һ����������Ͳ�ִ�еڶ�������������һ�������������ִ�еڶ�������
            printf("%d*%d=%d", j, i, j*i);
        }
        printf("\n");
    }
    return 0;
}
