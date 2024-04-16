#include <stdio.h>
#include <stdlib.h>


// FUNÇÃO QUE ORDENA O VETOR EM ORDEM DECRESCENTE
void ordenaVetorDec(int *vetor){
    int aux;
    for(int i=0; i<13; i++){
         for(int c=0; c<=i; c++){
            if(vetor[i]<vetor[c]){
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }
            if(vetor[i]>vetor[c]){
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }
         }
    }
}

// FUNÇÃO QUE ORDENA O VETOR EM ORDEM CRESCENTE
void ordenaVetorCre(int *vetor){
    int aux;
    for(int i=0; i<13; i++){
         for(int c=0; c<=i; c++){
            if(vetor[i]>vetor[c]){
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }

            if(vetor[i]<vetor[c]){
                aux = vetor[i];
                vetor[i] = vetor[c];
                vetor[c] = aux;
            }

         }
    }
}

// FUNÇÃO PARA IMPRIMIR O VETOR
void imprimeVetor(int vetor[]){ 
    for(int i=0; i<13; i++){
            printf("%d ", vetor[i]);
    }
}


int main()
{

    int vetor[13];

    vetor[0] = 10;
    vetor[1] = 4;
    vetor[2] = 8;
    vetor[3] = 7;
    vetor[4] = 11;
    vetor[5] = 1;
    vetor[6] = 15;
    vetor[7] = 3;
    vetor[8] = 5;
    vetor[9] = 4;
    vetor[10] = 2;
    vetor[11] = 12;
    vetor[12] = 6;

    ordenaVetorCre(&vetor);

   imprimeVetor(vetor);
}
