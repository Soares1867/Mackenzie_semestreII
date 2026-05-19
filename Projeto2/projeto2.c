#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 1000

// =================== FUNÇÕES GERAIS =====================

int encontraIndiceDaDescricao(int produtoIds[], int produtosIdsCatalogo[],int qtdProdutos, int indice){
    for(int i = 0; i < qtdProdutos; i++){
        if (produtoIds[indice] == produtosIdsCatalogo[i]){
            return i;
        }
    }
    return -1;
}

// Função para imprimir
void imprimir(int ids[], int produtoIds[], int quantidades[], float precos[], char descricoes[][50], int produtosIdsCatalogo[], int qtdVendas, int qtdProdutos) {
    printf("\nVendas ordenadas por ID:\n\n");
    printf("--------------------------------------------------------------------------------------------------------\n");
    printf("%-10s | %-12s | %-25s | %-12s | %-16s | %-12s\n", 
        "ID VENDA", "ID PRODUTO", "DESCRICAO", "QUANTIDADE", "PRECO UNITARIO", "TOTAL");
    printf("--------------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < qtdVendas; i++){


        int indiceDesc = encontraIndiceDaDescricao(produtoIds,produtosIdsCatalogo,qtdProdutos, i);

        /*
        for (int j = 0; j < qtdProdutos; j++){
            if (produtoIds[i] == produtosIdsCatalogo[j]){
                indiceDesc = j;
                break; // quando achar o indice da descricao, para o loop de j
            }
        }
        */

        // calcula a ultima coluna
        float total =  precos[i] * quantidades[i];

        if (indiceDesc != -1){ // SE ENCONTROU O ID DO PRODUTO NA TABELA DE ID PRODUTOS E DESCRICOES, IMPRIME NORMALMENTE
            printf("%-10d | %-12d | %-25s | %-12d | R$ %-13.2f | R$ %-12.2f\n",
                ids[i], produtoIds[i], descricoes[indiceDesc], quantidades[i], precos[i], total);
        } else { // SE NAO ENCONTRAR O RESPECTIVO INDICE, COLOCAR NA DESCRICAO "NAO ENCONTRADO"
            printf("%-10d | %-12d | %-25s | %-12d | R$ %-13.2f | R$ %-12.2f\n",
                ids[i], produtoIds[i], "NAO ENCONTRADO", quantidades[i], precos[i], total);            
        }
    }
    printf("--------------------------------------------------------------------------------------------------------\n");

}


// --- FUNÇÃO: carregarProdutos ---
// Funcao para carregar o arquivo .csv, que contem os cadastros dos produtos
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
// Carrega o arquivo de vendas.txt 
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


// --- FUNCAO CALCULAR FATURAMENTO TOTAL ---
float calcularFaturamentoTotal(int quantidades[],float precos[],int n){
    float resultado = 0;
    for (int i = 0; i < n; i++ ){
        resultado += quantidades[i] * precos[i];
    }
    return resultado;
}



// --- FUNCAO ENCONTRAR PRODUTO MAIS VENDIDO  - FALTAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
/*
Descrição: Determina o produtoId com maior quantidade total vendida.
Parâmetros:
    • produtoIds[]: vetor com ids dos produtos de cada venda
    • quantidades[]: quantidades de cada venda
    • n: número de registros
Retorno:
    • ID do produto mais vendido
    • Em caso de empate, retornar o produto com o menor id de produto

int encontrarProdutoMaisVendido(int produtoIds[],int quantidades[],int n){
    return;
}

*/


// ================== FUNCOES DE BUSCA =============================

//-- FUNÇÃO BUSCA LINEAR --
int buscaLinear(int ids[], int qtdVendas, int idProcurado){
    for(int i=0; i<qtdVendas; i++){
        if (idProcurado==ids[i]){
            return i;
        }
    }
    return -1; //caso não encontrado 
}


