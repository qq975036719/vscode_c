#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int x;
    int y;
} coordinate;

void flush_cordinate(coordinate* p, int x, int y);    // ˢ������
int main(void)
{
    int x, y;                   // Madeline������
    int n, k;                   // ���������
    char direction;             // �ƶ�����
    coordinate madeline;        // �洢madeline������
    coordinate badeline;        // �洢badeline������
    coordinate* pm = &madeline;
    coordinate* pb = &badeline;

    // ��ʼ������Madeline������
    x = 0;
    y = 0;

    // ��������
    scanf("%d %d", &n, &k);
    // ����һ����ʱ���飬���ڴ洢��n-k��ʱ��madeline������

    coordinate* temp = (coordinate*)malloc((n - k + 1) * sizeof(coordinate));
    flush_cordinate(pm, x, y);  // ����madeline������
    flush_cordinate(&temp[0], x, y);  // �洢madeline�ĳ�ʼ����

    // ����������
    while (getchar() != '\n')
        continue;

    for (int i = 1; i <= n; i++) {
        // ���뷽��
        direction = getchar();

        switch (direction) {
        case 'L':
            x -= 1;
            break;
        case 'R':
            x += 1;
            break;
        case 'U':
            y += 1;
            break;
        case 'D':
            y -= 1;
            break;
        case 'S':
            break;
        }
        // ÿ�ƶ�һ�� -- ˢ��һ��madeline������
        flush_cordinate(pm, x, y);
        // ˢ����madeline������� -- �洢����ʱ������
        if (i == 1837) 
            { int a = 1; }
        flush_cordinate(&temp[i], x, y);
        // ��k��ʱ,badeline����,���ʼλ��Ϊmadeline��ʼ��λ��
        if (i >= k) {
            flush_cordinate(pb, temp[i - k].x, temp[i - k].y);
            // �ж��Ƿ�����
            if ((madeline.x == badeline.x) &&
                (madeline.y == badeline.y))
            {
                printf("no\n");
                break;
            }
        }
        // ��n������
        if (i == n) {
            flush_cordinate(pb, temp[i - k].x, temp[i - k].y);
            // �ж��Ƿ�����
            if ((madeline.x == badeline.x) &&
                (badeline.x == badeline.y))
            {
                printf("no\n");
                break;
            }
            else {
                printf("yes\n");
                break;
            }
        }
    }
    free(temp);

    return 0;
}

void flush_cordinate(coordinate* p, int x, int y)
{
    p->x = x;
    p->y = y;
}