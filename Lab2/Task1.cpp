#include <iostream>
#include <iomanip>
#include <time.h>

int* getRandArray(int size, int maxValue);

int** getRandMatrix(int size, int maxValue);

void printArray(int* arr, int size);

void printMatrix(int** matrix, int size);

void right_diagonal(int **matrix, int *array, int size);

void left_diagonal(int **matrix, int *array, int size);

void spiral_central(int **matrix, int *array, int size);

void spiral_left_top(int **matrix, int *array, int size);

int main()
{
    srand(time(NULL));
    int size = 4;
    int maxValue = 100;
    int **matrix = getRandMatrix(size, maxValue);
    int *array_D = getRandArray(size * size, 1);
    std::cout << "Матрица\n";
    printMatrix(matrix, size);
    std::cout << "\n\nМассив, до заполнения\n";
    printArray(array_D, size * size);
    std::cout << "\n\nМассив, заполненный по правой диагонали\n";
    right_diagonal(matrix, array_D, size);
    std::cout << "\n\nМассив, заполненный по левой диагонали\n";
    left_diagonal(matrix, array_D, size);
    std::cout << "\n\nМассив, заполненный с центра по спирали\n";
    spiral_central(matrix, array_D, size);
    std::cout << "\n\nМассив, заполенный по спирали сверху\n";
    spiral_left_top(matrix, array_D, size);
    std::cout << "\n";
    for (int i = 0; i < size; i++)
    {
        delete matrix[i];
    }
    delete matrix;
    delete array_D;
    return 0;
}

int* getRandArray(int size, int maxValue)
{
    int* array = new int[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % maxValue;
    }
    return array;
}

int** getRandMatrix(int size, int maxValue)
{
    int** matrix = new int*[size];
    for (int i = 0; i < size; i++)
    {
        matrix[i] = getRandArray(size, maxValue);
    }
    return matrix;
}

void printArray(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << std::setw(2) << arr[i] << " ";
    }
    std::cout << "\n";
}

void printMatrix(int** matrix, int size)
{
    for (int i = 0; i < size; i++)
    {
        printArray(matrix[i], size);
    }
}

void right_diagonal(int **matrix, int *array, int size)
{
    int col, row;
    int stat = 0;
    for (int diag = size - 1; diag >= 0; diag--)
    {
        col = diag;
        row = 0;
        while (col < size && row < size)
        {
            array[stat++] = matrix[row][col];
            row++;
            col++;
        }
    }
    for (int diag = 1; diag < size; diag++)
    {
        col = 0;
        row = diag;
        while (col < size && row < size)
        {
            array[stat++] = matrix[row][col];
            row++;
            col++;
        }
    } 
    printArray(array, size * size);
}

void left_diagonal(int **matrix, int *array, int size)
{
    int col, row;
    int stat = 0;
    for (int diag = 0; diag < size; diag++)
    {
        col = diag;
        row = 0;
        while (col < size && row < size && col >= 0 && row >= 0)
        {
            array[stat++] = matrix[row][col];
            row++;
            col--;
        }
    }
    for (int diag = 1; diag < size; diag++)
    {
        col = size - 1;
        row = diag;
        while (col < size && row < size && row >= 0 && col >= 0)
        {
            array[stat++] = matrix[row][col];
            row++;
            col--;
        }
    }
    printArray(array, size * size);
}

void spiral_central(int **matrix, int *array, int size)
{
    int j, k;
    int stat = size * size - 1;
    int p = size / 2;
    for (k = 1; k <= p; k++)
    {
        for (j = k - 1; j < size - k + 1; j++)
        {
            array[stat--] = matrix[k - 1][j];
        }
        for (j = k; j < size - k + 1; j++)
        {
            array[stat--] = matrix[j][size - k];
        }
        for (j = size - k - 1; j >= k - 1; j--)
        {
            array[stat--] = matrix[size - k][j];
        }
        for (j = size - k - 1; j >= k; j--)
        {
            array[stat--] = matrix[j][k - 1];
        }
        array[stat] = matrix[j + 1][k];
    }
    printArray(array, size * size);
}

void spiral_left_top(int **matrix, int *array, int size)
{
    int j, k;
    int stat = 0;
    int p = size / 2;
    for (k = 1; k <= p; k++)
    {
        for (j = k - 1; j < size - k + 1; j++)
        {
            array[stat++] = matrix[k - 1][j];
        }
        for (j = k; j < size - k + 1; j++)
        {
            array[stat++] = matrix[j][size - k];
        }
        for (j = size - k - 1; j >= k - 1; j--)
        {
            array[stat++] = matrix[size - k][j];
        }
        for (j = size - k - 1; j >= k; j--)
        {
            array[stat++] = matrix[j][k - 1];
        }
        array[stat] = matrix[j + 1][k];
    }
    printArray(array, size * size);
}