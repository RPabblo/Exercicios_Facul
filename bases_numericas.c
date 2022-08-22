#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void decimal_to_binary(unsigned long long int num);

void decimal_to_hex(unsigned long long int num);


int main(void)
{
    unsigned long long int num = 1234567891234;

    decimal_to_binary(num);

    decimal_to_hex(num);
}


void decimal_to_hex(unsigned long long int num)
{
    unsigned int qtd = ceill(log2(num) + 4) / 4;

    char *array = malloc(sizeof(char) * qtd);

    int i;
    unsigned long long int q, r;

    for(i = qtd - 1; i > -1; i--) {
        q = num / 16;
        r = num % 16;

        if(r < 10) {
            array[i] = r + 48;
        }
        else {
            array[i] = r + 55;
        }
        num = q;
    }

    for(i = 0; i < qtd; i++) {
        printf("%c", array[i]);
    }
    printf("\n");
}

void decimal_to_binary(unsigned long long int num) 
{
    int qtd = floor(log2(num) + 1);

    int *array = malloc(sizeof(int) * qtd);
    

    int i;
    unsigned long long int q, r;
    for(i = qtd - 1; i > -1; i--) {
        q = num / 2;
        r = num % 2;
        array[i] = r;
        num = q;
    }   

    for(i = 0; i < qtd; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}