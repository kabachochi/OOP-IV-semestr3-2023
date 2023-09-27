#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* getRandArray(int size, int maxValue);

int** getRandMatrix(int size, int maxValue);

void print(int* arr);

void printMatrix(int** matrix);

int main()
{
    srand(time(NULL));
    int size = rand() % 10;
    int maxValue = 100;
    int **matrix = getRandMatrix(size, maxValue);
    printMatrix(matrix);
    for (int i = 0; i < size; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}

int* getRandArray(int size, int maxValue)
{
    int* array = NULL;
    array = malloc(sizeof(int) * (size + 1));
    array[0] = size;
    for (int i = 1; i < size; i++)
    {
        array[i] = rand() % maxValue;
    }
    return array;
}

int** getRandMatrix(int size, int maxValue)
{
    int** matrix = NULL;
    matrix = malloc(sizeof(int*) * (size + 1));
    matrix[0] = malloc(sizeof(int) * 1);
    matrix[0][0] = size;
    for (int i = 1; i <= size; i++)
    {
        int sizestr = rand() % 10;
        if (sizestr == 0)
        {
            sizestr = 1;
        }
        matrix[i] = getRandArray(sizestr, maxValue);
    }
    return matrix;
}

void print(int* arr)
{
    printf("%d: ", arr[0] - 1);
    for (int i = 1; i < arr[0]; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void printMatrix(int** matrix)
{
    int size = matrix[0][0];
    printf("%d\n", size);
    for (int i = 1; i <= size; i++)
    {
        print(matrix[i]);
    }
}