// -- BUSCA VENDA BINARIA --
//int buscaVendaBinaria(int v[], int n, int valor)
int buscaVendaBinaria(int ids[], int qtdVendas, int idProcurado) {
    int inicio=0;
    int fim=qtdVendas-1;
    //Repetir ate nao restar mais elementos
    while(inicio<=fim){

        //elemento do meio é dado pela formula => meio = inicial + (final - inicial) / 2
        int meio = inicio + (fim - inicio) / 2;
        //na sorte o elemento do meio é exatamente oque procuravamos, ja retorna  e acaba por ai mesmo
        if (ids[meio] == idProcurado) {
            //Retornar a resposta
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

// ================== FUNCOES DE ORDENACAO =============================

// -- BUBBLE SORT --
void bubbleSortVendaPorId(int ids[], int produtoIds[], int quantidades[], float precos[],int qtdVendas){
    for (int contador = 0; contador < qtdVendas - 1; contador++){
        for (int i = 0; i < qtdVendas - 1; i++){
            if (ids[i] > ids[i+1]){

                // troca de id
                int temp_id;
                temp_id = ids[i];
                ids[i] = ids[i+1];
                ids[i+1] = temp_id;
                
                // troca de produtos
                int temp_produtos;
                temp_produtos = produtoIds[i];
                produtoIds[i] = produtoIds[i+1];
                produtoIds[i+1] = temp_produtos;

                // troca de quantidades
                int temp_quantidades;
                temp_quantidades = quantidades[i];
                quantidades[i] = quantidades[i+1];
                quantidades[i+1] = temp_quantidades;

                // troca de preços
                float temp_precos;
                temp_precos = precos[i];
                precos[i] = precos[i+1];
                precos[i+1] = temp_precos;


            }
        }
    }
}
// -- INSERTION SORT --
void insertionSortVendaPorId(int ids[], int produtoIds[], int quantidades[], float precos[], int qtdVendas){
    for (int i = 1; i < qtdVendas; i++) {

        int elemento_ids = ids[i];
        int elemento_produtoIds = produtoIds[i];
        int elemento_quantidades = quantidades[i];
        float elemento_precos = precos[i];

        int j = i - 1;

        bool encontrei = false;

        while(j >= 0 && !encontrei){

            if (ids[j] > elemento_ids){

                ids[j+1] = ids[j];
                produtoIds[j+1] = produtoIds[j];
                quantidades[j+1] = quantidades[j];
                precos[j+1] = precos[j];

                j--;
            }
            else{
                encontrei = true;
            }
        }

        ids[j+1] = elemento_ids;
        produtoIds[j+1] = elemento_produtoIds;
        quantidades[j+1] = elemento_quantidades;
        precos[j+1] = elemento_precos;
    }

}


// -- SELECTION SORT --
void selectionSortVendaPorId(int ids[], int produtoIds[], int quantidades[], float precos[], int qtdVendas) {
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
}


// -- MERGE SORT --

// Funcao auxiliar: Ordena os valores - Mesclando os valores dos dois vetores
void merge(int n1, int n2, // n1 informa qts elementos tem a primeira metade, n2 informa da segunda metade
    int ids[], int ids1[], int ids2[], // chama id e suas partes divididas
    int pids[], int pids1[], int pids2[], // chama produtoIds e suas partes divididas
    int qtd[], int qtd1[], int qtd2[], // chama quantidades e suas partes
    float precos[], float precos1[], float precos2[]) // chama precos e suas particoes
    {

        // INICIALIZA OS INDICES PARA OS VETORES
        int i = 0; // vetor inteiro
        int i1 = 0; // primeira metade
        int i2 = 0; // segunda metade
        
        while (i1 < n1 && i2 < n2){ // Enquanto não acabar todos os elementos de um vetor, vai continuar iterando

            if(ids1[i1] < ids2[i2]) // se o elemento da metade e for menor que o elemento da metade 2
            { 
                ids[i] = ids1[i1]; //vetor completo recebe o valor da primeira parte
                pids[i] = pids1[i1];
                qtd[i] = qtd1[i1];
                precos[i] = precos1[i1];

                i1++;
            } else {
                ids[i] = ids2[i2]; //vetor completo recebe o valor da segunda metade
                pids[i] = pids2[i2];
                qtd[i] = qtd2[i2];
                precos[i] = precos2[i2];

                i2++;
            }
            i++;
        }

        // QUANDO ACABAR UM DOS DOIS VETORES, VAI PARTIR PARA CÁ
        // Vai copiar os elementos que sobrarem na metade 1 ou 2 para o vetor completo
        while(i1 < n1){ // caso seja o vetor da metade 1 que sobrar, entrará nessa iteracao
            ids[i] = ids1[i1]; //vetor completo recebe o valor da primeira parte
            pids[i] = pids1[i1];
            qtd[i] = qtd1[i1];
            precos[i] = precos1[i1];
            i1++;
            i++;
        }

        while (i2 < n2){ // caso seja o vetor da metade 2 que sobrar
            ids[i] = ids2[i2]; //vetor completo recebe o valor da segunda metade
            pids[i] = pids2[i2];
            qtd[i] = qtd2[i2];
            precos[i] = precos2[i2];
            i2++;
            i++;
        }

}

// Divide os valores
void mergeSortVendaPorId(int ids[], int produtoIds[],int quantidades[],float precos[],int qtdVendas){
    // VER ONDE ESSE inicio E fim DO PARAMETRO VAO SE ENCAIXAR, SE NAO CONSEGUIR, VOU RETIRAR, ADICIONEI O qtdVendas como n do exemplo na sala
    
    if (qtdVendas<=1){return;} // CASO BASE DA FUNCAO RECURSIVA, PARA TER UM PONTO DE PARADA E NAO CRIAR UMA RECURSIVIDADE INFINITA
    
    int meio = qtdVendas / 2;  // encontra a metade da lista
    int n1 = meio; // define que a primeira parte definida terá seu limite maximo o valor de meio
    int n2 = qtdVendas - meio; // define que a segunda parte tem seu limite maximo o que sobrar da operacao do total - meio, formula para operar em casos de quantidade impares
    
    int ids1[n1], ids2[n2]; //PARA DIVIDIR ids[] -- declara a metade 1 e a metade 2
    int produtoIds1[n1], produtoIds2[n2]; // PARA DIVIDIR produtosIds[]
    int quantidades1[n1], quantidades2[n2]; // PARA DIVIDIR quantidades[]
    float precos1[n1], precos2[n2]; // PARA DIVIDIR precos[]

    for (int i = 0; i < n1; i++){ //PRIMEIRA METADE RECEBE SEUS VALORES
        ids1[i] = ids[i];
        produtoIds1[i] = produtoIds[i];
        quantidades1[i] = quantidades[i];
        precos1[i] = precos[i];

    }
    for (int i = 0; i < n2; i++){ // SEGUNDA METADE RECEBE SEUS VALORES
        ids2[i] = ids[meio+i];
        produtoIds2[i] = produtoIds[meio+i];
        quantidades2[i] = quantidades[meio+i];
        precos2[i] = precos[meio+i];

    }
    // ordena a primeira metade fazendo a recursividade (vai quebrar essa parte em partes menores)
    mergeSortVendaPorId(ids1, produtoIds1, quantidades1, precos1, n1);
    
    // ordena a segunda metade fazendo a recursividade (vai quebrar essa parte em partes menores)
    mergeSortVendaPorId(ids2, produtoIds2, quantidades2, precos2, n2);

    // chama a funcao auxiliar para realizar a mesclagem (MERGE) dos dados ja divididos em suas respectivas partes
    merge(n1, n2, ids, ids1, ids2, produtoIds, produtoIds1, produtoIds2, quantidades, quantidades1, quantidades2, precos, precos1, precos2);

}


// ========= FUNCAO MAIN ==========
int main(){
    // ARRAYS DO ARQUIVO produto.csv (contendo o id e o nome de cada produto catalogado)
    int produtoIdsCatalogo[MAX];//lista de todos os produtos
    char descricoes[MAX][50];   // nome do produto

    // ARRAY DAS VENDAS do arquivo vendas.txt, contendo todas as vendas com suas respectivas informaçôes
    int ids[MAX];        // ID DA VENDA                    
    int produtoIds[MAX]; // ID DO PRODUTO VENDIDO                      
    int quantidades[MAX]; //Quantidades vendidas
    float precos[MAX]; // PREÇO VENDIDO ***UNITARIO*** DO PRODUTO

    // CARREGA PRODUTOS - carrega os produtos catalogados - carrega o arquivo produtos.csv
    int qtdProdutos = carregarProdutos("produtos.csv", produtoIdsCatalogo, descricoes, MAX);

    if (qtdProdutos == -1) {
        printf("Erro ao abrir o arquivo produtos.csv.\n");
        return 1;
    }

    // CARREGAR VENDAS - Carrega as vendas realizadas - carrega o arquivo vendas.txt
    int qtdVendas = carregarVendas("vendas.txt", ids, produtoIds, quantidades, precos, MAX);

    if (qtdVendas == -1) {
        printf("Erro ao abrir o arquivo vendas.txt.\n");
        return 1;
    }
    printf("%d produtos e %d vendas carregados com sucesso.\n", qtdProdutos, qtdVendas);

    int precisaOrdenar = 1; // Para aplicar a logica de ordenar somente uma vez, assim que for ordenado pela primerira vez, nao precisara novamente

    int opcao;
    while(1) {
        printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("        SISTEMA DE ANALISE DE DADOS DE VENDAS        \n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("1. Mostrar Vendas por ID\n"
            "2. Buscar Vendas por ID\n"
            "3. Calcular Faturamento Total\n"
            "4. Identificar produto mais vendido\n"
            "5. Sair da aplicacao\n"
            "ESCOLHA UMA OPCAO: ");
        scanf("%d", &opcao);

        switch(opcao){
            case 1: { // MOSTRAR VENDAS POR ID - abre o submenu para escolher o algoritmo de ordenacao
                if (precisaOrdenar == 0){ // se nao precisa ordenar, entao so imprime
                    imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                } else {
                    int opcaoVendas;
                    int controleSubMenuVendas = 1; // para definir o ponto de parada do while (exemplificando no primeiro subcase)
                    while(controleSubMenuVendas){
                        printf("\n\n\nEscolha o algoritmo de ordenacao:\n\n"
                            "1. Bubble Sort\n"
                            "2. Insertion Sort\n"
                            "3. Selection Sort\n"
                            "4. Quick Sort\n"
                            "5. Merge Sort\n"
                            "6. Retornar ao menu principal\n\n"
                            "ESCOLHA UMA OPCAO: "
                        );
                        scanf("%d", &opcaoVendas);
                        switch (opcaoVendas)    {
                            case 1:{ //BUBBLE SORT
                                bubbleSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas);
                                imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                                controleSubMenuVendas = 0; // neste ponto, assim que a funcao for chamada e realizada, vai parar o while
                                precisaOrdenar = 0;
                                break; // o break vai sair do laço do switch case interno / subcase (esse para escolher o bubble)
                            }
                            case 2: { // INSERTION SORT
                                insertionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas);
                                imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                                controleSubMenuVendas = 0; 
                                precisaOrdenar = 0;
                                break;
                            }
                            case 3: { // SELECTION SORT
                                selectionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas);
                                imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                                controleSubMenuVendas = 0; 
                                precisaOrdenar = 0;
                                break;
                            }
                            case 4: { // QUICK SORT
                                //quickSortVendaPorId();
                                //imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                                controleSubMenuVendas = 0; 
                                precisaOrdenar = 0;
                                break;
                            }
                            case 5: { // MERGE SORT
                                mergeSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas);
                                imprimir(ids, produtoIds, quantidades, precos, descricoes, produtoIdsCatalogo, qtdVendas, qtdProdutos);
                                controleSubMenuVendas = 0; 
                                precisaOrdenar = 0;
                                break;
                            }
                            case 6: { // RETORNA AO MENU PRINCIPAL
                                controleSubMenuVendas = 0; 
                                break;
                            }
                            default:{ // CASO DE ERRO
                                printf("OPCAO INVALIDA. DIGITE UMA OPCAO EXISTENTE");
                                break;
                            }
                        }
                    }
                }
            }
            break;
            case 2: { // BUSCAR VENDAS POR ID - abre o submenu para escolher o algoritmo de busca
                int opcaoBusca;
                int controleSubMenuBusca = 1;
                int idProcurado;
                printf("Digite o ID do produto procurado: ");
                scanf("%d", &idProcurado);
                while(controleSubMenuBusca){
                    printf("\n\nEscolha o algoritmo de busca:\n"
                    "  1. Busca Linear\n"
                    "  2. Busca Binaria\n"
                    "  3. Retornar ao menu principal\n"
                    "ESCOLHA UMA OPCAO: ");
                    scanf("%d", &opcaoBusca);
                    
                    switch (opcaoBusca){
                    case 1:{
                        int indicebusca = buscaLinear(ids, qtdVendas, idProcurado);
                        if (indicebusca == -1){
                            printf("ID DE VENDA NAO ENCONTRADO");
                        } else {

                            int indicedescricao = encontraIndiceDaDescricao(produtoIds,produtoIdsCatalogo,qtdProdutos, indicebusca);

                            printf("\nVenda encontrada:\n");
                            printf("ID Venda: %d\n", ids[indicebusca]);
                            printf("Produto: %d\n", produtoIds[indicebusca]);
                            if (indicedescricao = -1) {
                                printf("Descricao: NAO ENCONTRADO");
                            } else {
                            printf("Descricao: %s\n", descricoes[indicedescricao]);
                            }
                            printf("Quantidade: %d\n", quantidades[indicebusca]);
                            printf("Preco unitario: %.2f\n", precos[indicebusca]);
                            printf("Total da venda: %.2f\n", precos[indicebusca] * quantidades[indicebusca]);

                        }
                        controleSubMenuBusca = 0; // neste ponto, assim que a funcao for chamada e realizada, vai parar o while
                        break; // o break vai sair do laço do switch case interno / subcase (esse para escolher o linear)
                    }
                    case 2: {                      
                        if (precisaOrdenar) {
                            mergeSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas);
                            precisaOrdenar = 0;
                        }
                        int indicebusca = buscaVendaBinaria(ids, qtdVendas, idProcurado);
                        if (indicebusca == -1){
                            printf("ID DE VENDA NAO ENCONTRADO");
                        } else {
                            int indicedescricao = encontraIndiceDaDescricao(produtoIds,produtoIdsCatalogo,qtdProdutos, indicebusca);
                            printf("\nVenda encontrada:\n");
                            printf("ID Venda: %d\n", ids[indicebusca]);
                            printf("Produto: %d\n", produtoIds[indicebusca]);
                            if (indicedescricao = -1) {
                                printf("Descricao: NAO ENCONTRADO");
                            } else {
                            printf("Descricao: %s\n", descricoes[indicedescricao]);
                            }
                            printf("Quantidade: %d\n", quantidades[indicebusca]);
                            printf("Preco unitario: %.2f\n", precos[indicebusca]);
                            printf("Total da venda: %.2f\n", precos[indicebusca] * quantidades[indicebusca]);

                        controleSubMenuBusca = 0;
                        break;
                    }
                    case 3: {
                        controleSubMenuBusca = 0;
                        break;
                    }
                    default:{
                        printf("OPCAO INVALIDA. DIGITE UMA OPCAO VALIDA");
                        break;
                    }
                    }
                }
                break;
            }
            case 3: { // CALCULAR FATURAMENTO TOTAL
                float faturamento = calcularFaturamentoTotal(quantidades, precos, qtdVendas);
                printf("Faturamento total: R$ %.2f\n", faturamento);
                break;
            }
            case 4: { // IDENTIFICAR O PRODUTO MAIS VENDIDO
                //encontrarProdutoMaisVendido()
                break;
            }
            case 5: { // SAIR DA APLICACAO / FINALIZAR O PROGRAMA
                printf("Finalizando o programa");
                return 0; // FINALIZA O PROGRAMA

            }
            default: { // CASO DE ERRO
                printf("\nOPCAO INVALIDA, DIGITE UMA OPCAO VALIDA");
                break;
            }

            } 
        }
    }
    return 0;
}
