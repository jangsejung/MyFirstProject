#include <stdio.h>
#include <stdlib.h>

int sum(int n){
    int s = 0;
    for(int i = 1; i <= n; i++)
    s = s + i;
    return s;
}

int main() {
    int x, total = 0;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++)
    total = sum(i) + total;
    printf("%d\n", total);
    return 0;
}