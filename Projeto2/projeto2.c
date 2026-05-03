/*
 * Universidade Presbiteriana Mackenzie
 * Disciplina: Algoritmos e Programação II
 * Projeto 2 - Sistema de Análise de Dados de Vendas
 * 
 * Integrantes do Grupo:
 * - Nome 1 (RA)
 * - Nome 2 (RA)
 * - Nome 3 (RA)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

/*
GY:
    Função buscaLinear
OK  int buscaLinear(int ids[], int n, int idProcurado);
    Descrição:
    Realiza busca sequencial no array de IDs.
    Parâmetros:
ok  • ids[]: array de IDs
ok  • n: tamanho do array
ok  • idProcurado: valor a ser buscado
    Retorno:
ok  • Índice onde o ID foi encontrado
ok  • -1 caso não encontrado 
*/
//FUNÇÃO BUSCA BINARIA
int buscaLinear(int ids[], int qtdVendas, int idProcurado){
    for(int i=0; i<qtdVendas; i++){
        if (idProcurado==ids[i]){
            printf("O id esta na posicao %d\n",i);
            return i;
        }
    }
    

    return -1; //caso não encontrado 
}







/*
GY:
    Função buscaVendaBinaria
    int buscaBinaria(int ids[], int n, int idProcurado);
    Descrição:
    Realiza busca binária no array de IDs.
    Pré-condição:
    O array ids[] deve estar ordenado em ordem crescente.
    Parâmetros:
    • ids[]: array ordenado de IDs
    • n: tamanho do array
    • idProcurado: valor a ser buscado
    Retorno:
    • Índice onde o ID foi encontrado
    • -1 caso não encontrado

*/


//int buscarVendaBinaria(int v[], int n, int valor)
int buscarVendaBinaria(int ids[], int qtdVendas, int idProcurado) {
    int inicio=0;
    int fim=qtdVendas-1;
    //Repetir ate nao restar mais elementos
    while(inicio<=fim){

        //elemento do meio é dado pela formula do professor meio = inicial + (final - inicial) / 2
        int meio = inicio + (fim - inicio) / 2;
        //na sorte o elemento do meio é exatamente oque procuravamos, ja retorna  e acaba por ai mesmo
        if (ids[meio] == idProcurado) {
            //Retornar a resposta
            printf("O id esta na posicao %d\n",meio);
            return meio;
        }
        //Se nao, se o elemento eh menor que o valor
        if (ids[meio] < idProcurado) {
            //Continuar, pela formula do professor
            inicio = meio + 1;
        }
        
        if (ids[meio] > idProcurado){
            //Continuar, pela formula do professor
            fim = meio - 1;
        }
    }
    return -1;
}




//Função bubbleSortVendaPorId 
/*Gy:
    Função bubbleSortVendaPorId
        void bubbleSortVendaPorId(int ids[],
        int produtoIds[],
        int quantidades[],
        float precos[],
        int n);
    Descrição:
    Ordena os dados em ordem crescente de id utilizando o algoritmo Bubble Sort.
    Parâmetros:
    • Arrays paralelos (ids, produtoIds, quantidades, precos)
    • n: número de elementos
    Retorno:
    • Não possui retorno

*/


/*Gy:
    Função insertionSortVendaPorId
        void insertionSortVendaPorId(int ids[],
        int produtoIds[],
        int quantidades[],
        float precos[],
        int n);
    Descrição:
    Ordena os dados em ordem crescente de id utilizando o algoritmo Insertion Sort.
    Parâmetros:
    • Arrays paralelos (ids, produtoIds, quantidades, precos)
    • n: número de elementos
    Retorno:
    • Não possui retorno 
*/



/*Gy:
    Função selectionSortVendaPorId
        void selectionSortPorId(int ids[],
        int produtoIds[],
        int quantidades[],
        float precos[],
        int n);
    Descrição:
    Ordena os dados em ordem crescente de id utilizando o algoritmo Selection Sort.
    Parâmetros:
    • Arrays paralelos (ids, produtoIds, quantidades, precos)
    • n: número de elementos
    Retorno:
    • Não possui retorno 
*/



