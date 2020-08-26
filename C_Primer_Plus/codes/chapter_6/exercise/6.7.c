// 倒序打印输入的单词
#include <stdio.h>
#include <string.h>

int main(void)
{
    char ch[100];
    int len, i;
    printf("请输入一个单词: ");
    scanf("%s", ch);

    // 统计长度
    len = strlen(ch);
    
    // 倒序打印单词
    for (i = len-1; i >= 0; i--)
        printf("%c", ch[i]);
    /* strlen()不会统计字符串结尾的'\0'
       但是数组的下标要从len-1开始
       如hello的len == 4,则最后一个字母
       是ch[3] */
    return 0;
}