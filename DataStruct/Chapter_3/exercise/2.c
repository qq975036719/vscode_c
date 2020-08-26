// 检查表达式括号是否匹配
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s)
{
    char stack[200];
    int len = strlen(s);
    int top = -1;           // 栈顶指针
    bool flag = true;

    if (s == 0)
        return true;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(')
            stack[++top] = ')';
        if (s[i] == ')' && stack[top--] != s[i])
            flag = false;
    }
    // 字符串扫描完后，栈非空，则无效
    if (top != -1)
        flag = false;

    return flag;
}

int main(void)
{
    char *st = "1*(2+2)/3";

    if (isValid(st))
        puts("yes");
    else
        puts("false");
    
    return 0;
}