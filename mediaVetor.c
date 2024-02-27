#include <stdio.h>
#include <stdlib.h>

int main()
{
    int tamanhoVetor, numero;
    float soma;
    soma = 0;
    printf("Informe a quantidade de números que serão usados para a média: ");
    scanf("%d", &tamanhoVetor);
    int vetor[tamanhoVetor];

    for (int c = 0; c < tamanhoVetor; c++){
        printf("Informe um número: ");
        scanf("%d", &numero);
        vetor[c] = numero;
        soma += numero;
    };

    printf("A média é %.2f", (soma/tamanhoVetor));

    free(vetor);
    return 0;
}
