#include <stdio.h>
#include <stdlib.h>
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
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

void enfileirar(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==0){
        lista->ultimo->prox = (apontador) malloc(sizeof(celula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->prox = NULL;
        lista->ultimo->item = item;
    }
}

int buscar(TipoLista lista, int id){ // Função que retorna a posição do item
    apontador aux;
    aux = lista.primeiro->prox;
    while(aux!=NULL){
        if(aux->item.id == id)
            return aux;
        aux = aux->prox;
    }
    return 0;
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

void desenfileirar(TipoLista *lista){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador atual;
        atual = lista->primeiro->prox;
        lista->primeiro->prox = atual->prox;
        free(atual);
    }
}

void zerar(TipoLista *lista){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador atual, temp;
        atual = lista->primeiro->prox;
        printf("\nTerceira impressao zerando a lista: \n");
        while(lista->primeiro->prox!=NULL){
           lista->primeiro->prox = atual->prox;
           temp = atual;
           free(temp);
           atual = atual->prox;
           imprimir(*lista);
           printf("-\n");
        };
        //lista->primeiro->prox = atual;
        lista->primeiro = lista->ultimo;

    }
}

int main()
{
    TipoLista lista;
    TipoItem item;

    criar(&lista);

    item.id = 1;
    enfileirar(&lista, item);

    item.id = 2;
    enfileirar(&lista, item);

    item.id = 3;
    enfileirar(&lista, item);

    item.id = 4;
    enfileirar(&lista, item);

    item.id = 5;
    enfileirar(&lista, item);

    item.id = 6;
    enfileirar(&lista, item);

    item.id = 7;
    enfileirar(&lista, item);

    printf("Primeira impressao lista completa: \n");
    imprimir(lista);
    printf("\n");

    desenfileirar(&lista);
    printf("\nSegunda impressao removendo o primeiro item: \n");
    imprimir(lista);
    printf("\n");

    zerar(&lista);
    printf("\nQuarta impressao: \n");
    imprimir(lista);


    return 0;
}
