#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct lista  {
    int valor;
    struct lista *proximo;
} Lista;

typedef struct hashtable {
    struct lista *primeira;
} HashTable;


Lista * criar_lista(int valor)
{
    Lista  *nova_lista = malloc(sizeof(Lista));
    nova_lista->proximo = NULL;
    nova_lista->valor = valor;
    return nova_lista;
}

void inserir(HashTable *lista, int valor)
{
    if(lista == NULL)
        return;

    Lista *novo = criar_lista(valor);

    if(lista->primeira == NULL) {
        lista->primeira = novo;
        return;
    }

    else {
        Lista *temp = lista->primeira;
        while(temp->proximo != NULL) 
            temp = temp->proximo;
            
        temp->proximo = novo;
    }
}

int buscar_elemento(HashTable *ht, int x)
{
    Lista *temp = ht->primeira;
    while(temp != NULL) {
        if(temp->valor == x) {
            return 1;
        }
        temp = temp->proximo;
    }
    return 0;
}

void imprimir(HashTable *ht)
{
    int i;
    Lista *temp = ht->primeira;
    while(temp != NULL) {
        printf("%d -> ", temp->valor);
        temp = temp->proximo;
    }
}

void remover(HashTable *ht, int x)
{   
    Lista *penultimo = NULL, *ultimo = NULL;

    if(ht == NULL || ht->primeira == NULL) {
        printf("Lista ja vazia.\n");
        return;
    }

    if(ht->primeira->valor == x) {
        penultimo = ht->primeira->proximo;
        free(ht->primeira);
        ht->primeira = penultimo;
        return;
    }

    if(ht->primeira->proximo == NULL)
        return;

    penultimo = ht->primeira;
    ultimo = penultimo->proximo;

    while(ultimo->proximo != NULL && ultimo->valor != x) {
        penultimo = penultimo->proximo;
        ultimo = ultimo->proximo;
    }

    if(ultimo->proximo == NULL && ultimo->valor != x)
        return;

    penultimo->proximo = ultimo->proximo;
    free(ultimo);
    return;
}


int main(void)
{
    int i, pos, n, n2;

    // Array deve ter mesmo tamanho da hash_function
    HashTable ht[7];
    int hash_function = 7;

    int vet[18] = {0, 7, 10, 20, 15, 14, 12, 33, 30, 21, 70, 71, 72, 73, 74, 75, 76, 77};
    n = 18;

    int vet2[4] = {0, 77, 30, 12};
    n2 = 4;

//  =================================================================================

    // Inicializa
    for(i = 0; i < hash_function; i++) {
        ht[i].primeira = NULL;
    }

    // Aqui ocorre o enderecamento correto dos valores na hash table atraves
    // do modulo / resto da divisao pela funcao de dispercao
    for(i = 0; i < n; i++) {
        pos = vet[i] % hash_function;
        inserir(&ht[pos], vet[i]);
    }

    printf("Tabela hash:\n");
    for(i = 0; i < hash_function; i++) {
        printf("%d: ", i);
        imprimir(&ht[i]);
        printf("\n");
    }
    printf("\n");

    // Busca o elemento em cada lista na hash table
    for(i = 0; i < hash_function; i++) {
        if(buscar_elemento(&ht[i], 90));
    }
    printf("\n");

    for(i = 0; i < n2; i++) {
        pos = vet[i] % 7;
        remover(&ht[pos], vet2[i]);
    }

    printf("Apos a remocao:\n");
    for(i = 0; i < hash_function; i++) {
        printf("%d: ", i);
        imprimir(&ht[i]);
        printf("\n");
    }

    return 0;
}