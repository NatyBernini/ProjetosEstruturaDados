#include <stdio.h>
#include <stdlib.h>

typedef struct item{
    int id;
    struct item *prox;
}node;

void criaPilha(node *pilha){
    pilha->prox = NULL;
}

int vazia(node pilha){
    if(pilha.prox == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(node *pilha, int id){
    node *novo = (node*) malloc(sizeof(node));

    if(novo==NULL){
        printf("Sem memoria disponivel");
    }else{
        novo->id = id;
        novo->prox = NULL;
        if(vazia(*pilha)==1){
            pilha->prox = novo;
        }else{
            node *aux = pilha->prox;
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = novo;
        }
    }
}

node* pop(node *pilha){
    if(vazia(*pilha)==1){
        //printf("A pilha esta vazia!");
        return NULL;
    }else{
        node *ultimo = pilha->prox;
        node *penultimo = pilha;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        penultimo->prox = NULL;
        return ultimo;
            
    }
}

void imprimir(node pilha){
    if(vazia(pilha)==1){
        printf("A pilha esta vazia");
    }else{
        node *aux = pilha.prox;
        printf("Elementos da Pilha:\n");
        while(aux != NULL){
            printf("%d\n", aux->id);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void zerar(node *pilha){
    if(vazia(*pilha)==0){
        node *prox, *atual;
        atual = pilha->prox;

        while(atual != NULL){
            prox = atual->prox;
            free(atual);
            atual = prox;
        }
        criaPilha(pilha);
    }
}

void inverter(node *pilha){
    if(vazia(*pilha)==1){
        printf("A pilha está vazia!");
    }else {
        node pilhaAux;
        criaPilha(&pilhaAux);
        while(vazia(*pilha)!=1){
            node *aux = pilha->prox;
            node *ant = pilha;
            while(aux != NULL){ 
                ant = aux;
                aux = aux->prox;
            }
            //printf("%d", ant->id);
           push(&pilhaAux, ant->id);
           pop(pilha);
        }
        node *temp = pilhaAux.prox;
        while(temp != NULL){
            push(pilha, temp->id);
            temp = temp->prox;
        }
        zerar(&pilhaAux);
    }
}

int main()
{

    node pilha;

    criaPilha(&pilha);

    push(&pilha, 1);
    push(&pilha, 2);
    push(&pilha, 3);
    push(&pilha, 4);
    push(&pilha, 5);

    printf("Impressao sem inverter.\n");
    imprimir(pilha);

    inverter(&pilha);
    printf("Impressao apos inverter.\n");
    imprimir(pilha);
    return 0;
}
