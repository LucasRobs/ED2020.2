#include <stdio.h>
#include <stdlib.h>

struct NODE
{
  int chave;
  struct NODE *prox;
};

typedef struct NODE NO;

struct ListaEncadeada
{
  NO cabeca;
  int card; // Quantidade de elementos na Lista
};
typedef struct ListaEncadeada ListaEnc;

ListaEnc criarLista()
{
  ListaEnc L;
  L.card = 0;
  L.cabeca.prox = NULL;

  return L;
}

NO *buscar(ListaEnc L, int x)
{
  NO *p = L.cabeca.prox;
  while (p != NULL)
    if (p->chave == x)
      return p;
  return NULL;
}

int get(ListaEnc L, int x)
{
  NO *p = L.cabeca.prox;
  for(int i = 0; i < x;i++)
    p = p->prox;
  return p->chave;
}

void pintar(ListaEnc L)
{
  NO *p = L.cabeca.prox;
  if(L.cabeca.prox==NULL)
    printf("vazia");
  while (p != NULL){
    printf("%d ", p->chave);
    p = p->prox;
  }
}

int rm(ListaEnc L, int x)
{
  NO *p = &(L.cabeca);

  while (p->prox != NULL)
    if (p->prox->chave == x)
    {
      NO *r = p->prox;
      p->prox = p->prox->prox;
      free(r);
      return 1;
    }
    else
      p = p->prox;

  return 0;
}

ListaEnc incluir(ListaEnc L, int x)
{
  NO *novo = NULL;

  novo = (NO *)malloc(sizeof(NO));
  novo->chave = x;
  novo->prox = L.cabeca.prox;
  L.cabeca.prox = novo;
  (L.card)++;
  return L;
}

ListaEnc rmAll(ListaEnc L1, int index)
{
  ListaEnc p = criarLista();

  for(int i = 0; i < L1.card;i++){
    if(get(L1,i) != index)
      p = incluir(p, get(L1,i));
  }
  return p;
}

ListaEnc conc(ListaEnc L1, ListaEnc L2)
{
  ListaEnc p = criarLista();

  for(int i = 0; i < L2.card;i++){
    p = incluir(p, get(L2,i));
  }
  for(int i = 0; i < L1.card;i++){
    p = incluir(p, get(L1,i));
  }
  return p;
}

int main()
{
  ListaEnc L1 = criarLista();
  ListaEnc LF = criarLista();

  int x = 0;

  scanf("%d", &x);
  while (x != -1)
  {
    L1 = incluir(L1, x);
    scanf("%d", &x);
  }
  scanf("%d", &x);
  LF = rmAll(L1, x);
  pintar(LF);
  return 0;
}
