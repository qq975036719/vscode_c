// BF模式匹配
#include <stdio.h>
#include <string.h>

int StrIndex_BF(char *s, char *t, int pos)
{
    int i = pos;
    int j = 0;
    int s_len = strlen(s);
    int t_len = strlen(t);

    while (i < s_len && j < t_len) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (j>=t_len)
        return (i - t_len);

    return 0;
}

int main(void)
{
    char *s = "hello world!";
    char *t = "wo";

    printf("%d", StrIndex_BF(s, t, 0));

    return 0;
}