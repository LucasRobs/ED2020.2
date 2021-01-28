#include <stdio.h>
#include <stdlib.h>

int* getMiniMax(int* V, int size){
   int* minMax = (int *) malloc(2*sizeof(int)); 
   int max = -999999, min = 99999;
   for(int i = 0; i < size; i++){
      if(V[i] <= min) min = V[i];
      if(V[i] >= max) max = V[i];
   }
   minMax[0] = min, minMax[1] = max;
   return minMax;
}

int main() {
   int n = 0;
   scanf("%d", &n );
   int* V = (int *) malloc(n*sizeof(int)); 
   for(int i = 0; i < n; i++)
      scanf("%d", &V[i] );
   printf("%d %d", getMiniMax(V, n)[0], getMiniMax(V, n)[1]);
}