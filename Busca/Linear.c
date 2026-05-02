#include <stdio.h>

int buscar(int v[], int n, int valor) {
    //Percorrer o vetor
    for(int i = 0; i < n; i++){
        //Se o valor atual é igual a valor
        if (v[i] == valor) {
            //Achei e retorna a resposta
            return i;
        }
    }
    //Retorno que não achei
    return -1;
}

int main() {
    //             0   1   2   3   4   5   6   7
    int notas[] = {85, 87, 79, 75, 88, 99, 95, 83};
    int nota;
    printf("Nota que você busca: ");
    scanf("%d", &nota);
    int aluno = buscar(notas, 8, nota);
    printf("Aluno %d tirou nota %d!!\n", aluno, nota);
    return 0;
}