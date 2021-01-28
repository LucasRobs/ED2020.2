#include <stdio.h>
#include <stdlib.h>

int somatorioRec(int n) {
    if(n==0) return 0;
    else return n + somatorioRec(n-1);
}

int main() {
    int n = 0;
    scanf("%d", &n );
    printf("%d", somatorioRec(n));
    return 0;
}
