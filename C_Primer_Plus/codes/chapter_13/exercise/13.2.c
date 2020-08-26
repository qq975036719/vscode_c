// 文件拷贝程序 -- 使用命令行参数获取原始文件名和拷贝文件名
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

int main(int argc, char *argv[])
{
    FILE *f_src = NULL;        // 指向原始文件
    FILE *f_dest = NULL;       // 指向目标文件(拷贝文件)
    char buff[BUFFER_SIZE];    // 缓冲区

    if (argc != 3) {
        fprintf(stderr, "参数数量错误!");
        exit(EXIT_FAILURE);
    }
    else {
        // 打开原始文件
        if ((f_src = fopen(argv[1], "rb")) == NULL) {
            fprintf(stderr, "打开文件: %s 失败!", argv[1]);
            exit(EXIT_FAILURE);
        }

        // 创建拷贝文件
        if ((f_dest = fopen(argv[2], "wb")) == NULL) {
            fprintf(stderr, "打开文件: %s 失败!", argv[2]);
            exit(EXIT_FAILURE);
        }
    }

    size_t bytes;
    // 拷贝文件
    while ((bytes = fread(buff, sizeof(char), BUFFER_SIZE, f_src)) > 0) {
        fwrite(buff, sizeof(char), bytes, f_dest);
    }
    /* 
       bytes用于存储f_src即原文件中的字符数 -- fread()函数返回的是读取的字符数
       fwrite()中第三个参数用bytes而不是用BUFFER_SIZE -- 这样就可以保证写入了
       bytes个字符就停止 
    */
    
    fclose(f_dest);
    fclose(f_src);

    return 0;
}