#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *V;
  int f;   // índice do último elemento
  int tam; // tamanho: tamanho máximo da lista 
} ListaSeq;

ListaSeq criarLista(int tam) {
   ListaSeq L;
   L.V = (int *) malloc(tam*sizeof(int));
   L.f = -1;
   L.tam = tam;
   return L;
}

ListaSeq incluir(ListaSeq L, int x) {
   if((L.f)+1 < L.tam) {
      (L.f)++;
      L.V[L.f] = x;
   } else printf("Lista cheia! Elemento NÃO incluído!\n");
   return L;
}

int buscar(ListaSeq L, int x) {
   for(int i=0;i<(L.f+1);i++)
      if(L.V[i] == x) return i;
   
   return -1;  // Elemento NÃO encontrado!   
}

int remover(ListaSeq *L, int x) {
    int ind = buscar(*L,x);
    if(ind == -1) return 0;
    else {
	L->V[ind] = L->V[L->f];
        (L->f)--;
        return 1;   // Sucesso na remoção
    }
}

ListaSeq desalocarLista(ListaSeq L) {
    L.f = -1;
    L.tam = 0;
    free(L.V);
    L.V = NULL;
    return L;
}

int main() {
   int tam=0, x=0;
   ListaSeq L;   

   printf("Digite o tamanho da lista: ");
   scanf("%d", &tam);
   L = criarLista(tam);
   for(int i=0;i<tam;i++) L = incluir(L,i+1);
   
   printf("Digite o elemento a ser removido na lista: ");
   scanf("%d", &x);
   int ind = remover(&L,x);
   if(ind == 0) printf("Elemento NÃO encontrado!\n");
   else printf("Elemento removido!\n");

   printf("Digite o elemento a ser pesquisado na lista: ");
   scanf("%d", &x);
   ind = buscar(L,x);
   if(ind == -1) printf("Elemento NÃO encontrado!\n");
   else printf("Elemento está na posição %d!\n", ind);

   L = desalocarLista(L);

   return 0;
}