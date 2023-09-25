#include <stdio.h>
#include <stdlib.h>


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

void imprimir(Lista *lista)
{
    Lista *temp = lista;

    while(temp != NULL) {
        printf("%d, ", temp->valor);
        temp = temp->proximo;
    }
    printf("\n");
}


void remover(Lista **lista, int valor)
{
    Lista *temp;
    
    if(lista == NULL) return;
    
    if((*lista)->valor == valor) {
        temp = (*lista)->proximo;
        free(*lista);
        return;
    }
    
    Lista *ant = *lista;
    temp = ant->proximo;
    
    while(temp->valor != valor && temp != NULL) {
        temp = temp->proximo;
        ant = ant->proximo;
    }
    
    if(temp->valor == valor) {
        ant->proximo = temp->proximo;
        free(temp);
        return;
    }
}

//--------------------------------------------------

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


Lista * uniao(Lista *c1, Lista *c2)
{
    Lista *res = NULL;
    Lista **proximo = &res;

    while(c1 != NULL && c2 != NULL) {
        if(c1->valor < c2->valor) {
            *proximo = c1;
            c1 = c1->proximo;
        }
        else {
            *proximo = c2;
            c2 = c2->proximo;
        }
        proximo = &((*proximo)->proximo);
    }
    *proximo = c1 ? c1 : c2;
    return res;
}

Lista * interseccao(Lista *c1, Lista *c2)
{
    Lista *res = NULL;

    while(c1 != NULL && c2 != NULL) {
        if(c1->valor == c2->valor) {
            inserir_ordenado(&res, c1->valor);
            c1 = c1->proximo;
            c2 = c2->proximo;
        }
        else if(c1->valor < c2->valor) {
                c1 = c1->proximo;
        }
        else {
            c2 = c2->proximo;
        }
    }
    return res;
}


Lista * diferenca(Lista *c1, Lista *c2)
{
    Lista *res = NULL;
    Lista *temp = c2;

    if(c2 == NULL) return c1;
    
    while(c2 != NULL) {
        remover(&c1, c2->valor);
        
        temp = temp->proximo;
    }
}

int main(void)
{
    Lista *c1 = NULL; Lista *c2 = NULL; Lista *resultado = NULL;
    int n1 = 5 , n2 = 5, valor, escolha = 0;
    int array1[5] = {6, 7, 1 ,23, 10};
    int array2[5] = {1, 3, 5, 7, 9};
    
    /*
    printf("Quantos elementos do conjunto 1? ");
    scanf("%d", &n1);
    printf("Quantos elementos do conjunto 2? ");
    scanf("%d", &n2);
    */

    for(int i = 0; i < n1; i++) {
        //printf("Digite o %do elemento do conjuto 1: ", i + 1);
        //scanf("%d", &valor);
        inserir_ordenado(&c1, array1[i]);
    }
    printf("\n");
    for(int i = 0; i < n2; i++) {
        //printf("Digite o %do elemento do conjuto 2: ", i + 1);
        //scanf("%d", &valor);
        inserir_ordenado(&c2, array2[i]);
    }
    
    printf("\n--------------------------\nVoce inseriu os dois conjuntos abaixo:\n");
    imprimir(c1);
    imprimir(c2);

    printf("Qual operacao deseja fazer?\n[1] Uniao\n[2] Interseccao \n[3] Diferenca\n[4] Sair\n");
    scanf("%d", &escolha);

    while(escolha != 4) {
        switch (escolha) {
            case 1 :
                if(resultado != NULL) break;
                resultado = uniao(c1, c2);
                break;
            case 2:
                resultado = interseccao(c1, c2);
                break;
            case 3:
                diferenca(c1, c2);
                break;
                
            default:
                return 0;
        }
        printf("\n----------------------------\n");
        imprimir(c1);
        printf("----------------------------\n\nQual operacao deseja fazer?\n[1] Uniao\n[2] Interseccao \n[3] Diferenca\n[4] Sair\n");
        scanf("%d", &escolha);
    }
    return 0;
}
