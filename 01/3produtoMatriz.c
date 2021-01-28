#include <stdio.h>
#include <stdlib.h>

void ler(int **M, int nlin, int ncol)
{
    for (int i = 0; i < nlin; i++)
    {
        for (int j = 0; j < ncol; j++)
            scanf("%d", &M[i][j]);
    }
}

void imprimir(int **M, int nlin, int ncol)
{
    for (int i = 0; i < nlin; i++)
    {
        for (int j = 0; j < ncol - 1; j++)
            printf("%d ", M[i][j]);
        printf("%d\n", M[i][ncol - 1]);
    }
}

int** getProduto(int **M1, int **M2, int nlin, int ncol){
    int **M = NULL;
    M = (int **)malloc(nlin * sizeof(int *));
    for (int i = 0; i < nlin; i++)
        M[i] = (int *)malloc(ncol * sizeof(int));

    for (int l = 0; l < nlin; l++)
        for (int c = 0; c < ncol; c++)
            for(int i = 0; i < ncol; i++)
                M[l][c] += M1[l][i] * M2[i][c];
    return M;
}

int main()
{

    int nlin = 0, ncol = 0;

    scanf("%d", &nlin);
    ncol = nlin;

    int **M1 = NULL;
    M1 = (int **)malloc(nlin * sizeof(int *));
    for (int i = 0; i < nlin; i++)
        M1[i] = (int *)malloc(ncol * sizeof(int));

    int **M2 = NULL;
    M2 = (int **)malloc(nlin * sizeof(int *));
    for (int i = 0; i < nlin; i++)
        M2[i] = (int *)malloc(ncol * sizeof(int));

    ler(M1, nlin, ncol);
    ler(M2, nlin, ncol);
    imprimir(getProduto(M1, M2, nlin, ncol), nlin, ncol);

    for (int i = 0; i < nlin; i++)
        free(M1[i]);
    free(M1);
    for (int i = 0; i < nlin; i++)
        free(M2[i]);
    free(M2);

    return 0;
}