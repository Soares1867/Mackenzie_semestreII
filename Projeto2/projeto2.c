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
int buscaLinear(int ids[], int n, int idProcurado){
    for(int i=0; i<n; i++){
        if (idProcurado==ids[i]){
            printf("O id esta na posicao %d",i);
            return i;
        }
    }
    

    return -1; //caso não encontrado 
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




    
    //Função buscaLinear
    int idProcurado;
    int n=MAX;
    //Função de busca linear
    printf("Qual id Procurado?");
    scanf(" %d", &idProcurado);
    buscaLinear(ids, n, idProcurado);




    return 0;
}


