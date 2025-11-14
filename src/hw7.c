#include "hw7.h"

// HELPERS
int row_col_idx(const matrix_sf *mat, int row, int col)
{
    return row * mat->num_cols + col;
}

// MAIN FUNCTIONS

bst_sf *insert_bst_sf(matrix_sf *mat, bst_sf *root)
{
    return NULL;
}

matrix_sf *find_bst_sf(char name, bst_sf *root)
{
    return NULL;
}

void free_bst_sf(bst_sf *root)
{
}

matrix_sf *add_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2)
{
    int rows = mat1->num_rows;
    int cols = mat1->num_cols;
    matrix_sf *res = malloc(sizeof(matrix_sf) + rows * cols * sizeof(int));
    res->num_rows = rows;
    res->num_cols = cols;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            res->values[row_col_idx(res, y, x)] = mat1->values[row_col_idx(mat1, y, x)] +
                                                  mat2->values[row_col_idx(mat2, y, x)];
        }
    }

    return res;
}

matrix_sf *mult_mats_sf(const matrix_sf *mat1, const matrix_sf *mat2)
{
    int rows = mat1->num_rows;
    int cols = mat2->num_cols;
    int inner = mat1->num_cols; // or mat2->num_rows, equal
    matrix_sf *res = malloc(sizeof(matrix_sf) + rows * cols * sizeof(int));
    res->num_rows = rows;
    res->num_cols = cols;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            for (int k = 0; k < inner; k++)
            {
                res->values[row_col_idx(res, y, x)] += mat1->values[row_col_idx(mat1, y, k)] *
                                                       mat2->values[row_col_idx(mat2, k, x)];
            }
        }
    }

    return res;
}

matrix_sf *transpose_mat_sf(const matrix_sf *mat)
{
    int rows = mat->num_rows;
    int cols = mat->num_cols;
    matrix_sf *res = malloc(sizeof(matrix_sf) + rows * cols * sizeof(int));
    res->num_rows = cols;
    res->num_cols = rows;

    for (int y = 0; y < rows; y++)
    {
        for (int x = 0; x < cols; x++)
        {
            res->values[row_col_idx(res, x, y)] = mat->values[row_col_idx(mat, y, x)];
        }
    }

    return res;
}

matrix_sf *create_matrix_sf(char name, const char *expr)
{
    return NULL;
}

char *infix2postfix_sf(char *infix)
{
    return NULL;
}

matrix_sf *evaluate_expr_sf(char name, char *expr, bst_sf *root)
{
    return NULL;
}

matrix_sf *execute_script_sf(char *filename)
{
    return NULL;
}

// This is a utility function used during testing. Feel free to adapt the code to implement some of
// the assignment. Feel equally free to ignore it.
matrix_sf *copy_matrix(unsigned int num_rows, unsigned int num_cols, int values[])
{
    matrix_sf *m = malloc(sizeof(matrix_sf) + num_rows * num_cols * sizeof(int));
    m->name = '?';
    m->num_rows = num_rows;
    m->num_cols = num_cols;
    memcpy(m->values, values, num_rows * num_cols * sizeof(int));
    return m;
}

// Don't touch this function. It's used by the testing framework.
// It's been left here in case it helps you debug and test your code.
void print_matrix_sf(matrix_sf *mat)
{
    assert(mat != NULL);
    assert(mat->num_rows <= 1000);
    assert(mat->num_cols <= 1000);
    printf("%d %d ", mat->num_rows, mat->num_cols);
    for (unsigned int i = 0; i < mat->num_rows * mat->num_cols; i++)
    {
        printf("%d", mat->values[i]);
        if (i < mat->num_rows * mat->num_cols - 1)
            printf(" ");
    }
    printf("\n");
}
