#include <stdio.h>
#include <stdlib.h>

int arr[20];
int Max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int rPrint(int n)
{
    
    if (n == 1)
        return Max(arr[0], arr[1]);
    else 
    {
        return Max(rPrint(n-1), arr[n]);
    }
}

int main()
{
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++ )
    {
        scanf("%d", &arr[i]);
    }

    printf("Max : %d", rPrint(N - 1));
}