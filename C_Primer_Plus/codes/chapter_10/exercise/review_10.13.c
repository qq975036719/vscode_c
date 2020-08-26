// a. 编写一个函数调用, 把一个内含8、3、9和2的复合字面量传递给 show() 函数
/* b. 编写一个函数调用, 把一个2行3列的复合字面量(8、3、9作为第1行, 5、4、1作为第2行)
      传递给 show2() 函数 */
#include <stdio.h>

int main(void)
{
    void show(const double ar[], int n);        // n是一维数组的个数
    void show2(const double ar2[][3], int n);   // n是二维数组的行数

    show((const double []){8, 3, 9, 2}, 4);                 // 复合字面量传递函数参数
    show2((const double [][3]){{8, 3, 9}, {5, 4, 1}}, 2);   // 复合字面量传递函数参数

    return 0;
}