#include <stdio.h>
#include <stdlib.h>

double *criarListaSequencial(int n)
{
   return (double *)malloc(n * sizeof(double));
}

void desalocarLista(double *L)
{
   free(L);
}

int adicionaLista(double *L, int *cardinalidade, int tamanho, double x)
{
   if (*cardinalidade == tamanho)
      return 0;
   else
   {
      L[*cardinalidade] = x; // *(L+cardinalidade) = x
      (*cardinalidade)++;
      return 1;
   }
}

int buscaLista(double *L, int cardinalidade, double x)
{
   for (int i = 0; i < cardinalidade; i++)
      if (L[i] == x)
         return i;
   return -1;
}

int removeLista(double *L, int *cardinalidade, double x)
{
   int i = buscaLista(L, *cardinalidade, x);

   if (i > -1)
   {
      (*cardinalidade)--;
      L[i] = L[*cardinalidade];
   }
   return i;
}

void imprimir(double *L, int cardinalidade)
{
   if(cardinalidade == 0) printf("vazio");
   for (int i = 0; i < cardinalidade; i++)
      printf("%.0lf ", L[i]);
   printf("\n");
}

void rmall(double *L, int *cardinalidade, int index)
{
   for (int i = 0; i < *cardinalidade; i++){
      if (L[i] == index){
         *cardinalidade -= 1;
         for (int j = i; j < *cardinalidade; j++){
            L[j] = L[j + 1];
         }
         i=0;
      }
   }
}

int main()
{
   int tamanho = 999, cardinalidade = 0;
   double *LS = NULL;
   int x = 0;
   LS = criarListaSequencial(tamanho);
   scanf("%d", &x);
   while (x != -1)
   {
      adicionaLista(LS, &cardinalidade, tamanho, x);
      scanf("%d", &x);
   }
   scanf("%d", &x);

   rmall(LS, &cardinalidade, x);
   imprimir(LS, cardinalidade);
   desalocarLista(LS);
   return 0;
}