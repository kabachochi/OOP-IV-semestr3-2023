#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getRandArray(int size, int maxValue);

void print(int *arr);

int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int *arr = getRandArray(size, maxValue);
    print(arr);
    free(arr);
    return 0;
}

int* getRandArray(int size, int maxValue)
{
    int* array = malloc(sizeof(int) * (size + 1));
    array[0] = size;
    for (int i = 1; i <= size; i++)
    {
        array[i] = rand() % maxValue;
    }
    return array;
}

void print(int* arr)
{
    if (arr[0] == 0)
    {
        arr[0] = 1;
    }
    printf("%d: ", arr[0] - 1);
    for (int i = 1; i < arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}