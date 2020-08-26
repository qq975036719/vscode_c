#include <stdio.h>
#include <string.h>

void mode_direct(char *direction, char *move);   // 带方向模式
void mode_other(char *move);                     // 无方向模式
int main(void)
{
    int T, i;
    char dire_move[10];
    char move[10];

    // 读入测试组数
    scanf("%d", &T);
    
    for (i = 0; i < T; i++) {
        // 有方向的情况
        scanf("%s", dire_move);
        if (strcmp(dire_move, "leftup") == 0||
            strcmp(dire_move, "up") == 0||
            strcmp(dire_move, "rightup") == 0||
            strcmp(dire_move, "leftdown") == 0||
            strcmp(dire_move, "down") == 0||
            strcmp(dire_move, "rightdown") == 0||
            strcmp(dire_move, "left") == 0||
            strcmp(dire_move, "right") == 0)
        {
            scanf("%s", move);
            mode_direct(dire_move, move);
        }
        // 无方向的情况
        else {
            // 将输入拷贝到move字符串中
            strcpy(move, dire_move);
            mode_other(move);
        }
    }
}

void mode_direct(char *direction, char * move)
{
    if (strcmp(move, "Walk") == 0)        // 第一种情况
        puts(direction);
    else if (strcmp(move, "Dash") == 0) {   // 第三种情况
        if (strcmp(direction, "leftup") == 0) {
            printf("left up X\n");
        }
        else if (strcmp(direction, "rightup") == 0) {
            printf("right up X\n");
        }
        else if (strcmp(direction, "leftdown") == 0) {
            printf("left down X\n");
        }
        else if (strcmp(direction, "rightdown") == 0) {
            printf("right down X\n");
        }
        else if (strcmp(direction, "left") == 0) {
            printf("left X\n");
        }
        else if (strcmp(direction, "right") == 0) {
            printf("right X\n");
        }
        else if (strcmp(direction, "up") == 0) {
            printf("up X\n");
        }
        else if (strcmp(direction, "down") == 0) {
            printf("down X\n");
        }
    }
    else
        fprintf(stderr, "Invalid input!\n");
}

void mode_other(char *move)
{
    // 速降和下蹲
    if (strcmp(move, "QuickDrop") == 0 ||
        strcmp(move, "Squat") == 0)
    {
        printf("down\n");
    }
    // 抓住墙体
    else if (strcmp(move, "Grasp") == 0) {
        printf("Z\n");
    }
    // 跳跃
    else if (strcmp(move, "Jump") == 0) {
        printf("C\n");
    }
    else
        fprintf(stderr, "Invalid input!\n");
}