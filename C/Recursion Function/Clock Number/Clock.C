#include <stdio.h>

typedef struct {
    int h, m, s;
} Time;

int main(void) {
    Time t1, t2;
    scanf("%d %d %d", &t1.h, &t1.m, &t1.s);
    scanf("%d %d %d", &t2.h, &t2.m, &t2.s);

    int sec1 = t1.h*3600 + t1.m*60 + t1.s;
    int sec2 = t2.h*3600 + t2.m*60 + t2.s;
    int d = sec2 - sec1;

    int H = d / 3600; d %= 3600;
    int M = d / 60;
    int S = d % 60;

    printf("%d %d %d\n", H, M, S);
    return 0;
}