void imprimir(int ids[], int produtoIds[], int quantidades[], float precos[], int qtdVendas) {
    printf("[");
    for (int i = 0; i < qtdVendas; i++) printf("%d ", ids[i]);
    printf("]\n");
    printf("[");
    for (int i = 0; i < qtdVendas; i++) printf("%d ", produtoIds[i]);
    printf("]\n");
    printf("[");
    for (int i = 0; i < qtdVendas; i++) printf("%d ", quantidades[i]);
    printf("]\n");
    printf("[");
    for (int i = 0; i < qtdVendas; i++) printf("%f ", precos[i]);
    printf("]\n");

}


void selectionSortVendaPorId(int ids[], int produtoIds[], int quantidades[], float precos[], int qtdVendas,int digitado) {
    // para cada posição do vetor
    for (int i = 0; i < qtdVendas - 1; i++) {
        // inicializar o índice do menor elemento
        int indiceMenor = i;
        // percorrer o vetor
        for (int j = i + 1; j < qtdVendas; j++) {
            // se o elemento atual (do 2o percurso) for menor que o valor que está no índice do menor elemento
            if (ids[j] < ids[indiceMenor]) {
                // atualizar o índice do menor elemento
                indiceMenor = j;
            }
        }

        // trocar o valor da posição a ser preenchida com o valor do menor índice
        int aux1 = ids[i];
        ids[i] = ids[indiceMenor];
        ids[indiceMenor] = aux1;

        int aux2 = produtoIds[i];
        produtoIds[i] = produtoIds[indiceMenor];
        produtoIds[indiceMenor] = aux2;

        int aux3= quantidades[i];
        quantidades[i] = quantidades[indiceMenor];
        quantidades[indiceMenor] = aux3;

        float aux4 = precos[i];
        precos[i] = precos[indiceMenor];
        precos[indiceMenor] = aux4;
    }
    if (digitado!=2){
        imprimir(ids, produtoIds, quantidades, precos, qtdVendas);
    }
}













// --- FUNÇÃO: carregarProdutos ---
/*Gy:
    4.
        Função carregarProdutos
                    int carregarProdutos(const char nomeArquivo[],
                    int produtoIds[],
                    char descricoes[][50],
                    int max);
        Descrição:
        Lê o arquivo no formato CSV e preenche os arrays de IDs e descrições.
        Parâmetros:
     ok • nomeArquivo[]: nome do arquivo de entrada
     ok • produtoIds[]: array de IDs dos produtos
     ok  • descrições[][50]: array de strings até 49 caracteres
     ok  • max: quantidade máxima de produtos que podem ser carregados nos arrays.
        Retorno:
     ok • Número de registros carregados com sucesso
     ok  • Retorna -1 em caso de erro ao abrir o arquivo
*/

int carregarProdutos(const char nomeArquivo[], int produtoIds[], char descricoes[][50], int max) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        return -1;
    }

    int contador = 0;
    char linha[150];
    
    while (contador < max && fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%d;%49[^\n]", &produtoIds[contador], descricoes[contador]) == 2) {
            contador++;
        }
    }

    fclose(arquivo);
    return contador;
}




/*GY:
    4.
    OK  Função carregarVendas
        int carregarVendas(const char nomeArquivo[],
            int ids[],
            int produtoIds[],
            int quantidades[],
            float precos[],
            int max);
        Descrição:
        Lê os dados de vendas a partir de um arquivo texto e armazena nos arrays paralelos.
        Parâmetros:
     ok • nomeArquivo[]: nome do arquivo de entrada
     ok • ids[]: array de IDs das vendas
     ok • produtoIds[]: array de IDs dos produtos
     ok • quantidades[]: array de quantidades vendidas
     ok • precos[]: array de preços unitários
     ok • max: capacidade máxima dos arrays
        Retorno:
     ok • Número de registros carregados com sucesso
     ok • Retorna -1 em caso de erro ao abrir o arquivo 
*/

