#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define tam 5

typedef struct{
    int id;
    char nome[30];
}TipoItem;

typedef struct{
    int inicio;
    int fim;
    TipoItem itens[tam];
}TipoLista;

void criarLista(TipoLista *lista){
    lista->inicio = 0;
    lista->fim = 0;
}

int vazia(TipoLista lista){
    if(lista.inicio == lista.fim)
        return 1;
    else
        return 0;
}

int cheia(TipoLista lista){
    if(lista.fim >= tam)
        return 1;
    else
        return 0;
}

void inserirFinal(TipoLista *lista, TipoItem item){
    if(cheia(*lista)==1){
        printf("Lista cheia");
    }else{
        lista->itens[lista->fim] = item;
        lista->fim++;
    }
}

int buscar(TipoLista lista, int id){
    int i;
    for(i=0; i < lista.fim; i++){
        if(lista.itens[i].id == id){
           return i;
        }
    }
    return -1;
}


int remover(TipoLista *lista, int id){
    int i, pos;
    pos = buscar(*lista, id);
    if(pos==-1){
        return 0;
    }else{
        for(i=pos; i < lista->fim; i++){
            lista->itens[i] = lista->itens[i+1];
        }
        lista->fim--;
        return 1;
    }
}

void imprimir(TipoLista lista){
    int i;
    if(vazia(lista)==1){
        printf("Lista vazia!!!");
    }else{
        for(i=0; i<lista.fim; i++){
            printf("ID: %d", lista.itens[i].id);
            printf("\nNome: %s", lista.itens[i].nome);
            printf("\n\n");
        }
    }
}

int main(){

    TipoLista lista;
    TipoItem item;

    criarLista(&lista);

    item.id = 1;
    strcpy(item.nome, "Joao");
    inserirFinal(&lista, item);

    item.id = 2;
    strcpy(item.nome, "Robson");
    inserirFinal(&lista, item);

    item.id = 3;
    strcpy(item.nome, "Leandro");
    inserirFinal(&lista, item);

    item.id = 4;
    strcpy(item.nome, "Breno");
    inserirFinal(&lista, item);

    item.id = 5;
    strcpy(item.nome, "Guilherme");
    inserirFinal(&lista, item);

    imprimir(lista);

    remover(&lista, 3);

    imprimir(lista);

    //inserirFinal(&lista, item);
    //inserirFinal(&lista, item);
    //inserirFinal(&lista, item);
    //inserirFinal(&lista, item);



    return 0;
}
