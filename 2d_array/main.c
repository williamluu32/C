#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define TRUE 1
#define MAX_COLS 20
#define MAX_ROWS 20

int size_input(int max_val)
{
    int size;
    while (TRUE)
    {
        scanf("%d", &size);
        if (size < 1 || size > max_val)
            puts("Invalid value.");
        else
            break;
    }
    return size;
}

void matrix_input(int matrix[][MAX_ROWS], int *n, int *m)
{
    printf("Number of rows: ");
    *n = size_input(MAX_ROWS);

    printf("Number of columns: ");
    *m = size_input(MAX_COLS);

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void matrix_random_input(int matrix[][MAX_ROWS], int *n, int *m)
{
    printf("Number of rows: ");
    *n = size_input(MAX_ROWS);

    printf("Number of columns: ");
    *m = size_input(MAX_COLS);

    int from, to;
    printf("From value: ");
    scanf("%d", &from);
    printf("To value: ");
    scanf("%d", &to);

    srand(time(NULL));

    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *m; j++)
        {
            // matrix[i][j] = rand() % 100; // from 0 to 100
            matrix[i][j] = from + rand() % (to - from + 1); // inclusive range [from, to]
        }
    }
}

void matrix_output(int matrix[][MAX_ROWS], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

int main()
{
    int matrix[MAX_COLS][MAX_ROWS];
    int n_cols, n_rows;

    matrix_random_input(matrix, &n_cols, &n_rows);
    matrix_output(matrix, n_cols, n_rows);

    return EXIT_SUCCESS;
}