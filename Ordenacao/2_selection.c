#include <stdio.h>

void trocar(int v[], int i, int min){
    int aux = v[i];
    v[i] = v[min];
    v[min] = aux;
}




void selection_sort(int v[], int n) {
    // para cada posição do vetor (1º percurso)
    for (int i = 0; i < n - 1; i++) {
        // salvar o índice com menor valor ("pegar menor carta"), que começa pelo
        // índice atual de cada iteração do 1º percurso
        int min = i;
        // percorrer cada uma das próximas posições do vetor (2º percurso)
        for (int j = i + 1; j < n; j++) {
            // se o elemento deste segundo percurso for menor que o mínimo, atualizar o
            // índice que contém o menor valor.
            if (v[j] < v[min]) min = j;
        }
        // trocar os elementos entre a posição do 1º percurso e o índice mínimo
        if (min != i) trocar(v, i, min);
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
    selection_sort(v, n);

    // Apos acabar as função, volta para cá automaticamente
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}