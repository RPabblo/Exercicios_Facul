#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *proximo;
} Node;

typedef struct fila {
    struct node *primeiro;
    struct node *ultimo;
} Fila;


Node *criar_elemento(int value)
{
    Node *novo_elemento = malloc(sizeof(Node));

    novo_elemento->value = value;
    novo_elemento->proximo = NULL;

    return novo_elemento;
}

Fila *iniciar_fila()
{
    Fila *nova_fila = malloc(sizeof(Fila));

    nova_fila->primeiro = NULL;
    nova_fila->ultimo = NULL;

    return nova_fila;
}

void adicionar_elemento(Fila *f, int value)
{
    printf("%d adicionado a fila.\n", value);
    Node *novo_elemento = criar_elemento(value);

    if(f->ultimo == NULL) {
        f->primeiro = novo_elemento;
        f->ultimo = novo_elemento;
        return;
    }

    f->ultimo->proximo = novo_elemento;
    f->ultimo = novo_elemento;

}

void print_fila(Fila *f)
{
    if(f->primeiro == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    Node *temp = f->primeiro;

    printf("INICIO | ");

    while(temp != NULL) {
        if(temp->proximo != NULL)
            printf("%d <- ", temp->value);
        else 
            printf("%d. ", temp->value);
        temp = temp->proximo;
    }

    printf("| FINAL\n\n");
}

void remover_elemento(Fila *f)
{
    if(f->primeiro == NULL) {
        printf("Lista vazia. Nao foi possivel remover.\n");
        return;
    }
    
    Node *temp = f->primeiro;

    f->primeiro = f->primeiro->proximo;

    if(f->primeiro == NULL)
        f->ultimo = NULL;

    else if(f->primeiro->proximo == NULL) {
        f->ultimo = f->primeiro;
    }

    free(temp);
}

void reverter(Fila *f)
{
    Node *atual = f->primeiro;
    Node  *anterior = NULL, *proximo = NULL;
    
    f->ultimo = f->primeiro;

    while(atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }
    f->primeiro = anterior;
}

int main(void)
{
    Fila *f = iniciar_fila();

    adicionar_elemento(f, 1);
    adicionar_elemento(f, 2);
    adicionar_elemento(f, 3);
    adicionar_elemento(f, 4);

    print_fila(f);

    reverter(f);
    print_fila(f);

    return 0;
}