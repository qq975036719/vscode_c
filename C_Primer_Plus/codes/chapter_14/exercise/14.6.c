// 读取垒球队信息文件到结构体中
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    struct {
        char fname[30];
        char lname[30];
    };
    int times;
    int beat_times;
    int go_times;
    int RBI;
    float beat_rate;
} PLAYER;

PLAYER player_list[19] = {};

void read_data(PLAYER list[], FILE *fp);    // 获取文件信息 -- 保存到结构体中
void set_beat_rate(PLAYER list[]);          // 计算安打率
void show_info(PLAYER list[]);              // 打印球员信息

int main(void)
{
    FILE *fp = NULL;

    // 打开文件
    if ((fp = fopen("data.txt", "r")) == NULL) {
        fprintf(stderr, "Open file \"data.txt\" failed.\n");
        exit(EXIT_FAILURE);
    }

    read_data(player_list, fp);
    set_beat_rate(player_list);
    show_info(player_list);

    return 0;
}

void read_data(PLAYER list[], FILE *fp)
{
    int id, times, beat_times, go_times, RBI;
    int read_count;
    char fname[20];
    char lname[20];

    while (1) {
        read_count = fscanf(fp, "%d %s %s %d %d %d %d",
                            &id, fname, lname, &times, &beat_times, &go_times, &RBI);

        if (read_count < 7)
            break;
        else {
            list[id].id = id;
            strcpy(list[id].fname, fname);
            strcpy(list[id].lname, lname);
            list[id].times += times;
            list[id].beat_times += beat_times;
            list[id].go_times += go_times;
            list[id].RBI += RBI;
        }
    }
}

void set_beat_rate(PLAYER list[])
{
    for (int i = 0; i < 19; i++) {
        if (list[i].times != 0 &&
            strcmp(list[i].fname, "\0") &&
            strcmp(list[i].fname, "\0"))
        {
            list[i].beat_rate = (float)list[i].beat_times / (float)list[i].times;
        }
    }
}

void show_info(PLAYER list[])
{
    printf("ID   First Name   Last Name   Times   Beat Times   Go Times   RBI   Beat Rate\n");

    for (int i = 0; i < 19; i++)
        printf("%-7d %-12s %-10s %-10d %-10d %-8d %-7d %-6.2f\n",
               list[i].id, list[i].fname, list[i].lname, list[i].times, list[i].beat_times,
               list[i].go_times, list[i].RBI, list[i].beat_rate);
}