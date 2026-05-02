#include <stdio.h>

void trocar(int v[], int i, int j) {
    int aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}



void bubble_sort(int v[], int n) {
    int i, contador;
    // repetir (n – 1) vezes
    for (contador = 1; contador <= n - 1; contador++) {
        // percorrer cada posição do vetor
        for (i = 0; i < n - 1; i++) {
            // se elemento atual for maior que o próximo
            if (v[i] > v[i + 1]) {
            // trocar os elementos entre as 2 posições
            trocar(v, i, i + 1);
            }
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
    bubble_sort(v, n);

    // Apos acabar as função, volta para cá automaticamente
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}