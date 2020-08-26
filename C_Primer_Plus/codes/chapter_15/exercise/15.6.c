// 字体信息程序
#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned int id          : 8;
    unsigned int size        : 7;
    unsigned int alignment   : 2;
    bool B_style             : 1;
    bool I_style             : 1;
    bool U_style             : 1;
} FONT;

void show_info(FONT info);      // 打印结构体的信息
void show_menu();               // 打印菜单
void change_font(FONT *info);   // 改变字体ID
void change_size(FONT *info);   // 改变字体大小
void change_alignment(FONT *info);  // 改变字体的居中方式
void turn(FONT *info, int mode);              // 改变字体风格

int main(void)
{
    FONT info = {1, 12, 0, 0, 0, 0};
    FONT *pinfo = &info;
    char choice;

    // 打印信息和菜单
    show_info(*pinfo);
    show_menu();

    while (scanf("%c", &choice) == 1 && choice != 'q') {
        switch (choice) {
            case 'f':
                change_font(pinfo);
                break;
            case 's':
                change_size(pinfo);
                break;
            case 'a':
                change_alignment(pinfo);
                break;
            case 'b':
                turn(pinfo, 0);
                break;
            case 'i':
                turn(pinfo, 1);
                break;
            case 'u':
                turn(pinfo, 2);
                break;
            case 'q':
                break;
        }
        while (getchar() != '\n')
            continue;
        show_info(*pinfo);
        show_menu();
    }
    puts("Bye!");

    return 0;
}

void show_info(FONT info)
{
    printf("ID SIZE ALIGNMENT   B     I     U\n");
    printf("%d  %d     ",info.id, info.size);
    switch (info.alignment) {
        case 0:
            printf("left     ");
            break;
        case 1:
            printf("center   ");
            break;
        case 2:
            printf("right    ");
            break;
    }
    printf("%s   %s   %s\n\n",
            info.B_style == 0 ? "off" : "on",
            info.I_style == 0 ? "off" : "on",
            info.U_style == 0 ? "off" : "on");
}

void show_menu()
{
    printf("f) change font  s) change size      a) change alignment\n");
    printf("b) toggle bold  i) toggle italic    u) toggle underline\n");
    printf("q) quit\n");
}

void change_font(FONT *info)
{
    int id;

    printf("Enter font ID(0-255): ");
    if (scanf("%d", &id) == 1) {
        if (id >= 0 && id <= 255)
            info->id = id;
        else
            printf("Invalid rage!\n");
    }
    else
        printf("Please enter int type number!\n");
}

void change_size(FONT *info)
{
    int size;
    
    printf("Enter font ID(0-255): ");
    if (scanf("%d", &size) == 1) {
        if (size >= 0 && size <= 127)
            info->size = size;
        else
            printf("Invalid rage!\n");
    }
    else
        printf("Please enter int type number!\n");
}

void change_alignment(FONT *info)
{
    char choice;

    while (getchar() != '\n')
        continue;

    printf("Select alignment:\n");
    printf("l) left     c) center     r) right\n");
    if (scanf("%c", &choice) == 1) {
        switch (choice) {
            case 'l':
                info->alignment = 0;
                break;
            case 'c':
                info->alignment = 1;
                break;
            case 'r':
                info->alignment = 2;
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    }
}

void turn(FONT *info, int mode)
{
    switch(mode) {
        case 0:
            info->B_style ^= 1;
            break;
        case 1:
            info->I_style ^= 1;
            break;
        case 2:
            info->U_style ^= 1;
            break;
    }
}