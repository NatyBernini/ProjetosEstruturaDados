#include <stdio.h>
#include <stdlib.h>

int elevaQuadrado(int k, int n){
    if (n == 1){
        return(1);
    } else {
        return( k * (elevaQuadrado(k, n - 1)));
    }
}

int main()
{
    int k, n;
    printf("Primeiro número: ");
    scanf("%d", &k);

    printf("Segundo número: ");
    scanf("%d", &n);

    printf("%d elevado a %d é %d", k, n, elevaQuadrado(k,n));
    return 0;
}
