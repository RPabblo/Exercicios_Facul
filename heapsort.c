#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void subir(int *array,int i) 
{
    double x = (double) i / 2.0;
    double j = ceil(x) - 1.0; // Nó pai

    if(j >= 0.0) {
        if(array[i] > array[(int)j]) {
            swap(&array[i], &array[(int)j]);
            subir(array, (int)j);
        }
    }
}


void descer(int *array,int i, int tam)
{
    int j = 2 * i + 1; // Filho esquerdo

    if(j <= tam - 1) {
        if(j < tam - 1) {
            if(array[j + 1] > array[j]) {
                j += 1;
            }
        }

        if(array[i] < array[j]) {
            swap(&array[i], &array[j]);
            descer(array, j, tam);
        }
    }
}


int heapify(int *array, int n)
{ 
    int i;
    for(i = n / 2; i >= 0; i--) {
        descer(array, i, n);
    }
}


void heapsort(int *array, int n)
{
    heapify(array, n);

    int i = n;
    while(i > 0) {
        swap(&array[0], &array[i - 1]);
        i -= 1;
        descer(array, 0, i);
    }
}


void imprimir(int *array, int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d, ", array[i]);

    printf("\n");
}


int main()
{
    int n = 5, x;
    int *array = malloc(sizeof(int) * n);
    int temp[5] = {7, 12, 18, 25, 50};
    int outro_array[4] = {20, 35, 64, 45};

//  =============================================================

    for(int i = 0; i < n; i++)
        array[i] = temp[i];

    heapify(array, n);

    printf("Antes de inserir:\n");
    imprimir(array, n);

    for(int i = 0; i < 7; i++){
        // Insere valores no array
        array = (int *) realloc(array, sizeof(int) * (n + 1));
        array[n] = i;
        n += 1;
    }

    printf("\nDepois de inserir e construir heap:\n");
    heapify(array, n);
    imprimir(array, n);
    
    printf("\nApos heapsort:\n");
    heapsort(array, n);
    imprimir(array, n);

    return 0;
}