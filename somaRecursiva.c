
#include <stdio.h>
#include <conio.h>
double fatorial(int n);
int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d",soma(n));
}

int soma (int numero){
    if (numero == 1 ){
        return (1);
    }
    else {
        return (numero + soma(numero-1));
    }
}
