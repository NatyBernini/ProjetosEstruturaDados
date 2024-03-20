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
    apontador *prox, *ant;
}celula;

typedef struct{
    apontador primeiro, ultimo;
}TipoLista;

void criar(TipoLista *lista){
    lista->primeiro = (apontador) malloc(sizeof(celula));
    lista->primeiro->prox = NULL;
    lista->ultimo = lista->primeiro;
    lista->primeiro->ant = NULL;
}

int vazia(TipoLista lista){
    if(lista.primeiro == lista.ultimo)
        return 1;
    return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==0){
        lista->ultimo->prox = (apontador) malloc(sizeof(celula)); // Cria o próximo
        apontador temp = lista ->ultimo; // Armazena o item antigo
        lista->ultimo = lista->ultimo->prox; // Faz o item antigo receber o novo
        lista->ultimo->ant = temp; // Faz o apontador anterior novo apontar para o item antigo
        lista->ultimo->prox = NULL; //
        lista->ultimo->item = item; //
    }
}

void imprimir(TipoLista lista){
    if(vazia(lista)==1){
        printf("A lista esta vazia!!!");
    }else{
        apontador aux = lista.primeiro->prox;
        while(aux!=NULL){
            printf("|<-[%d]- [%d] -[%d]->| \n", aux->ant,aux->item, aux->prox);
            aux = aux->prox;
        }
    }
}

void remover(TipoLista *lista, int id){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador anterior, atual, proximo;

        atual = lista->primeiro->prox;
        while(atual!=NULL){
            if(atual->item.id == id){
                anterior = atual->ant;
                proximo = atual->prox;
                anterior->prox = atual->prox;
                proximo->ant = anterior;
                free(atual);
                break;
            }
            atual = atual->prox;
        }
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


int buscarAnterior(TipoLista lista, int id){ // Função que retorna o anterior de um item
    apontador aux, anterior;
    aux = lista.primeiro->prox;
    anterior = lista.primeiro;
    while(aux!=NULL){
        if(aux->item.id == id)
            return anterior;
        anterior = aux;
        aux = aux->prox;
    }
    return 0;
}

void TrocaItem(TipoLista *lista, int id_1, int id_2){
    if(vazia(*lista)==1){
        printf("A lista está vazia");
    } else {
        apontador aux = lista -> primeiro -> prox;
        apontador item_1 = NULL, item_2 = NULL;
        while (aux!=NULL){
            if(aux->item.id== id_1){
                item_1 = aux;
            }
            if(aux->item.id== id_2){
                item_2 = aux;
            }
            aux = aux->prox;
        }
        if(item_1!=NULL && item_2!=NULL){
            if (item_1 == item_2){
                printf("\nVocê inseriu dois IDs iguais!");
            } else{
                int temp = item_1->item.id;
                item_1->item.id = item_2->item.id;
                item_2->item.id = temp;
                printf("\nTroca realizada com sucesso!");

                printf("\n\nSegunda impressao: \n");
                imprimir(*lista);
            }
        }else {
            printf("\nIDs fornecidos nao encontrados na lista!\n");
        }
    }
}


void acrescentaItemProx(TipoLista *lista, TipoItem item, int antecessor){

    apontador aux = buscar(*lista, antecessor);
    apontador antigo, proximo;
    if (aux != 0){
        if(buscar(*lista, item.id)==0){ // verifica se o novo item não está na lista
            apontador novo = (apontador) malloc(sizeof(celula));
            novo->item = item; // recebe o item novo
            novo->prox = aux->prox; // o novo aponta para o proximo do aux
            novo->ant = aux; // Faz o anterior do novo apontar para o aux
            antigo = aux->prox; // recebe o próximo do aux
            antigo->ant=novo; // Faz o anterior do próximo do aux apontar para o novo
            aux->prox = novo; // Faz o proximo do auxiliar apontar para o novo
        }
    }

}

void Trocar(TipoLista *lista, int id1, int id2){
    if((buscar(*lista, id1)!=0) && (buscar(*lista, id1)!=0) ){// verifica se os dois itens existem
        apontador ant1,aux1,ant2, aux2, temp, prox1,prox2;
        aux1 = buscar(*lista, id1); // armazena a posição do id 1
        aux2 = buscar(*lista, id2); // armazena a posição do id 2
        ant1 = aux1->ant; // armazena a posição do anterior do id 1
        ant2 = aux2->ant; // armazena a posição do anterior do id 2
        prox1 = aux1->prox;
        prox2 = aux2->prox;
        temp = aux2->prox; // armazena o prox do aux 2

        aux2->prox=aux1->prox;
        aux2->ant=aux1->ant;

        aux1->prox=temp;
        aux1->ant=ant2;

        ant1->prox=aux2;
        ant2->prox=aux1;

        prox1=aux2;
        prox2=aux1;

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

    item.id = 7;
    inserirFinal(&lista, item);

    item.id = 8;
    inserirFinal(&lista, item);

    item.id = 9;
    inserirFinal(&lista, item);

    printf("Primeira impressao: \n");
    imprimir(lista);

    remover(&lista, 7);


    printf("\nSegunda impressao com remoção do 7: \n");
    imprimir(lista);

    item.id = 10;
    acrescentaItemProx(&lista, item, 8);

    //inserirPosicaoAnt(&lista, 4, 6);



    printf("\nTerceira impressao com o acréscimo do 10 após o 8: \n");
    imprimir(lista);

    Trocar(&lista, 9,3);
    printf("\nQuarta impressao com a troca do 9 com o 2: \n");
    imprimir(lista);
    return 0;
}

