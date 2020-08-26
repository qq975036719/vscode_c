#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s)
{
    if (*s == '\0')
        return true;
    int len = strlen(s);
    if (len & 1)            // 奇数不符合
        return false;
    char stack[len / 2 + 1];
    for (int i = 0, top = -1; i < len &&top < (len / 2); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')      // 左括号 -- 入栈
            stack[++top] = s[i];
        else if (top == -1)                 // 栈空 -- 无法匹配
            return false;
        else if (s[i] == stack[top] + 1 || s[i] == stack[top] + 2)  // 栈非空 -- 匹配，出栈
            stack[top--] = 0;
        else                                                        // 栈非空 -- 不匹配，结束
            return false;
    }
    return !stack[0];
}

int main(void)
{
    char *st = "([[]])";
    
    if (isValid(st))
        puts("yes");
    else
        puts("false");

    return 0;
}