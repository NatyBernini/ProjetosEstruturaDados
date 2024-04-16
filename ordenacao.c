#include <stdio.h>
#include <stdlib.h>


// FUNÇÃO QUE ORDENA O VETOR EM ORDEM DECRESCENTE
void ordenaVetorDec(int *vetor,  int qtd){
    int aux;
    for(int i=0; i<qtd; i++){
         for(int c=0; c<=i; c++){ // percorre os elementos anteriores ao atual
            if(vetor[i]<vetor[c]){ // verifica se o elemento é menor
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }
            if(vetor[i]>vetor[c]){ // verifica se o elemento é maior
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }
         }
    }
}

// FUNÇÃO QUE ORDENA O VETOR EM ORDEM CRESCENTE
void ordenaVetorCre(int *vetor, int qtd){
    int aux;
    for(int i=0; i<qtd; i++){
         for(int c=0; c<=i; c++){ // percorre os elementos anteriores ao atual
            if(vetor[i]>vetor[c]){ // verifica se o elemento é maior
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }

            if(vetor[i]<vetor[c]){ // verifica se o elemento é menor
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }

         }
    }
}

// FUNÇÃO PARA IMPRIMIR O VETOR
void imprimeVetor(int vetor[], int qtd){
    for(int i=0; i<qtd; i++){
            printf("%d\n", vetor[i]);
    }
}


// FUNÇÃO PARA PREENCHER O VETOR COM VALORES ALEATÓRIOS
void preencheVetor(int *vetor, int qtd){
    int aux;

    for(int i=0;i<qtd;i++){
        aux = rand() % qtd;
        vetor[i] = aux;
    }

}


int main()
{
    int qtd = 100;
    int vetor[qtd];

    preencheVetor(&vetor, qtd);

    ordenaVetorCre(&vetor, qtd);

    imprimeVetor(vetor, qtd);
}
