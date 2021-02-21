#include <stdio.h>
#include <stdlib.h>
int x = 0;
int pell(int n) {
   x++;
    if(n==0) return 0;
    if(n==1) return 1;
    else return 2 * pell(n - 1) + pell(n-2);
}

int main() {
    int n = 0;
    scanf("%d", &n );
    printf("%d %d", x, pell(n));
    return 0;
}
