// 航空公司座位预订程序 -- 多航班
#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    int reserve_flag;
    char lname[30];
    char fname[30];
} SEAT;

typedef struct {
    int plane_id;
    SEAT plane[12];
} PLANE;

void show_plane_menu(void);
void show_menu(PLANE list[], int index);
void show_empty_nums(PLANE list[], int index);
void show_empty_list(PLANE list[], int index);
void show_alpha_list(PLANE list[], int index);
void book_seat(PLANE list[], int index);
void delete_book(PLANE list[], int index);
void clean_line(void);
int get_id(int num);

int main(void)
{
    PLANE plane_list[4] = {{102},{311},{444},{519}};    // 初始化航班编号
    char choice, plane_choice;
    int plane_index;

    // 初始化plane_list的座位预订状态为未预定
    for (int j = 0; j < 4; j++)
        for (int i = 0; i < 12; i++)
        {
            plane_list[j].plane[i].reserve_flag = 0;
            plane_list[j].plane[i].id = i + 1;
        }

    show_plane_menu();
    
    while (scanf("%c", &plane_choice) == 1 && 
        (plane_choice == 'a'||plane_choice=='b'||
        plane_choice == 'c' || plane_choice == 'd'))
    {
        clean_line();
        plane_index = get_id(plane_choice);
        show_menu(plane_list, plane_index);
        while (scanf("%c", &choice) == 1 && choice != 'f' && plane_index != -1) {
            // 清理输入行
            clean_line();

            switch (choice) {
                case 'a':
                    show_empty_nums(plane_list, plane_index);
                    break;
                case 'b':
                    show_empty_list(plane_list, plane_index);
                    break;
                case 'c':
                    show_alpha_list(plane_list, plane_index);
                    break;
                case 'd':
                    book_seat(plane_list, plane_index);
                    break;
                case 'e':
                    delete_book(plane_list, plane_index);
                    break;
                case 'f':
                    break;
                default:
                    printf("Error choose!\n");
            }
            show_menu(plane_list, plane_index);
        }
        if (plane_index == -1)
            break;
        if (plane_index == -2)
            printf("Error choose!\n");
        show_plane_menu();
    }
    printf("Quit successfully!\n");

    return 0;
}

void show_menu(PLANE list[], int index)
{
    printf("You have chosen Plane id: %d\n", list[index].plane_id);
    printf("To choose a function, enter its letter label: \n");
    printf("a) Show number of empty seats\n");
    printf("b) Show list of empty seats\n");
    printf("c) Show alphabetical list of seats\n");
    printf("d) Assign a customer to a seat assignment\n");
    printf("e) Delete a seat assignment\n");
    printf("f) Quit\n");
}

void show_empty_nums(PLANE list[], int index)
{
    int ct = 0;

    for (int j = 0; j < 12; j++)
        if (list[index].plane[j].reserve_flag == 0)
            ct++;

    printf("Plane id: %d\n", list[index].plane_id);
    printf("The number of empty seats: %d\n", ct);
}

void show_empty_list(PLANE list[], int index)
{
    printf("Plane id: %d\n", list[index].plane_id);
    printf("The list of empty seats:\n");
    for (int i = 0; i < 12; i++)
        if (list[index].plane[i].reserve_flag == 0)
            printf("No.%d\n", list[index].plane[i].id);
}

void show_alpha_list(PLANE list[], int index)
{
    SEAT *plist[12];
    SEAT *temp;
    int top, seek;

    // 将list的信息拷贝到plist
    for (int i = 0; i < 12; i++)
        plist[i] = &list[index].plane[i];

    for (top = 0; top < 11; top++)
        for (seek = top + 1; seek < 12; seek++)
            if (strcmp(plist[top]->fname, plist[seek]->fname) > 0) {
                temp = plist[top];
                plist[top] = plist[seek];
                plist[seek] = temp;
            }
    
    // 打印按字母顺序排序的预定信息
    printf("Plane id: %d\n", list[index].plane_id);
    printf("The alphabetical list:\n");
    for (int i = 0; i < 12; i++)
        if (plist[i]->reserve_flag == 1)
            printf("No.%d booked by %s.%s\n",
            plist[i]->id-1, plist[i]->fname, plist[i]->lname);
}

void book_seat(PLANE list[], int index)
{
    int index_1;

    printf("Plane id: %d\n", list[index].plane_id);
    // 提示用户选择空白座位
    printf("Please choose one of the empty seats: ");
    for (int i = 0; i < 12; i++)
        if (list[index].plane[i].reserve_flag == 0)
            printf("%d ", list[index].plane[i].id);
    putchar('\n');

    scanf("%d", &index_1);
    if (list[index].plane[index_1].reserve_flag == 1)
        printf("Error choose!\n");
    else {
        list[index].plane[index_1].reserve_flag = 1;
        printf("Please enter you first name and last name.\n");
        scanf("%s %s", list[index].plane[index_1].fname, list[index].plane[index_1].lname);
        printf("Book successfully!\n");
    }
    // 清理输入行
    clean_line();
}

void delete_book(PLANE list[], int index)
{
    int index_1;

    printf("Plane id: %d\n", list[index].plane_id);
    printf("Please choose one of the booked seats to delete: ");
    for (int i = 0; i < 12; i++)
        if (list[index].plane[i].reserve_flag == 1)
            printf("%d ", list[index].plane[i].id-1);
    putchar('\n');

    scanf("%d", &index_1);

    if (list[index].plane[index_1].reserve_flag == 0)
        printf("Error choose!\n");
    else {
        list[index].plane[index_1].reserve_flag = 0;
        printf("Delete booking successfully!\n");
    }
    // 清理输入行
    clean_line();
}

void show_plane_menu(void)
{
    printf("Please choose plane_id:\n");
    printf("a) 102      b) 311\n");
    printf("c) 444      d) 519\n");
    printf("q) quit\n");
}

void clean_line(void)
{
    while (getchar() != '\n')
        continue;
}

int get_id(int num)
{
    if (num == 'a')
        return 0;
    if (num == 'b')
        return 1;
    if (num == 'c')
        return 2;
    if (num == 'd')
        return 3;
    if (num == 'q')
        return -1;
    else
        return -2;
}