// 猜数字程序
#include <stdio.h>

int main(void)
{
    int guess = 1;
    char response;
    printf("从1到100之间选择一个整数，我会猜你心里想的这个数字\n");
    printf("如果我猜对了,请你输入\"y\",猜错了请输入\"n\"\n");
    printf("emmm....你心里的数字是%d吗?\n", guess);
    while ((response = getchar()) != 'y') {
        if (response == 'n')
            printf("emmm....那你心里的数字是%d吗?\n", ++guess);
        else
            printf("抱歉,我只能接受\"y\"或者\"n\"的回应!\n");
        while (getchar() != '\n')       // 跳过剩余的输入行
            continue;
    }
    printf("我猜对啦哈哈哈！");
    return 0;
}