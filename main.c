#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct pilha {
    int value;
    struct pilha *proximo;
} Pilha;

void print_lista(Pilha *head);
void decimal_to_binary(Pilha *pilha, unsigned long long int num);
void adicionar_inicio(Pilha **head, int value);
Pilha *criar_elemento(int value);





int main(void)
{
    Pilha *pilha = NULL;
    unsigned long long int num = 14;

    decimal_to_binary(pilha, num);
    print_lista(pilha);

}




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

    if(*head == NULL) {
        *head = novo_elemento;
        return;
    }

    Pilha *temp = *head;

    while(temp != NULL) {
        temp = temp->proximo;
    }

    novo_elemento->proximo = *head;
    *head = novo_elemento;
}


void print_lista(Pilha *head)
{
    Pilha *temp = head;

    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->proximo;
    }
    printf("\n\n");
}

void decimal_to_binary(Pilha *pilha, unsigned long long int num)
{

    int i;
    unsigned long long int q, r;
    while(num >= 1) {
        q = num / 2;
        r = num % 2;
        //array[i] = r;
        adicionar_inicio(&pilha, r);
        num = q;
    }

}
