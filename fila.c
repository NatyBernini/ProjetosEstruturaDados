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

void desenfileirar(TipoLista *lista){
    if(vazia(*lista)==1){
        printf("A lista esta vazia!");
    }else{
        apontador atual;
        atual = lista->primeiro->prox;
        if (atual->prox == NULL){
            lista->primeiro->prox = atual->prox;
            free(atual);
            lista->primeiro = lista->ultimo;
        } else{
            lista->primeiro->prox = atual->prox;
            free(atual);
        }
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
            if(lista->primeiro->prox == lista->ultimo){
                lista->primeiro = lista->ultimo;
                free(atual);
                imprimir(*lista);
            }else{
               lista->primeiro->prox = atual->prox;
               temp = atual;
               free(temp);
               atual = atual->prox;
               imprimir(*lista);
               printf("-\n");
           }


        };
        //lista->primeiro->prox = atual;


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

int main()
{
    TipoLista lista;
    TipoItem item;
    int qtdItem, resposta, idItem;

    criar(&lista);

    printf("Olá, seja bem-vindo!\nNos informe por favor quantos itens sua lista terá inicialmente: ");
    scanf("%d", &qtdItem);
    if(qtdItem!=0){
       for (int i = 1; i<=qtdItem; i++){
        item.id = i;
        enfileirar(&lista, item);
        };
        printf("Primeira impressao lista completa: \n");
        imprimir(lista);
        printf("\n");
    }else{
        printf("Tudo bem, vamos começar com sua lista vazia.\n");
    };

    do{
        printf("\n--------------------\n");
        printf("  MENU DE OPERAÇÕES  \n");
        printf("[1] enfileirar;\n[2] desenfileirar;\n[3] zerar;\n[4] imprimir;\n[0] sair;\nRESPOSTA:");
        scanf("%d",&resposta);
        printf("\n--------------------\n");

        switch (resposta){
            case 1:
                printf("\n");
                printf("Informe o ID do item: ");
                scanf("%d", &idItem);
                item.id = idItem;
                enfileirar(&lista, item);
            break;

            case 2:
                printf("\n");
                desenfileirar(&lista);
            break;

            case 3:
                printf("\n");
                zerar(&lista);
            break;

            case 4:
                printf("\nIMPRESSAO DA LISTA: \n");
                imprimir(lista);
            break;

            default:
                printf("\n");
                printf("INFORME UMA OPÇÃO VÁLIDA");
            break;
        }

    }while(resposta!=0);

    return 0;
}
