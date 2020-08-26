// 求序列的和 -- 1 + 1/2.0 + 1/4.0 + 1/8.0 +...
#include <stdio.h>

int main(void)
{
    int term;
    double time, power_of_2;
    int limit;
    printf("请输入求和的项数: ");
    scanf("%d", &limit);

    for(term = 1, time = 0, power_of_2 = 1; term <= limit;
         term++, power_of_2 *= 2)
         {
             time += 1 / power_of_2;
             printf("前%d项的和是%lf\n", term, time);
         }
    
    getchar();
    getchar();
    return 0;
}