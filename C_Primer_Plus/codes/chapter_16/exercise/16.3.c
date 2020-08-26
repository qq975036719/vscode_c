// 极坐标转直角坐标
#include <stdio.h>
#include <math.h>
#define DEG_TO_RAD (atan(1) * 4) / 180

typedef struct Rect {
    double x;
    double y;
} Rect_V;

typedef struct Polar {
    double magnitude;
    double angle;
} Polar_V;

Rect_V polar_to_rect(Polar_V polar)
{
    Rect_V res;

    res.x = polar.magnitude * cos(polar.angle * DEG_TO_RAD);
    res.y = polar.magnitude * sin(polar.angle * DEG_TO_RAD);

    return res;
}

int main(void)
{
    Polar_V polar;
    Rect_V ans;

    printf("请输入极坐标的极径和角度(单位: 角度): ");
    scanf("%lf %lf", &polar.magnitude, &polar.angle);
 
    ans = polar_to_rect(polar);
    printf("直角坐标(%.2lf, %.2lf)\n", ans.x, ans.y);

    return 0;
}