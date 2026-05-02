#include <stdio.h>
#include <stdbool.h>

void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}



void bubble_sort_sentinela(int v[], int n) {
    int i, contador;
    for (contador = 1; contador <= n - 1; contador++) {

        //mudança do normal para o com sentinela
        bool sentinela = false;
    
        //igual
        for (i = 0; i < n - 1; i++) {
            if (v[i] > v[i + 1]) {
                trocar(v, i, i + 1);
                sentinela = true;  //mudança
            }
        }
        if (!sentinela){ //mudança
            return;
        }
    }
}


int main(){
    int v[100];
    int valor;
    int n=0;
    int cont=1;
    int i=0;


    while(cont==1){
        printf("Digite um numero: \n");
        scanf(" %d", &valor);
        v[i]=valor;
        n++;
        i++;
        printf("Quer continuar? 0=não, 1=sim\n");
        scanf(" %d", &cont);
    }
    bubble_sort_sentinela(v, n);

    // Apos acabar as função, volta para cá automaticamente
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}