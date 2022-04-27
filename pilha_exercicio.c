#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int id;
    int value;
    struct pilha *proximo;
} Pilha;

Pilha *criar_elemento(int value)
{
    Pilha *novo_elemento = malloc(sizeof(Pilha));

    novo_elemento->value = value;
    novo_elemento->proximo = NULL;

    return novo_elemento;
}

void adicionar_inicio(Pilha **head, int value)
{
    Pilha *novo_elemento = criar_elemento(value);
    novo_elemento->id = 1;
    
    if(*head == NULL) {
        *head = novo_elemento;
        return;
    }

    Pilha *temp = *head;

    while(temp != NULL) {
        temp->id += 1;
        temp = temp->proximo;
    }

    novo_elemento->proximo = *head;
    *head = novo_elemento;
}

void print_lista(Pilha *head)
{
    Pilha *temp = head;

    printf("ID    Valor\n\n");

    while(temp != NULL) {
        printf("%d     %d\n", temp->id, temp->value);
        temp = temp->proximo;
    }
    printf("\n\n");
}

void remover_inicio(Pilha **head)
{
    Pilha *temp = *head;
    *head = (*head)->proximo;

    free(temp);

    Pilha *temp_2 = *head;
    while(temp_2 != NULL) {
        temp_2->id  -= 1;
        temp_2 = temp_2->proximo;
    }
}

void reverter(Pilha **head)
{
    Pilha *anterior = NULL, *atual = *head, *proximo = NULL;
    int temp;

    while(atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

void fundo(Pilha *head)
{
    Pilha *temp = head;

    while(temp->proximo != NULL) {
        temp = temp->proximo;
    }

    printf("Ultimo elemento\n");
    printf("ID   VALOR\n%d    %d\n", temp->id, temp->value);

}

void somar(Pilha *head)
{
    Pilha *temp = head;
    int cont = 0;

    while(temp != NULL) {
        cont += temp->value;
        temp = temp->proximo;
    }

    printf("A soma dos valores e %d\n\n", cont);
}

void mover(Pilha **remetente, Pilha **destinatario, int id)
{
    if(*remetente == NULL)
        return;

    Pilha *ant = *remetente;
    Pilha *prox = ant->proximo;
    Pilha *temp_2 = NULL;

    while(prox != NULL && prox->id != id) {
        prox = prox->proximo;
        ant = ant->proximo;
    }

    if(prox == NULL) 
        return;

    ant->proximo = prox->proximo;
    temp_2 = ant->proximo;

    prox->proximo = *destinatario;
    *destinatario = prox;

    while(temp_2 != NULL) {
        temp_2->id -= 1;
        temp_2 = temp_2->proximo;
    }

    // Acertar IDs das listas
    (*destinatario)->id = 1;
    if((*destinatario)->proximo != NULL) {
        Pilha *temp = (*destinatario)->proximo;

        while(temp != NULL) {
            temp->id += 1;
            temp = temp->proximo;
        }
    }
    printf("%d e %d e %d\n\n", ant->id, prox->id, (*remetente)->id);
    
}

int main(void)
{
    Pilha *head = NULL, *head_2 = NULL;

    adicionar_inicio(&head, 200);
    adicionar_inicio(&head, 250);
    adicionar_inicio(&head, 300);
    adicionar_inicio(&head, 2000);
    adicionar_inicio(&head, 1000);

    adicionar_inicio(&head_2, 1);
    adicionar_inicio(&head_2, 2);
    adicionar_inicio(&head_2, 3);

    print_lista(head);
    print_lista(head_2);

    mover(&head, &head_2, 2);

    printf("Depois de mover:\n");
    print_lista(head);
    print_lista(head_2);

    return 0;
}