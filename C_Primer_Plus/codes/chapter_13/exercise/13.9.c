// 添加单词 -- 为单词编号 -- 程序下次运行会接着上次的编号开始
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 41

int get_num(FILE *);
int main(int argc, char*argv[])
{
    FILE *fp;
    char words[MAX];
    int num;

    // 判断打开文件是否成功
    if ((fp = fopen("wordy", "a+")) == NULL) {
        printf("Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    num = get_num(fp);

    // 提示用户输入单词
    printf("Enter words to add to the file; press the #");
    printf("key at the beginning of a line to terminate.\n");

    while ((fscanf(stdin, "%40s", words)) == 1 && words[0] != '#')
        fprintf(fp, "%d.%s\n", ++num, words);     // 将输入的单词存入fp指向的文件中
    
    // 打印文件中的内容
    puts("File content:");
    rewind(fp);         // 光标返回文件的开始处 -- 从开始处打印单词
    
    // 从文件中读取内容再打印
    while ((fscanf(fp, "%s", words)) == 1)
        puts(words);
    puts("Done!");

    // 判断文件是否正常关闭
    if (fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}

int get_num(FILE *fp)
{
    int num = 0;
    char content[MAX];

    rewind(fp);

    while (fgets(content, MAX, fp) != NULL)
        num++;
    
    return num;
}

