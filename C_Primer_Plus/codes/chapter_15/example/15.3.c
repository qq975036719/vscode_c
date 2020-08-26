// 定义并使用位字段
#include <stdio.h>
#include <stdbool.h>

// 线的样式
#define SOLID 0     // 实线
#define DOTTED 1    // 点线
#define DASHED 2    // 虚线
// 三原色
#define BLUE 4
#define GREEN 2
#define RED 1
// 混合色
#define BLACK 0
#define YELLOW (RED | GREEN)
#define PURPLE (RED | BLUE)
#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

// 颜色数组
const char *color[8] = {"black", "red", "green", "yellow", "blue", "purple", "cyan", "white"};

// 结构定义
struct box_props {
    bool opaque : 1;                    // 方框透明或不透明
    unsigned int fill_color : 3;        // 方框的填充颜色
    unsigned int : 4;                   // 填充字段
    bool show_border : 1;               // 打开或关闭边框
    unsigned int border_color : 3;      // 边框颜色
    unsigned int border_style : 2;      // 边框样式
    unsigned int : 2;                   // 填充字段
};

void show_settings(const struct box_props *);

int main(void)
{
    // 创建并初始化box_props结构
    struct box_props box = {true, PURPLE, true, CYAN, DASHED};
    printf("Original box settings:\n");
    show_settings(&box);

    // 更改box的属性
    box.opaque = false;
    box.fill_color = GREEN;
    box.show_border = false;
    box.border_color = WHITE;
    box.border_style = DOTTED;

    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}

void show_settings(const struct box_props * pbox)
{
    printf("Box is %s\n",
           pbox->opaque == 1 ? "透明" : "不透明");
    printf("The fill color is %s\n", color[pbox->fill_color]);
    printf("Border %s\n",
           pbox->show_border == 1 ? "打开" : "关闭");
    printf("The border color is %s\n", color[pbox->border_color]);
    printf("The border is ");
    switch (pbox->border_style) {
        case SOLID:
            printf("实线\n");
            break;
        case DOTTED:
            printf("点线\n");
            break;
        case DASHED:
            printf("虚线\n");
            break;
        default:
            printf("不存在的线模式\n");
            break;
    }
}