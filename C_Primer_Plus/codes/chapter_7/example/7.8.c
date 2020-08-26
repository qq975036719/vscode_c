// 使用条件运算符
#include <stdio.h>
#define COVERAGE 350    // 每罐油漆可刷的面积

int main(void)
{
    int acre;
    int cans;

    printf("请输入待刷油漆的面积: ");
    while (scanf("%d", &acre) == 1) {
        cans = acre / COVERAGE;
        cans += (acre % COVERAGE == 0) ? 0 : 1; // 如果刷油漆的面积刚好够整数罐
                                                // 就不用加一罐，否则就要加一罐

        printf("You need %d %s of paint.\n",
               cans, (cans == 1) ? "can" : "cans");
        printf("请输入待刷油漆的面积: ");
    }
    return 0;
}