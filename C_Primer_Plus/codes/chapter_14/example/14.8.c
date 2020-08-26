// 使用指向结构的指针
#include <stdio.h>
#include <string.h>

#define NLEN 30

struct namect {
    char fname[NLEN];
    char lname[NLEN];
    int letters;
};

void getinfo(struct namect *pst);
void makeinfo(struct namect *pst);
void showinfo(const struct namect *pst);
char *s_gets(char *st, int n);

int main(void)
{
    struct namect person;

    getinfo(&person);
    makeinfo(&person);
    showinfo(&person);

    return 0;
}

void getinfo(struct namect *pst)
{
    printf("请输入你的姓: ");
    s_gets(pst->fname, NLEN);
    printf("请输入你的名: ");
    s_gets(pst->lname, NLEN);
}

void makeinfo(struct namect *pst)
{
    pst->letters = strlen(pst->fname) + strlen(pst->lname);
}

void showinfo(const struct namect *pst)
{
    printf("%s %s, 你的名字有%d个字符\n",
           pst->fname, pst->lname, pst->letters);
}

char *s_gets(char *st, int n)
{
    char *ret_val = NULL;
    char *find = NULL;

    ret_val = fgets(st, n, stdin);

    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar()!='\n')
                continue;
    }

    return ret_val;
}