#include <stdio.h>
#include <stdlib.h>

struct NODE_
{
  double chave;
  struct NODE_ *prox;
};

typedef struct NODE_ NODE;
int cardinalidade = 0;
NODE *noCabeca = NULL;

int criarLista()
{
  noCabeca = (NODE *)malloc(sizeof(NODE));
  if (noCabeca != NULL)
  {
    noCabeca->chave = 0;
    noCabeca->prox = NULL;
    cardinalidade = 0;
    return 1;
  }
  else
    return 0;
}

int adicionar(double x)
{ // O(1)
  NODE *novo = (NODE *)malloc(sizeof(NODE));

  if (novo != NULL)
  {
    novo->chave = x;
    novo->prox = noCabeca->prox;
    noCabeca->prox = novo;
    cardinalidade++;
    return 1;
  }
  else
    return 0;
}

void imprimir()
{ // O(n)
  NODE *p = noCabeca->prox;
  if (p == NULL)
    printf("vazia");
  while (p != NULL)
  {
    printf("%.0lf ", p->chave);
    p = p->prox;
  }
  printf("\n");
}


int main()
{
  criarLista();
  NODE lista1 = *noCabeca;
  int x = 0;
  scanf("%d", &x);
  while (x != -1)
  {
    adicionar(x);
    scanf("%d", &x);
  }
  criarLista();
  NODE lista2 = *noCabeca;
  int x = 0;
  scanf("%d", &x);
  while (x != -1)
  {
    adicionar(x);
    scanf("%d", &x);
  }

  printf("%d", cardinalidade);
}