// --- FUNÇÃO: carregarVendas ---
int carregarVendas(const char nomeArquivo[], int ids[], int produtoIds[], int quantidades[], float precos[], int max) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    
    if (arquivo == NULL) {
        return -1;
    }

    int contador = 0;
    
    while (contador < max && fscanf(arquivo, "%d %d %d %f",
           &ids[contador],
           &produtoIds[contador],
           &quantidades[contador],
           &precos[contador]) == 4) {
        contador++;
    }

    fclose(arquivo);
    return contador;
}









// --- FUNÇÃO PRINCIPAL ---
int main() {

    // Arrays de produtos
    int produtoIdsCatalogo[MAX];                  //Gy:lista de todos os produto
    char descricoes[MAX][50];  // ✅ CORRIGIDO    //Gy: nome do produto

    // Arrays de vendas
    /* Gy:
    OK 3. Arrays para armazenamento dos dados
        Função carregarVendas
        int carregarVendas(const char nomeArquivo[],
            int ids[],
            int produtoIds[],
            int quantidades[],
            float precos[],
            int max);
            
        Descrição:
        Lê os dados de vendas a partir de um arquivo texto e armazena nos arrays paralelos.
        Parâmetros:
         • nomeArquivo[]: nome do arquivo de entrada
     ok • ids[]: array de IDs das vendas
     ok • produtoIds[]: array de IDs dos produtos
     ok • quantidades[]: array de quantidades vendidas
     ok • precos[]: array de preços unitários
     ok • max: capacidade máxima dos arrays
        Retorno:
     ok • Número de registros carregados com sucesso
     ok • Retorna -1 em caso de erro ao abrir o arquivo 
    */
    int ids[MAX];                                 
    int produtoIds[MAX];                          
    int quantidades[MAX]; //Gy: Quantidades vendidas
    float precos[MAX];

    // Carregar produtos
    int qtdProdutos = carregarProdutos("produtos.csv", produtoIdsCatalogo, descricoes, MAX);

    if (qtdProdutos == -1) {
        printf("Erro ao abrir o arquivo produtos.csv.\n");
        return 1;
    }

    // Carregar vendas
    int qtdVendas = carregarVendas("vendas.txt", ids, produtoIds, quantidades, precos, MAX);

    if (qtdVendas == -1) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        return 1;
    }
    printf("Sucesso! %d produtos e %d vendas carregados.\n\n", qtdProdutos, qtdVendas);





    //GY: Deixei esse pedaço em comentario porque ele é inutil por enquanto
    /*
    // --- PRINT DOS PRODUTOS ---
    printf("=== PRODUTOS ===\n");
    for (int i = 0; i < qtdProdutos; i++) {
        printf("ID: %d | Descricao: %s\n", produtoIdsCatalogo[i], descricoes[i]);
    }

    printf("\n");

    // --- PRINT DAS VENDAS ---
    printf("=== VENDAS ===\n");
    for (int i = 0; i < qtdVendas; i++) {
        printf("Venda ID: %d | Produto ID: %d | Quantidade: %d | Preco: %.2f\n",
               ids[i], produtoIds[i], quantidades[i], precos[i]);
    }

    printf("\n");
    */



    //Menu provisorio

    int digitado;

    printf("1=busca linear\n");
    printf("2=busca binaria\n");
    printf("3=Selection\n");
    printf("0=sair\n");
    scanf(" %d", &digitado);

    

    while(digitado!=0){
        
    
        if (digitado==1 || digitado==2){
            //Função buscaLinear e buscarVendaBinaria
            int idProcurado;
            //Função de busca linear
            printf("Qual id Procurado?");
            scanf(" %d", &idProcurado);

            if (digitado==1){
                buscaLinear(ids, qtdVendas, idProcurado);
            }

            if (digitado==2){
                selectionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas, digitado);
                buscarVendaBinaria(ids, qtdVendas, idProcurado);
            }
        }

        if (digitado==3){
            //Função Selection
            selectionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas, digitado);
        }

    }

    



    return 0;
}
