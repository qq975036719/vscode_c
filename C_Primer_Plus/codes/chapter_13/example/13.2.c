// 把文件压缩到原来的1/3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(int argc, char *argv[])
{
    FILE *in;           // 指向输入文件
    FILE *out;          // 指向输出文件
    
    char name[LEN];     // 用于存储文件名
    char ch;            // 用于读取输入文件的字符

    int count = 0;      // 用于统计输入文件中的字符数

    // 检查命令行参数
    if (argc < 2) {
        fprintf(stderr, "Usage: %s\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    // 设置输入
    if ((in = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "I couldn't open the file \"%s\".\n",
                argv[1]);
        exit(EXIT_FAILURE);
    }
    
    // 生成输出文件名
    strncpy(name, argv[1], LEN - 5);     // 将输入文件的文件名存储到name中
    name[LEN - 5] = '\0';
    strcat(name, ".red");                // 在名字末尾加上后缀.red
    
    // 设置输出
    if ((out = fopen(name, "w")) == NULL) {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    // 拷贝数据到输出文件中
    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);              // 打印每3个字符中的第1个字符

    // 收尾工作
    if (fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files.\n");

    return 0;
}