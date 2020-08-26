// 输出最长的单词
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ShowMaxWord(char *st)
{
    // 变量定义
    int i = 0;                  // 用来记录单词的下标
    int j = 0;                  // 用来扫描单词
    int max_length = 0;         // 统计最长单词的长度
    int each_length;            // 统计每个单词的长度
    int max_index = 0;          // 记录最长单词下标

    /* ************************************************************ */

    // 扫描循环
    while (st[j] != '\0') {     // 扫描字符串直到结尾
        // 过滤字符串开始前的空格 -- 如  Hello world，让j从'H'开始扫描
        while (isspace(st[j])) {
            j++;
            i = j;              // 扫描后让i指向单词开始处
        }
        while (isalpha(st[j]))  // 如果j扫描到字母，则让j后移
            j++;
        each_length = j - i;    // 当j扫描到非字母时，统计该单词长度

        // 如果单词长度大于最长长度，则最长单词的下标更新，否则不变
        max_index = (each_length > max_length) ? i : max_index;
        // 如果单词长度大于最长长度，则最长单词的长度更新，否则不变
        max_length = (each_length > max_length) ? each_length : max_length;
        /*
            ps: 这里要先更新最长单词的下标之后才更新最长单词的长度
                因为最长单词的下标需要和上一次的最长单词的长度进行
                比较后才能确认，如果先更新最长单词长度则无法得到有
                效的下标
        */
       
       // 扫描完一个单词之后过滤掉后面每个单词后面的空格或标点符号
        while (isspace(st[j]) || ispunct(st[j]))
            j++;
        // 过滤完后i指向新的单词开始处
        i = j;
    }
    
    /* ************************************************************ */

    // 打印输出最长单词

    // 从最长单词的下标处开始打印max_length个长度的字符
    int index = max_index;
    for (int k = 0; k < max_length; k++)
        putchar(st[index++]);
    putchar('\n');
}

// 测试最长单词程序
int main(void)
{
    char *st = "Hello World, I love the world!";
    ShowMaxWord(st);

    return 0;
}