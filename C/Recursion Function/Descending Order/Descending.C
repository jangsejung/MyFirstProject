#include <stdio.h>
#include <stdlib.h>

void ABC(int arr[], int k)
{
    int Max = k;
    for(int i = k; i < 10; i++){
        if(arr[i] > arr[Max]) 
            Max = i;
    }
    int tmp = arr[k];
    arr[k] = arr[Max];
    arr[Max] = tmp;
}

int main()
{
    int arr[10];
    for (int i = 0; i <10; i++)
    scanf("%d", &arr[i]);
    for (int k = 0; k <9; k++)
    ABC(arr, k);
    for(int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
    return 0;
}