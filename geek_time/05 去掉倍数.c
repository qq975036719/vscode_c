#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m, num[10000], temp[10000];
    scanf("%d%d", &n, &m);

    // �����û������n������
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    // ����һ�� 1 ~ m ������
    for (int i=0; i<m; i++)
        temp[i] = i+1;

    // �� 1 ~ m �����ֱַ��ж��Ƿ������������n������
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<n; j++)
            {
             if (i%num[j]==0)
                temp[i-1] = 0;
            }
    }

    // ��ӡ����������ֵ
    for (int i=0; i<m; i++)
    {
        if (temp[i] != 0) printf("%d ", temp[i]);
    }

    return 0;
}
