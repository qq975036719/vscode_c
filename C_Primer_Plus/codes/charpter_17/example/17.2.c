// 使用链表
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TSIZE 45

struct film {
    char title[TSIZE];
    int rating;
    struct film *next;
};

char *s_gets(char *st, int n)
{
    char *ret_val, *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}

int main(void)
{
    struct film *head = NULL;
    struct film *prev, *current;
    char input[TSIZE];

    // 读入数据到链表中
    printf("请输入电影名(空行退出): ");
    while (s_gets(input, TSIZE) != NULL && input[0] != '\0') {
        current = (struct film *)malloc(sizeof(struct film));
        if (head == NULL)
            head = current;     // 让头指针指向第一个结点
        else
            prev->next = current;
        current->next = NULL;       // 让新结点的next指向NULL

        strcpy(current->title, input);
        printf("请输入评分: ");
        scanf("%d", &current->rating);
        // 清理输入行
        while (getchar() != '\n')
            continue;

        printf("请输入下一部电影名(空行退出): ");
        prev = current;
    }

    // 打印链表内容
    if (head == NULL)
        puts("没有任何电影信息!");
    else
        puts("电影信息如下:");
    current = head;
    while (current != NULL) {
        printf("电影名: %s -- 评分: %d\n", current->title, current->rating);
        current = current->next;
    }


    // 释放所有结点
    current = head;
    while (current != NULL) {
        head = current->next;
        free(current);
        current = head;
    }

    return 0;
}