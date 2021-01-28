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



int calcularLinhaDoMax(int **M, int nlin, int ncol){
    int max = 0;
    int linha = 0;
    for (int i = 0; i < nlin; i++)
        for (int j = 0; j < ncol - 1; j++)
            if(M[i][j] > max){
                linha = i;
                max = M[i][j];
            }
    return linha;
}

int calcularMinDaLinha(int linha, int **M, int ncol){
    int min = 999999;
    for (int j = 0; j < ncol; j++)
        if(M[linha][j] < min)
            min = M[linha][j];
    return min;
}

int main(){
    int nlin = 0, ncol = 0;

    scanf("%d %d", &nlin, &ncol);

    int **M = NULL;
    M = (int **)malloc(nlin * sizeof(int *));
    for (int i = 0; i < nlin; i++)
        M[i] = (int *)malloc(ncol * sizeof(int));

    ler(M, nlin, ncol);
    printf("%d", calcularMinDaLinha(calcularLinhaDoMax(M, nlin, ncol), M, ncol));
    

    for (int i = 0; i < nlin; i++)
        free(M[i]);
    free(M);

    return 0;
}