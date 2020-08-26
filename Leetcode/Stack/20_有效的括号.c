#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    int len = strlen(s);
    char stack[len + 1];                        // 栈
    int top = -1;                               // 栈顶指针

    for (int i = 0; i < len; i++) {
        // 左括号入栈 -- 用相应的右括号入栈 -- 方便匹配
        if (s[i] == '(') stack[++top] = ')';
        else if (s[i] == '[') stack[++top] = ']';
        else if (s[i] == '{') stack[++top] = '}';
        
        // 不是左括号那就只有右括号了，栈空或不匹配则非法
        else if (top == -1 || stack[top] != s[i])
            return false;
        // 栈非空匹配 -- 出栈 -- 即栈顶指针往下移
        else
            top--;
    }

    // 如果遍历完字符串s后栈非空 -- 还有左括号未匹配 -- 非法
    // 如果遍历完字符串s后栈为空 -- 所有左括号匹配完 -- 合法
    return (top == -1);
}

int main(void)
{
    char *st = "([])";
    if (isValid(st))
        puts("yes");
    else
        puts("false");

    return 0;
}