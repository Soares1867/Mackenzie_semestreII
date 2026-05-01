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

// --- FUNÇÃO: carregarProdutos ---
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
    int produtoIdsCatalogo[MAX];
    char descricoes[MAX][50];  // ✅ CORRIGIDO

    // Arrays de vendas
    int ids[MAX];
    int produtoIds[MAX];
    int quantidades[MAX];
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

    return 0;
}

