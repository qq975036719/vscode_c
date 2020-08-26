#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char * s){
    if(*s == 0) return true;    // 空字符串显然符合
    int len = strlen(s);
    if(len & 1) return false;   // 奇数长度的字符串显然不符合
    char stack[len/2+1];        // 只检查*s的前一半，
    // i遍历*s，top管理stack，如果前一半未出栈且下一个还不能匹配，不符合
    for(int i=0, top=-1; i<len && top<len>>1; ++i){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            stack[++top] = s[i];// 如果是左括号们，欢迎入栈
        else if(top == -1)
            return false;       // 不是左括号们，栈空则无法配对，不符合
        else if(s[i] == stack[top]+1 || s[i] == stack[top]+2)
            stack[top--] = 0;   // 不是左括号们，栈非空，当前和栈顶配对，出栈
        else
            return false;       // 不是左括号们，栈非空，当前和栈顶不配对，不符合
    }
    return !stack[0];           // 最后栈为空则符合，不为空则不符合
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