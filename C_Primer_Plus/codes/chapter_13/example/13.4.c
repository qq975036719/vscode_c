// 倒序显示文件中的内容
#include <stdio.h>
#include <stdlib.h>

#define CNTL_Z '\032'
#define SLEN 81

int main(void)
{
    char ch;
    char file[SLEN];

    FILE *fp = NULL;

    long last;
    
    // 提示用户输入文件名
    printf("请输入文件名: ");
    scanf("%80s", file);

    // 判断是否可以打开用户输入的文件
    if ((fp = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "无法打开文件: %s", file);
        exit(EXIT_FAILURE);
    }

    // 定位到文件的末尾
    fseek(fp, 0L, SEEK_END);
    last = ftell(fp);   // ftell() 返回光标当前位置离首字符的距离 -- 此处即为文件中的字符数

    // 从文件结尾处开始反向遍历
    for (long count = 1L; count <= last; count++) {
        fseek(fp, -count, SEEK_END);       // 让光标回退
        ch = getc(fp);      // 获取当前光标处的字符
        if (ch != EOF)
            putchar(ch);
    }
    putchar('\n');
    fclose(fp);

    return 0;
}