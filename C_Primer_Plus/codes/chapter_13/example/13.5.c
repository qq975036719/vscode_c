// 把文件附加到另一个文件末尾
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SLEN 81
#define BUFSIZE 4096                // 缓冲区大小

char *s_gets(char *st, int n);      // 读取文件名的函数 -- 用fgets会读取到换行符 -- 该函数可过滤换行符
void append(FILE *src, FILE *dest); // 将src文件的内容添加到dest文件中

int main(void)
{
    char file_app[SLEN];        // 目标文件名
    char file_src[SLEN];        // 源文件名
    FILE *fa;                   // 指向目标文件
    FILE *fs;                   // 指向源文件
    int file_ct = 0;            // 统计读取的文件数
    int ch;

    // 读取目标文件名
    printf("请输入目标文件名: ");
    s_gets(file_app, SLEN);

    // 打开目标文件
    if ((fa = fopen(file_app, "a+")) == NULL) {
        fprintf(stderr, "打开目标文件: %s失败!\n", file_app);
        exit(EXIT_FAILURE);
    }
    
    // 打开后为目标文件创立缓冲区
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0) {
        fputs("无法创建缓冲区!\n", stderr);
        exit(EXIT_FAILURE);
    }

    // 询问源文件名称
    printf("请输入源文件的名称(输入空行退出程序): ");
    // 读取源文件名称并判断是否重合
    while (s_gets(file_src, SLEN) && file_src[0] != '\0') {
        if (strcmp(file_src, file_app) == 0)
            fputs("不能将文件内容附加到自己的文件中!\n", stderr);
        
        // 打开源文件
        else if ((fs = fopen(file_src, "r")) == NULL) {
            fprintf(stderr, "源文件: %s 访问失败!", file_src);
            exit(EXIT_FAILURE);
        }
        else {
            // 为源文件创建缓冲区
            if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0) {
                fputs("为源文件创建缓冲区失败!\n", stderr);
                continue;
            }
            append(fs, fa);     // 将源文件添加到目标文件末尾

            // 检测读写过程是否出错
            if (ferror(fs) != 0)
                fprintf(stderr, "读取 %s 过程中出错!\n", file_src);
            if (ferror(fa) != 0)
                fprintf(stderr, "写入 %s 过程中出错!\n", file_app);
            
            // 关闭文件
            fclose(fs);
            file_ct++;
            printf("文件 %s 已添加!\n", file_src);
            printf("请输入下一个文件(输入空行退出): ");
        }
    }
    printf("文件添加完成, 共添加%d个文件\n",file_ct);

    // 打印添加完毕后的文件内容
    rewind(fa);         // 将光标置于开头
    printf("%s 的内容如下: \n", file_app);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("演示完毕!");
    fclose(fa);

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val = NULL;
    char *find = NULL;

    ret_val = fgets(st, n, stdin);      // 让ret_val指向fgets的返回值 -- 即传入的字符串
    if (ret_val) {
        // 寻找换行符
        find = strchr(st, '\n');
        // 如果找到换行符 -- 替换成空字符 -- 否则跳过剩余输入
        if (find)
            *find = '\0';
        else
            while (getchar()!='\n')
                continue;
    }

    return ret_val;
}

void append(FILE *src, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];      // 创建一个静态存储期的块作用域变量

    while ((bytes = fread(temp, sizeof(char), BUFSIZE, src)) > 0)
        fwrite(temp, sizeof(char), bytes, dest);
}