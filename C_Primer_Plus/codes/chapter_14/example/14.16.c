// 使用函数指针
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LEN 81

char *s_gets(char *st, int n);
char showmenu(void);
void eatline(void);         // 读取至行末尾
void show(void (*fp)(char *), char *str);
void ToUpper(char *);       // 转为大写
void ToLower(char *);       // 转为小写
void Transpose(char *);     // 大小写反转
void Dummy(char *);         // 不更改字符串

int main(void)
{
    char line[LEN];
    char copy[LEN];
    char choice;
    void (*pfun)(char *) = NULL;   // 指向函数的指针

    puts("请输入一个字符串(输入空行退出):");
    while (s_gets(line, LEN) != NULL && line[0] != '\0') {
        while ((choice = showmenu()) != 'n') {
            switch (choice) {
                case 'u':
                    pfun = ToUpper;
                    break;
                case 'l':
                    pfun = ToLower;
                    break;
                case 't':
                    pfun = Transpose;
                    break;
                case 'o':
                    pfun = Dummy;
                    break;
            }
            strcpy(copy, line);
            show(pfun, copy);
        }
        puts("请输入一个字符串(输入空行退出):");
    }
    puts("Bye!");
    
    return 0;
}

void eatline(void)
{
    while (getchar() !='\n')
        continue;
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
            eatline();
        }

    return ret_val;
}

char showmenu(void)
{
    char choice;

    puts("请选择下面的功能: ");
    printf("u) uppercase        l) lowercase\n");
    printf("t) transposed case  o) original case\n");
    printf("n) next string\n");

    choice = getchar();
    choice = tolower(choice);
    eatline();

    while (strchr("ulton", choice) == NULL) {
        printf("请输入有效的选项!\n");
        choice = tolower(getchar());
        eatline();
    }

    return choice;
}

void ToUpper (char *st)
{
    while (*st) {
        *st = toupper(*st);
        st++;
    }
}

void ToLower(char *st)
{
    while (*st) {
        *st = tolower(*st);
        st++;
    }
}

void Transpose(char *st)
{
    while (*st) {
        if (islower(*st))
            *st = toupper(*st);
        else if (isupper(*st))
            *st = tolower(*st);
        st++;
    }
}

void Dummy(char *st)
{
    // 不改变字符串
}

void show(void (*fp)(char *), char *str)
{
    (*fp)(str);
    puts(str);
}