// 二进制I/O随机访问
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main(void)
{
    double number[SIZE];
    FILE *iofile = NULL;
    const char *file = "numbers.dat";
    int index;
    long pos;

    // 创建一个double类型的数组
    for (int i = 0; i < SIZE; i++)
        number[i] = 100.0 * i + 1.0 / (i + 1);
    
    // 以二进制只写模式打开文件
    if ((iofile = fopen(file, "wb")) == NULL) {
        fprintf(stderr, "二进制只写模式打开文件: %s 失败!", file);
        exit(EXIT_FAILURE);
    }

    // 以二进制格式把数组写入文件
    fwrite(number, sizeof(double), SIZE, iofile);
    fclose(iofile);

    // 以二进制只读模式打开文件
    if ((iofile = fopen(file, "rb")) == NULL) {
        fprintf(stderr, "二进制只读模式打开文件: %s 失败!", file);
        exit(EXIT_FAILURE);
    }

    // 从文件中读取选定的内容
    fprintf(stdout, "请输入索引值(0~%d): ", SIZE-1);
    while (scanf("%d", &index) == 1 && index >= 0 && index < SIZE) {
        double temp_val = 0;
        // 计算偏移量
        pos = (long) index * sizeof(double);
        // 定位到pos处
        fseek(iofile, pos, SEEK_SET);
        // 读取pos处的数据到临时变量中
        fread(&temp_val, sizeof(double), 1, iofile);
        // 打印结果
        printf("在数组number中，索引值为%d的数值为: %f\n", index, temp_val);
        printf("请输入下一个索引值(out of range to quit): ");
    }
    // 循环退出 -- 即用户选择退出程序 -- 关闭文件 iofile
    fclose(iofile);
    puts("Done!");

    return 0;
}