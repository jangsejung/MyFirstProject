#include <stdio.h>
#include <string.h>

int main(void) {
    char s[101];
    if (scanf("%100s", s) != 1) return 0;

    int len = (int)strlen(s);
    char ss[202];
    strcpy(ss, s);
    strcat(ss, s);

    printf("%s\n", s);
    for (int i = 1; i < len; i++) {
        char save = ss[i + len];
        ss[i + len] = '\0';
        printf("%s\n", ss + i);
        ss[i + len] = save;
    }
    return 0;
}
