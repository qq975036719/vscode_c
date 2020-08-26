// 航空公司座位预订程序
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int reserve_flag;
    char lname[30];
    char fname[30];
} SEAT;

void show_menu(void);
void show_empty_nums(SEAT list[]);
void show_empty_list(SEAT list[]);
void show_alpha_list(SEAT list[]);
void book_seat(SEAT list[]);
void delete_book(SEAT list[]);

int main(void)
{
    SEAT seat_list[12];
    char choice;

    // 初始化seat_list的座位预订状态为未预定
    for (int i = 0; i < 12; i++) {
        seat_list[i].reserve_flag = 0;
        seat_list[i].id = i+1;
    }

    show_menu();
    while (scanf("%c", &choice) == 1 && choice != 'f') {
        // 清理输入行
        while (getchar()!='\n')
            continue;

        switch (choice) {
            case 'a':
                show_empty_nums(seat_list);
                break;
            case 'b':
                show_empty_list(seat_list);
                break;
            case 'c':
                show_alpha_list(seat_list);
                break;
            case 'd':
                book_seat(seat_list);
                break;
            case 'e':
                delete_book(seat_list);
                break;
            case 'f':
                break;
            default:
                printf("Error choose!\n");
        }
        show_menu();
    }
    printf("Quit successfully!\n");

    return 0;
}

void show_menu(void)
{
    printf("To choose a function, enter its letter label: \n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

void show_empty_nums(SEAT list[])
{
    int ct = 0;

    for (int i = 0; i < 12; i++) {
        if (list[i].reserve_flag == 0)
            ct++;
    }
    printf("The number of empty seats: %d\n", ct);
}

void show_empty_list(SEAT list[])
{
    printf("The list of empty seats:\n");
    for (int i = 0; i < 12; i++)
        if (list[i].reserve_flag == 0)
            printf("No.%d\n", list[i].id);
}

void show_alpha_list(SEAT list[])
{
    SEAT *plist[12];
    SEAT *temp;
    int top, seek;

    // 将list的信息拷贝到plist
    for (int i = 0; i < 12; i++)
        plist[i] = &list[i];

    for (top = 0; top < 11; top++)
        for (seek = top + 1; seek < 12; seek++)
            if (strcmp(plist[top]->fname, plist[seek]->fname) > 0) {
                temp = plist[top];
                plist[top] = plist[seek];
                plist[seek] = temp;
            }
    
    // 打印按字母顺序排序的预定信息
    printf("The alphabetical list:\n");
    for (int i = 0; i < 12; i++)
        if (plist[i]->reserve_flag == 1)
            printf("No.%d booked by %s.%s\n",
            plist[i]->id-1, plist[i]->fname, plist[i]->lname);
}

void book_seat(SEAT list[])
{
    int index;

    // 提示用户选择空白座位
    printf("Please choose one of the empty seats: ");
    for (int i = 0; i < 12; i++)
        if (list[i].reserve_flag == 0)
            printf("%d ", list[i].id);
    putchar('\n');

    scanf("%d", &index);
    if (list[index].reserve_flag == 1)
        printf("Error choose!\n");
    else {
        list[index].reserve_flag = 1;
        printf("Please enter you first name and last name.\n");
        scanf("%s %s", list[index].fname, list[index].lname);
        printf("Book successfully!\n");
    }
    // 清理输入行
    while (getchar()!='\n')
        continue;
}

void delete_book(SEAT list[])
{
    int index;

    printf("Please choose one of the booked seats to delete: ");
    for (int i = 0; i < 12; i++)
        if (list[i].reserve_flag == 1)
            printf("%d ", list[i].id-1);
    putchar('\n');

    scanf("%d", &index);

    if (list[index].reserve_flag == 0)
        printf("Error choose!\n");
    else {
        list[index].reserve_flag = 0;
        printf("Delete booking successfully!\n");
    }
    // 清理输入行
    while (getchar()!='\n')
        continue;
}