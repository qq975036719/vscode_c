// 打印个人平均分和班级平均分
#include <stdio.h>
#include <string.h>
#define CSIZE 4

typedef struct {
    char fname[30];
    char lname[30];
}FULL_NAME;

typedef struct {
    FULL_NAME name;
    float grade[3];
    float average;
} student;

void get_grade(student *p[CSIZE]);
void calc_average(student *p[CSIZE]);
void show_info(student *p[CSIZE]);
void show_tot_average(student *p[CSIZE]);

int main(void)
{
    student student_list[CSIZE] = {
        {{"Mike", "Fuck"}},
        {{"Andy", "Shit"}},
        {{"Hello", "Bitch"}},
        {{"Dick", "Jason"}},
    };
    student *pstu[CSIZE];
    for (int i = 0; i < CSIZE; i++)
        pstu[i] = &student_list[i];

    get_grade(pstu);
    calc_average(pstu);
    show_info(pstu);
    show_tot_average(pstu);

    return 0;
}

void get_grade(student *p[CSIZE])
{
    char fname[20];
    char lname[20];

    printf("请输入姓名: ");
    for (int i = 0; i < CSIZE; i++) {
        if (scanf("%s %s", fname, lname) == 2)
        {
            while (getchar() != '\n')
                continue;

            if (strcmp(fname, p[i]->name.fname) == 0 &&
                strcmp(lname, p[i]->name.lname) == 0)
            {
                for (int j = 0; j < 3; j++)
                {
                    printf("请输入第%d科分数: ", j + 1);
                    scanf("%f", &p[i]->grade[j]);
                }
            }
            else
            {
                printf("该姓名不存在!\n");
                break;
            }
            while (getchar() != '\n')
                continue;
            printf("请输入姓名: ");
        }
    }
    
}

void calc_average(student *p[CSIZE])
{
    float sum = 0;
    int count = 0;

    for (int i = 0; i < CSIZE; i++) {
        for (int j = 0; j < 3; j++)
            if (p[i]->grade[j] >= 0 && p[i]->grade[j] <= 100)
            {
                sum += p[i]->grade[j];
                count++;
            }
        p[i]->average = sum / count;
    }
}

void show_info(student *p[CSIZE])
{
    for (int i = 0; i < CSIZE; i++) {
        printf("姓名: %s %s\n", p[i]->name.fname, p[i]->name.lname);
        for (int j = 0; j < 3; j++)
            printf("分数%d: %.2f\n", j + 1, p[i]->grade[j]);
        printf("平均分: %.2f\n\n", p[i]->average);
    }
}

void show_tot_average(student *p[CSIZE])
{
    float sum = 0;
    int count = 0;

    for (int i = 0; i < CSIZE; i++)
        if (p[i]->average>=0 && p[i]->average<=100) {
            sum += p[i]->average;
            count++;
        }

    printf("班级总平均分: %.2f", sum / count);
}