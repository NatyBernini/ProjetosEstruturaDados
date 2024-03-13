#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
}TipoItem;

typedef struct celula *apontador;

typedef struct celula{
    TipoItem item;
    apontador *prox;
}celula;

typedef struct{
    apontador primeiro, ultimo;
}TipoLista;

void criar(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula)); // Aloca espaço na memória para a célula cabeça
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    lista->ultimo->prox = (apontador) malloc(sizeof(celula));
    lista->ultimo = lista->ultimo->prox;
    lista->ultimo->prox = NULL;
    lista->ultimo->item = item;
}

void excluir(TipoLista *lista, int idItem){
    if (vazia(*lista)==1){
        printf("A lista está vazia");
    }else{
        apontador anterior, atual;
        anterior = lista->primeiro;
        atual = lista->primeiro->prox; // Ou atual = anterior -> prox
        while(atual != NULL){
            if(atual->item.id == idItem){
                anterior->prox = atual->prox;
                free(atual);
                break;
            }
            anterior = atual;
            atual = atual->prox;
        }
    }
}

void imprimir(TipoLista lista){
    if(vazia(lista)==1){
        printf("A lista esta vazia!!!");
    }else{
        apontador aux = lista.primeiro->prox;
        while(aux!=NULL){
            printf("[%d] ", aux->item.id);
            aux = aux->prox;
        }
    }
}

int main()
{
    TipoLista lista;
    TipoItem item;

    criar(&lista);

    item.id = 1;
    inserirFinal(&lista, item);

    item.id = 2;
    inserirFinal(&lista, item);

    item.id = 3;
    inserirFinal(&lista, item);


    item.id = 4;
    inserirFinal(&lista, item);


    item.id = 5;
    inserirFinal(&lista, item);

    imprimir(lista);

    excluir(&lista, 3);

    imprimir(lista);
    return 0;
}
