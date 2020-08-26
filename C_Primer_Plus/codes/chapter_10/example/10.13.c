// 指针操作
#include <stdio.h>

int main(void)
{
    int nums[5] = {100, 200, 300, 400, 500};
    int *p1, *p2, *p3;
    p1 = nums;
    p2 = &nums[2];
    printf("指针p1的值\t\t指针p1指向地址的值\t指针p1自身的地址\n");
    printf("p1 = %p\t*p1 = %d\t&p1 = %p\n", p1, *p1, &p1);

    // 指针加法
    p3 = p1 + 4;
    printf("指针p1加上一个整数后: \n");
    printf("p1 + 4 = %p, *(p1 + 4) = %d\n", p1 + 4, *(p1 + 4));
    p1++;   //指针递增(指向下一个元素)
    printf("指针p1递增后: \n");
    printf("p1 = %p, *p1 = %d, &p1 = %p\n", p1, *p1, &p1);
    p2--;   // 指针递减(指向上一个元素)
    printf("指针p2递减后: \n");
    printf("p2 = %p, *p2 = %d, &p2 = %p\n", p2, *p2, &p2);
    --p1;   // 恢复为递增前的值
    ++p2;   // 恢复为递减前的值
    printf("指针重置后: \n");
    printf("p1 = %p, p2 = %p\n", p1, p2);
    // 一个指针减去另一个指针
    printf("指针与指针做差: \n");
    printf("p2 = %p, p1 = %p, p2 - p1 = %ld\n",p2, p1, p2 - p1);
    // 一个指针减去一个整数
    printf("指针与整数做差: \n");
    printf("p3 = %p, p3 - 2 = %p\n", p3, p3 - 2);

    return 0;
}