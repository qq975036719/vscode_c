// 串基本操作
#include <stdio.h>
#include <stdlib.h>

// 获取字符串长度
int StrLength(char *st)
{
    int length = 0;
    while (*st++)
        length++;

    return length;
}

// 获取指定下标处指定长度的子串
int SubString(char **sub, char *s, int index, int length)
{
    int s_len = StrLength(s);
    int j = 0;

    // 检查输入的下标及获取的长度是否有效
    if (index > s_len)
        return 0;
    else if (s_len < index + length)
        return 0;
    // 有效后开始获取子串
    char *p = s;
    p = p + index;
    *sub = (char *)malloc(sizeof(char) * length+1);


    for (j = 0; j < length; j++)
        (*sub)[j] = *(p++);
    (*sub)[length] = '\0';

    return 1;
}

// 比较两个字符串是否相等
int StrCompare(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i]) {
        if (s1[i] > s2[i])
            return 1;
        else if (s1[i] < s2[i])
            return -1;
        i++;
    }
    if (s1[i])
        return 1;
    if (s2[i])
        return -1;
    return 0;
}

// 找出子串在主串中指定位置开始第一次出现的下标位置
int StrIndex(char *s, char *t, int pos)
{
    int slen, tlen;
    char *sub = NULL;
    slen = StrLength(s);
    tlen = StrLength(t);

    for (int i = pos; i < slen - tlen + 1; i++) {
        SubString(&sub, s, i, tlen);
        if (StrCompare(sub, t) == 0)
            return i;
    }
    return -1;
}

int main(void)
{
    char *s = "fuck";
    char *t = "k";

    printf("%d\n", StrIndex(s, t, 0));

    return 0;
}