// 使用多重标签
#include <stdio.h>

int main(void)
{
    char ch;
    int a_ct, e_ct, i_ct, o_ct, u_ct;
    a_ct = e_ct = i_ct = o_ct = u_ct = 0;

    printf("请输入一句话,此程序会统计这句话里的元音字母数量(输入#表示句子结束): ");
    while ((ch = getchar()) != '#') {
        switch (ch)
        {
        case 'a':
        case 'A':
            a_ct++;
            break;
        case 'e':
        case 'E':
            e_ct++;
            break;
        case 'i':
        case 'I':
            i_ct++;
            break;
        case 'o':
        case 'O':
            o_ct++;
            break;
        case 'u':
        case 'U':
            u_ct++;
            break;
        default:
        break;
        }
    }
    printf("这句话里元音字母的数量为:");
    printf("\tA\tE\tI\tO\tU\n\n");
    printf("\t\t\t\t%d\t%d\t%d\t%d\t%d",
           a_ct, e_ct, i_ct, o_ct, u_ct);

    return 0;
}