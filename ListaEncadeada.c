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

int buscar(TipoLista lista, int id){
    apontador aux;
    aux = lista.primeiro->prox;
    while(aux!=NULL){
        if(aux->item.id == id)
            return 1;
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
void inserirPosicao(TipoLista *lista, int id, int id_novo) {
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

        printf("\n");
        imprimir(*lista);
    } else {
        printf("Erro: o id %d não foi encontrado na lista.\n", id);
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

    printf("Primeira impressao: \n");
    imprimir(lista);

    //TrocaItem(&lista, 2,1);
    inserirPosicao(&lista, 2, 5);


    return 0;
}

