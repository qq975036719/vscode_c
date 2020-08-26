// 拷贝文件 -- 用户输入文件名 -- 将文本内容全部转换为大写拷贝进新文件 -- 用文本模式
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define BUFFER_SIZE 512

int main(void)
{
    char file_name[40];
    FILE *f_src;
    char buff[BUFFER_SIZE];

    // 读入文件名
    printf("请输入文件名: ");
    while (scanf("%40s", file_name) != 1) {
        fprintf(stderr, "你输入的文件名有误!");
        exit(EXIT_FAILURE);
    }
    
    // 打开文件
    if ((f_src = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "打开文件: %s 失败", file_name);
        exit(EXIT_FAILURE);
    }
    
    size_t bytes;
    // 读取原文件的内容到缓冲区
    if ((bytes = fread(buff, sizeof(char), BUFFER_SIZE, f_src)) > 0) {
        fclose(f_src);
        f_src = fopen(file_name, "w");
        // 将buff中的内容转换为大写
        for (int i = 0; i < bytes; i++)
            if (isalpha(buff[i]))
                buff[i] = toupper(buff[i]);
        // 转换好的缓冲区内容拷贝到目标文件中
        fwrite(buff, sizeof(char), bytes, f_src);
    }

    fclose(f_src);

    return 0;
}