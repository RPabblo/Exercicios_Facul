#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

typedef struct lista {
    int valor;
    struct lista *proximo;
} Lista;


void print_Lista(Lista *head)
{
    Lista *temp = head;

    while(temp != NULL) {
        if(temp->proximo == NULL) {
            printf("%d.", temp->valor);
        }
        else {
            printf("%d -> ", temp->valor);
        }
        temp = temp->proximo;
    }
    printf("\n\n");
}

Lista *create_node(int value)
{
    Lista *new_node = malloc(sizeof(Lista));
    new_node->valor = value;
    new_node->proximo = NULL;

    return new_node;
}

void node_after(Lista *node, int value)
{
    Lista *new_node = create_node(value);
    
    new_node->proximo = node->proximo;
    node->proximo = new_node;
}

void delete_first(Lista **head)
{
    Lista *temp = *head;
    *head = (*head)->proximo;

    free(temp);
}

void head_node(Lista **head, int value)
{   
    Lista *new_node = create_node(value);
    new_node->proximo = *head;
    *head = new_node;
}

Lista *find_node(Lista *head, int value)
{
    Lista *temp = head;

    while(temp != NULL) {
        if(temp->valor == value) return temp;
        temp = temp->proximo;
    }
    return NULL;
}

void last_node(Lista **head, int value)
{
    Lista *new_node = create_node(value);

    while((*head)->proximo != NULL) {
        *head = (*head)->proximo;
    }
    (*head)->proximo = new_node;
    new_node->proximo = NULL;
}

void inserir_ordenado(Lista **head, int value)
{
    Lista *new_node = create_node(value);

    if(*head == NULL || (*head)->valor >= new_node->valor) {
        new_node->proximo = *head;
        *head = new_node;
        return;
    }

    Lista *ant = *head;
    Lista *prox = ant->proximo;

    while(prox != NULL && prox->valor < new_node->valor) {
        ant = ant->proximo;
        prox = prox->proximo;
    }
    new_node->proximo = prox;
    ant->proximo = new_node;
}

Lista *ordernar_lista(Lista **head)
{
    Lista *nova_lista = NULL;
    Lista *temp = *head;

    while(temp != NULL) {
        inserir_ordenado(&nova_lista, temp->valor);
        temp = temp->proximo;
    }
    return nova_lista;
}

int myRandom (int size) {
    int i, n;
    static int numNums = 0;
    static int *numArr = NULL;

    // Initialize with a specific size.

    if (size >= 0) {
        if (numArr != NULL)
            free (numArr);
        if ((numArr = malloc (sizeof(int) * size)) == NULL)
            return ERR_NO_MEM;
        for (i = 0; i  < size; i++)
            numArr[i] = i;
        numNums = size;
    }

    // Error if no numbers left in pool.

    if (numNums == 0)
       return ERR_NO_NUM;

    // Get random number from pool and remove it (rnd in this
    //   case returns a number between 0 and numNums-1 inclusive).

    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums-1];
    numNums--;
    if (numNums == 0) {
        free (numArr);
        numArr = 0;
    }

    return i;
}

void inserir_sem_repeticao(Lista **head, int value)
{
    Lista *temp = *head;

    while(temp != NULL) {
        if(temp->valor == value) {
            printf("Elemento nao adicionado pois ja existe na lista.\n");
            return;
        }
        temp = temp->proximo;
    }

    head_node(head, value);
}

void info(Lista *head)
{
    int pares = 0, impares = 0, cont = 0;
    int maior = head->valor, menor = head->valor;

    while(head != NULL) {
        if(head->valor % 2 == 0)
            pares += 1;
        else 
            impares += 1;
        
        if(head->valor > maior)
            maior = head->valor;
        
        if(head->valor < menor)
            menor = head->valor;

        head = head->proximo;
        cont += 1;   
    }

    printf("Ha %d elementos, sendo eles:\n\n", cont);
    printf("Ha %d numeros pares e %d numeros impares.\n", pares, impares);
    printf("O maior elemento temo valor %d e o menor possui o valor de %d.\n\n", maior, menor);
}

void remover_dois_inicio(Lista **head)
{
    Lista *primeiro = *head;
    Lista *segundo = (*head)->proximo;

    *head = (*head)->proximo->proximo;

    free(primeiro);
    free(segundo);
}

int remove_last(Lista **head)
{
    Lista *penultimo = NULL, *ultimo = NULL;

    if(*head == NULL || head == NULL) {
        printf("Lista vazia\n");
        return 1;
    }

    if((*head)->proximo == NULL) {
        printf("Deletando ultimo elemento\n");
        free(*head);
        *head = NULL;
        return 0;
    }

    penultimo = *head;
    ultimo = penultimo->proximo;

    while(ultimo->proximo != NULL) {
        penultimo = penultimo->proximo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;

    return 0;
}

void remover_dois_final(Lista **head)
{
    Lista *antepenultimo = *head;
    Lista *penultimo = antepenultimo->proximo;
    Lista *ultimo = penultimo->proximo;

    while(ultimo->proximo != NULL) {
        antepenultimo = antepenultimo->proximo;
        penultimo = penultimo->proximo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    free(penultimo);
    antepenultimo->proximo = NULL;
}

/*
void remover_dois_final(Lista **head)
{
    remove_last(head);
    remove_last(head);
}
*/

void reverse(Lista **head)
{
    Lista *anterior = NULL, *atual = *head, *proximo = NULL;

    while(atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *head = anterior;
}

void dividir(Lista **head, Lista **new_list, int value)
{
    Lista *temp = *head;

    while(temp->valor != value && temp != NULL)
        temp = temp->proximo;
    
    if(temp == NULL) {
        printf("Elemento nao encontrado.\n");
        return;
    }

    else {
        *new_list = temp->proximo;
        temp->proximo = NULL;
    }
}

void concatenar(Lista **lista_1, Lista **lista_2, Lista **lista_concatenada)
{
    *lista_concatenada = *lista_1;
    Lista *temp = *lista_concatenada;

    while(temp->proximo != NULL) {
        temp = temp->proximo;
    }

    temp->proximo = *lista_2;
}


int main(void)
{
    Lista *head = NULL, *temp = NULL, *new_list = NULL, *new_list2 = NULL, *uniao = NULL;

    int i;

    srand (time (NULL));
    i = myRandom (10);
    while (i >= 0) {
        i = myRandom (-1);
        printf ("%d, ", i);
        head_node(&head, i);
    }

    new_list = ordernar_lista(&head);
    printf("\n\nLista ordenada:\n");
    print_Lista(new_list);

    inserir_sem_repeticao(&new_list, 50);
    inserir_sem_repeticao(&new_list, 60);

    printf("\nNova  Lista:\n");
    print_Lista(new_list);

    remover_dois_inicio(&new_list);
    remover_dois_final(&new_list);

    reverse(&new_list);
    printf("Lista reversa:\n");
    print_Lista(new_list);

    dividir(&new_list, &new_list2, 3);
    print_Lista(new_list);
    print_Lista(new_list2);

    printf("Lista concatenada:\n");
    concatenar(&new_list, &new_list2, &uniao);
    print_Lista(uniao);

    return 0;

    /*
    for(int i = 1; i < 26; i++) {
            temp = create_node(i);
            head_node(&head, temp);
    }

    Lista *find = find_node(head, 10);
    if(find != NULL) printf("Elemento de valor %d foi encontrado.\n", find->valor);

    node_after(find, 80);

    printf("Antes de deletar:\n");
    print_Lista(head);

    delete_first(&head);
    remove_last(&head);

    printf("\n\nDepois das alteracoes:\n");
    print_Lista(head);
    */

}
