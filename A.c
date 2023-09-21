#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct lista {
    int valor;
    struct lista *proximo;
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
    Lista *novo_no = criar_no(value);

    if(*lista == NULL || (*lista)->valor >= novo_no->valor) {
        novo_no->proximo = *lista;
        *lista = novo_no;
        return;
    }

    Lista *ant = *lista;
    Lista *prox = ant->proximo;

    while(prox != NULL && prox->valor < novo_no->valor) {
        ant = ant->proximo;
        prox = prox->proximo;
    }
    novo_no->proximo = prox;
    ant->proximo = novo_no;
}

void append(Lista** head_ref, int new_data)
{
    /* 1. allocate node */
    Lista* new_node = (Lista*)malloc(sizeof(Lista));
 
    Lista* last = *head_ref; /* used in step 5*/
 
    /* 2. put in the data */
    new_node->valor = new_data;
 
    /* 3. This new node is going to be the last node, so
    make next of it as NULL*/
    new_node->proximo = NULL;
 
    /* 4. If the Linked List is empty, then make the new
    * node as head */
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    /* 5. Else traverse till the last node */
    while (last->proximo != NULL)
        last = last->proximo;
 
    /* 6. Change the next of last node */
    last->proximo = new_node;
    return;
}

void imprimir(Lista *lista)
{
    Lista *temp = lista;

    while(temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}


void uniao(Lista **res, Lista *c1, Lista *c2)
{
    Lista *temp1 = c1; Lista *temp2 = c2;

    for(;;)
    {
        if(temp1 != NULL && temp2 == NULL) {
            return;
        }
    
        if(temp1->valor < temp2->valor) {
            inserir_ordenado(res, temp1->valor);
        }
        else if(temp2->valor < temp1->valor) {
            inserir_ordenado(res, temp2->valor);
        }
    }
    
    while(temp1 != NULL) {
        inserir_ordenado(res, temp1->valor);
        temp1= temp1->proximo;
    }
    
    while(temp2 != NULL) {
        inserir_ordenado(res, temp2->valor);
        temp2 = temp2->proximo;
    }
}

// 1 -> 3 -> 5
// 2 -> 5 -> 6 -> 0



int main(void)
{
    Lista *c1 = NULL; Lista *c2 = NULL; Lista *resultado = NULL;
    int n1 = 5, n2 = 5, valor;
    int array1[5] = {6, 7, 1 ,23, 10};
    int array2[5] = {1, 3, 5, 7, 9};
  
    for(int i = 0; i < n1; i++) {
        //printf("\nDigite o %do elemento do conjuto 1: ", i + 1);
        //scanf("%d", &valor);
        inserir_ordenado(&c1, array1[i]);
    }

    for(int i = 0; i < n2; i++) {
        //printf("Digite o %do elemento do conjuto 1: ", i + 1);
        //scanf("%d", &valor);
        inserir_ordenado(&c2, array2[i]);
    }
    
    imprimir(c1);
    printf("\n");
    imprimir(c2);

    uniao(&resultado, c1, c2);
    printf("dihfidhfuihfiuhdsfudshf");
    printf("Resultado\n");
    imprimir(resultado);

    return 0;
}
