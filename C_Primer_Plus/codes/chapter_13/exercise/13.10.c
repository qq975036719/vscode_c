// 根据索引值打印文件内容
#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 512

int main(void)
{
    char file_name[40];
    char buff[BUFFER_SIZE];
    FILE *fp;
    long int index;

    // 读取文件名
    printf("请输入文件名: ");
    scanf("%40s", file_name);

    // 打开文件
    if ((fp = fopen(file_name, "r")) == NULL) {
        fprintf(stderr, "文件%s打开失败", file_name);
        exit(EXIT_FAILURE);
    }

    // 提示用户输入文件位置
    printf("请输入索引值: ");
    while (scanf("%ld", &index) == 1 && index > 0) {
        // 将文件指针定位到用户输入的index处
        fseek(fp, index - 1, SEEK_SET);
        // 打印文件的内容
        if (fgets(buff, BUFFER_SIZE, fp) != NULL)
            printf("内容: %s", buff);

        printf("请输入索引值: ");
    }

    return 0;
}
