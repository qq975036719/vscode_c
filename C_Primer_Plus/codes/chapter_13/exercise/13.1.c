// 对程序清单13.1的修改
// 使用标准I/O  -- 不使用命令行参数
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = NULL;
    int ch;
    unsigned long int count = 0;
    char file_name[40];

    // 提示用户输入文件名
    printf("请输入文件名: ");
    if (scanf("%40s", file_name) != 1) {
        fprintf(stderr, "你的输入有误!");
        exit(EXIT_FAILURE);
    }

    // 打开用户输入的文件名
    if ((fp = fopen(file_name, "r")) == NULL) {
        printf("Can't open %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // 从打开的文件中读取字符
    while ((ch = getc(fp)) != EOF) {
        putc(ch, stdout);
        // putchar(ch);
        count++;
    }

    // 关闭文件
    fclose(fp);
    printf("\nFile %s has %lu characters\n", file_name, count);

    return 0;
}