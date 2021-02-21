#include <stdio.h>
#include <stdlib.h>

void ChosenPivotPartition(int* Vector, int size, int pivo){
    for(int i = 0; i < size; i++){
        if(Vector[i] > Vector[pivo] && i < pivo){
            int aux = Vector[i];
            for(int j = i; j < pivo;j++){
                Vector[j] = Vector[j+1];
            }
            Vector[pivo] = aux;
            pivo--;
            i=0;
        }else if(Vector[i] < Vector[pivo] && i > pivo){
            int aux = Vector[i];
            for(int j = i; j > pivo;j--){
                Vector[j] = Vector[j-1];
            }
            Vector[pivo] = aux;
            pivo++;
            i=0;
        }
    }
}

int main() {
   int size=0, pivo=0;

   scanf("%d %d",&size ,&pivo);

    int* vector = (int *) malloc(size*sizeof(int)); 

    for(int i = 0; i < size; i++)
        scanf("%d", &vector[i] );

    ChosenPivotPartition(vector,size, pivo);

    for(int i = 0; i < size; i++)
        printf("%d ", vector[i]);
    

   return 0;
}