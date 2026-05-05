#include <stdio.h>
#include <stdbool.h>

void insertion_sort(int v[], int n) {
 // para cada posição do vetor (1º percurso)
 // observe que começamos pelo 2º elemento, pois consideramos que o 1º elemento já está ordenado
    for (int i = 1; i < n; i++) {
        // guardar elemento
        int elemento = v[i];
        int j = i - 1;
        bool encontrou = false;
        // percorrer no sentido inverso enquanto não chegar ao início do vetor e não encontrar um menor
        while (j >= 0 && !encontrou) {
            // se o elemento do 2º percurso for maior que o elemento do 1º percurso
            if (v[j] > elemento) {
                // deslocar elemento do 2º percurso para a direita
                v[j + 1] = v[j];
                // continuar procurando
                j--;
            }
            // se o elemento do 2º percurso for menor, encontramos a posição onde o elemento do 1º percurso
            // deve ser inserido
            else encontrou = true;
        }  

     
        // continuar procurando
        v[j + 1] = elemento;
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
    
    insertion_sort(v, n);

    // Apos acabar as função, volta para cá automaticamente
    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
