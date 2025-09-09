#include <stdio.h>
#include <stdlib.h>

void Hanoi(int n, char from, char temp, char to)
{
    if (n == 1)
    {
        printf("Disk %d : Move %c to %c\n", n, from, to);
    }

    else
    {
        Hanoi(n-1, from, temp, to);
        printf("Disk %d : Move %c to %c\n", n, from, to);
        Hanoi(n-1, from, temp, to);
    }
}

int main()
{
    Hanoi(3, 'A', 'B', 'C');

    return 0;
}