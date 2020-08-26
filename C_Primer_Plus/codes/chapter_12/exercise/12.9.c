// 提示用户输入单词并存储这些单词 -- 然后打印输出
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 30

int main(void)
{
    char temp[SIZE];
    int num;

    // 提示用户输入并判断输入是否有效
    printf("How many words do you wish to enter?");
    while (scanf("%d", &num)!=1) {
        printf("请输入一个正整数!");
        while (getchar() != '\n')
            continue;
    }

    char **words = (char **)malloc(num * sizeof(char *));

    // 提示用户输入对应个数的单词
    printf("Enter %d words now: \n", num);
    for (int i = 0; i < num; i++) {
        char temp[100];    // 用于临时存储单个单词

        scanf("%s", temp);
        
        int length = strlen(temp);      // 计算单词长度
        char *each_word = (char *)malloc(length * sizeof(char));    // 创建一个动态分配数组用于存储长度匹配的单词
        
        // 让字符串数组指向新创建的指针
        strcpy(each_word, temp);
        *(words + i) = each_word;
    }

    // 打印结果
    printf("Here are your words: \n");
    for (int i = 0; i < num; i++)
        printf("%s\n", *(words+i));

    free(words);
    return 0;
}