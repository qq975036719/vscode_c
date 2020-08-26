// 把直角坐标转换为极坐标
#include <stdio.h>
#include <math.h>

#define RAD_TO_DEG 180 / (4 * atan(1))

// 极坐标结构
typedef struct polar_v {
    double magnitude;
    double angle;
} Polar_V;

// 直角坐标结构
typedef struct rect_v {
    double x;
    double y;
} Rect_V;

Polar_V rect_to_polar(Rect_V);

int main(void)
{
    Rect_V input;
    Polar_V res;

    printf("请输入直角坐标系下的x, y坐标: ");
    while (scanf("%lf %lf", &input.x, &input.y) == 2) {
        res = rect_to_polar(input);
        printf("极坐标下:(%.2f, %.2f)\n", res.magnitude, res.angle);
    }
    puts("Bye!");

    return 0;
}

Polar_V rect_to_polar(Rect_V rv)
{
    Polar_V pv;

    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
    if (pv.magnitude == 0)
        pv.angle = 0;
    else
        pv.angle = RAD_TO_DEG * atan2(rv.y, rv.x);

    return pv;
}