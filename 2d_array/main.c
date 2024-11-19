#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define EXIT_SUCCESS 0
#define TRUE 1
#define MAX_COLS 20
#define MAX_ROWS 20

/**
 * Nhập giá trị kích thước không vượt quá max_val
 */
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

/**
 * Nhập ma trận
 */
void matrix_input(int matrix[][MAX_ROWS], int *n_rows, int *n_cols)
{
    printf("Number of rows: ");
    *n_rows = size_input(MAX_ROWS);

    printf("Number of columns: ");
    *n_cols = size_input(MAX_COLS);

    for (int i = 0; i < *n_rows; i++)
    {
        for (int j = 0; j < *n_cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

/**
 * Nhập ma trận với các giá trị được sinh ngẫu nhiên
 */
void matrix_random_input(int matrix[][MAX_ROWS], int *n_rows, int *n_cols)
{
    printf("Number of rows: ");
    *n_rows = size_input(MAX_ROWS);

    printf("Number of columns: ");
    *n_cols = size_input(MAX_COLS);

    int from, to;
    printf("From value: ");
    scanf("%d", &from);
    printf("To value: ");
    scanf("%d", &to);

    srand(time(NULL));

    for (int i = 0; i < *n_rows; i++)
    {
        for (int j = 0; j < *n_cols; j++)
        {
            // matrix[i][j] = rand() % 100; // from 0 to 100
            matrix[i][j] = from + rand() % (to - from + 1); // inclusive range [from, to]
        }
    }
}

/**
 * Xuất ma trận
 */
void matrix_output(int matrix[][MAX_ROWS], int n_rows, int n_cols)
{
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        puts("");
    }
}

/**
 * Chép toàn bộ nội dung từ dòng source tới dòng đích
 */
void copy_entire_row(int matrix[][MAX_COLS], int n_rows, int n_cols, int source_row, int des_row)
{
    if (source_row < 0 || source_row >= n_rows || des_row < 0 || des_row >= n_rows)
    {
        return;
    }

    for (int i = 0; i < n_cols; i++)
    {
        matrix[des_row][i] = matrix[source_row][i];
    }
}

/**
 * Chép toàn bộ nội dung từ cột source tới cột đích
 */
void copy_entire_column(int matrix[][MAX_COLS], int n_rows, int n_cols, int source_col, int des_col)
{
    if (source_col < 0 || source_col >= n_cols || des_col < 0 || des_col >= n_cols)
    {
        return;
    }

    for (int i = 0; i < n_rows; i++)
    {
        matrix[i][des_col] = matrix[i][source_col];
    }
}

int main()
{
    int matrix[MAX_COLS][MAX_ROWS];
    int n, m;

    matrix_input(matrix, &n, &m);
    matrix_output(matrix, n, m);
    copy_entire_column(matrix, n, m, 0, 2);
    puts("");
    matrix_output(matrix, n, m);

    return EXIT_SUCCESS;
}