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

void inserirFinal(TipoLista *lista, TipoItem item){
    if(buscar(*lista, item.id)==0){
        lista->ultimo->prox = (apontador) malloc(sizeof(celula));
        lista->ultimo = lista->ultimo->prox;
        lista->ultimo->prox = NULL;
        lista->ultimo->item = item;
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

void remover(TipoLista *lista, int id){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador anterior, atual;
        anterior = lista->primeiro;
        atual = lista->primeiro->prox;
        while(atual!=NULL){
            if(atual->item.id == id){
                anterior->prox = atual->prox;
                free(atual);
                break;
            }
            anterior = atual;
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

// Função para inserir um novo item na posição indicada
void inserirPosicaoAnt(TipoLista *lista, int id, int id_novo) {
    apontador atual = lista->primeiro->prox;
    apontador antecessor = lista->primeiro;

    // Encontra o nó com o id dado
    while (atual != NULL && atual->item.id != id) {
        antecessor = atual;
        atual = atual->prox;
    }

    // Se o nó com o id dado foi encontrado
    if (atual != NULL) {
        // Cria um novo nó com o id_novo
        apontador novo = (apontador)malloc(sizeof(apontador));
        if (novo == NULL) { // Quando a memoria está cheia
            fprintf(stderr, "Erro: memória insuficiente.\n");
            exit(EXIT_FAILURE);
        }
        novo->item.id = id_novo; // ID passado pelo usuário
        novo->prox = atual; // Posição passada pelo usuário

        // Insere o novo nó antes do nó com o id dado
        antecessor->prox = novo;


        printf("\nTerceira impressao: \n");
        imprimir(*lista);
    } else {
        printf("Erro: o id %d não foi encontrado na lista.\n", id);
    }
}


void acrescentaItemProx(TipoLista *lista, TipoItem item, int antecessor){

    apontador aux = buscar(*lista, antecessor);
    if (aux != 0){
        if(buscar(*lista, item.id)==0){ // verifica se o novo item não está na lista
            apontador novo = (apontador) malloc(sizeof(celula));
            novo->item = item;
            novo->prox = aux ->prox;
            aux->prox = novo;
        }
    }

}

void Trocar(TipoLista *lista, int id1, int id2){
    if((buscar(*lista, id1)!=0) && (buscar(*lista, id1)!=0) ){// verifica se os dois itens existem
        apontador ant1,aux1,ant2, aux2, temp;
        ant1 = buscarAnterior(*lista, id1); // armazena a posição do anterior do id 1
        ant2 = buscarAnterior(*lista, id2); // armazena a posição do anterior do id 2
        aux1 = buscar(*lista, id1); // armazena a posição do id 1
        aux2 = buscar(*lista, id2); // armazena a posição do id 2
        temp = aux2->prox; // armazena o prox do aux 2

        aux2->prox = aux1->prox;
        ant1->prox=aux2;

        aux1->prox=temp;
        ant2->prox=aux1;
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

    item.id = 5;

    acrescentaItemProx(&lista, item, 3);

    printf("\nSegunda impressao: \n");
    imprimir(lista);

    inserirPosicaoAnt(&lista, 4, 6);

    Trocar(&lista, 9,2);

    printf("\nTerceira impressao: \n");
    imprimir(lista);
    return 0;
}

