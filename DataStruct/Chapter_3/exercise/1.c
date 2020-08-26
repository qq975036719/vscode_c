// 回文串
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isHui(char *s)
{
    int len = strlen(s);
    int top = -1;                 // 栈顶指针
    char st[100];
    bool even = true;              // true -- len为偶数， false -- len为奇数
    bool flag = true;

    if (len & 1)
        even = false;
    else
        even = true;

    if (s == 0)
        return true;

    for (int i = 0; i < len / 2; i++)
        st[++top] = s[i];        // 入栈
    if (even) {
        for (int i = 0; i< len / 2; i++) {
            if (st[top--] != s[i+len/2]) {
                flag = false;
                break;
            }
        }
    }
    if (!even) {
        for (int i = 0; i< len / 2; i++) {
            if (st[top--] != s[i+len/2+1]) {
                flag = false;
                break;
            }
        }
    }

    return flag;
}

int main(void)
{
    char *s = "abba";

    if (isHui(s))
        puts("yes");
    else
        puts("false");

    return 0;
}