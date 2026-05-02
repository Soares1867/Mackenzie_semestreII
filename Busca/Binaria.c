#include <stdio.h>

int buscar(int v[], int n, int valor) {
    int inicial = 0;
    int final = n - 1;
    //Repetir ate nao restar mais elementos
    while(inicial <= final) {
        //Encontrar o elemento do meio
        //int meio = (inicial + final)/2;
        int meio = inicial + (final - inicial) / 2;
        printf("%d: %d\n", meio, v[meio]);
        //Se o elemento eh o valor que buscamos
        if (v[meio] == valor) {
            //Retornar a resposta
            return meio;
        }
        //Se nao, se o elemento eh menor que o valor
        else if (v[meio] < valor) {
            //Continuar buscando na metade direita
            inicial = meio + 1;
        }
        //Se nao
        else {
            //Continuar buscando na metade esquerda
            final = meio - 1;
        }
    }
    //Retornar que nao encontramos
    return -1;
}

int main() {
    //             0   1   2   3   4   5   6   7   8   9
    int notas[] = {70, 75, 77, 79, 83, 85, 87, 88, 95, 99};
    int nota;
    printf("Nota que você busca: ");
    scanf("%d", &nota);
    int aluno = buscar(notas, 10, nota);
    printf("Aluno %d tirou nota %d!!\n", aluno, nota);
    return 0;
}