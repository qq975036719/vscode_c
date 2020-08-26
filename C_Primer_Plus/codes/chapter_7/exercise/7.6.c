// 统计一句话中ei出现的次数
#include <stdio.h>

int main(void)
{
    int count = 0;
    char ch, prev;

    printf("请输入一句话,此程序会统计这句话中\"ei\"出现的次数: ");
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case 'e': {
                prev = ch;
                printf("%c", ch);
                break;
            }
            case 'i': {
                if (prev == 'e')
                    count++;
                printf("%c", ch);
            }
            default:
                printf("%c", ch);
        }
    }
    printf("\n这句话中\"ei\"出现的次数为: %d", count);

    return 0;
}