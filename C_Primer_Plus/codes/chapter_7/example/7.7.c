// 统计字符数、单词数、行数
#include <stdio.h>
#include <ctype.h>      // 提供isspace()函数原型
#include <stdbool.h>    // 提供bool类型变量原型
#define STOP '|'

int main(void)
{
    char ch;
    char prev;                  // 读入的前一个字符
    bool inword = false;        // 如果ch在单词中, 则设置为true
    int word = 0;               // 单词计数
    int ch_num = 0;             // 字符计数
    int rows = 0;               // 行数计数
    int spec_row = 0;           // 不完整的行数

    prev = '\n';
    // 读取一个字符
    while ((ch = getchar()) != STOP) {
        ch_num++;           // 统计字符

        if (ch == '\n')
            rows++;         // 统计行数

        if (!isspace(ch)&& !inword) {
            word++;             // 统计单词数
            inword = true;
        }
        if (isspace(ch) && inword)  // 到达单词末尾
            inword = false;
        prev = ch;
    }

    if (prev != '\n')
        spec_row++;
    printf("字符共:%d个, 单词有:%d个, 总行数为:%d行, 特殊行数为: %d行",
           ch_num, word, rows, spec_row);

    return 0;
}