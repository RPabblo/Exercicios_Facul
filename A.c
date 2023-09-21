#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct lista {
    int valor;
    struct Lista *proximo;
} Lista;


Lista* criar_no(int valor)
{
    Lista *novo_no = malloc(sizeof(Lista));
    novo_no->valor = valor;
    novo_no->proximo = NULL;

    return novo_no;
}


void inserir(Lista **head, int value)
{
    Lista *novo = criar_no(value);

    while((*head)->proximo != NULL) {
        *head = (*head)->proximo;
    }
    (*head)->proximo = novo;
    novo->proximo = NULL;
}


void inserir_ordenado(Lista **lista, int value)
{
    Lista *new_Listade = criar_no(value);

    if(*lista == NULL || (*lista)->valor >= new_Listade->valor) {
        new_Listade->proximo = *lista;
        *lista = new_Listade;
        return;
    }

    Lista *ant = *lista;
    Lista *prox = ant->proximo;

    while(prox != NULL && prox->valor < new_Listade->valor) {
        ant = ant->proximo;
        prox = prox->proximo;
    }
    new_Listade->proximo = prox;
    ant->proximo = new_Listade;
}

void imprimir(Lista *lista)
{
    Lista *temp = lista;

    while(temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
}

/*
void uniao(Lista **res, Lista *c1, Lista *c2)
{
    Lista *temp1 = c1; Lista *temp2 = c2;

    while(temp1 != NULL &&  temp2 != NULL) {
        if(temp1->valor < temp2->valor) {
            inserir(res, temp1->valor);
            temp1 = temp1->proximo;
        }

        else if(temp2->valor < temp1->valor) {
            inserir(res, temp2->valor);
            temp2 = temp2->proximo;
        }

        else {
            temp1 = temp1->proximo;
            temp2 = temp2->proximo;
        }
    }
}
*/


int main(void)
{
    Lista *c1 = NULL; Lista *c2 = NULL; Lista *resultado = NULL;
    int n1, n2, valor;
    
    printf("Quantos elementos na lista 1? ");
    scanf("%d", &n1);
    while(getchar() != '\n');

    printf("\nQuantos elementos na lista 2? ");
    scanf("%d", &n2);
    while(getchar() != '\n');

    for(int i = 0; i < n1; i++) {
        printf("\nDigite o %do elemento do conjuto 1: ", i + 1);
        scanf("%d", &valor);
        //inserir_ordenado(&c1, valor);
    }

    for(int i = 0; i < n2; i++) {
        printf("\nDigite o %do elemento do conjuto 1: ", i + 1);
        scanf("%d", &valor);
        //inserir_ordenado(&c2, valor);
    }

    imprimir(resultado);

    return 0;
}
