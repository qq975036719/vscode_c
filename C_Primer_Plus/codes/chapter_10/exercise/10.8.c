// 把一个内含7个元素的数组中第3~5个元素拷贝到一个内含3个元素的数组中
#include <stdio.h>

int main(void)
{
    void copy_ptr(double *ar, double *source, int n);
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target[3];

    copy_ptr(target, source + 2, 3);
    for (int i = 0; i < 3; i++)
        printf("%g  ", target[i]);

    return 0;
}

void copy_ptr(double *ar, double *source, int n)
{
    for (int i = 0; i < n; i++)
        *(ar + i) = *(source + i);
}
