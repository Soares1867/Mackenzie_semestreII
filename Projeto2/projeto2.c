#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000

// =================== FUNÇÕES GERAIS =====================

// Função para imprimir após a ordenação
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

/*Gy:
    4.
        Função carregarProdutos
                    int carregarProdutos(const char nomeArquivo[],int produtoIds[],char descricoes[][50],int max);
        Descrição: Lê o arquivo no formato CSV e preenche os arrays de IDs e descrições.
        Parâmetros:
     ok • nomeArquivo[]: nome do arquivo de entrada
     ok • produtoIds[]: array de IDs dos produtos
     ok  • descrições[][50]: array de strings até 49 caracteres
     ok  • max: quantidade máxima de produtos que podem ser carregados nos arrays.
        Retorno:
     ok • Número de registros carregados com sucesso
     ok  • Retorna -1 em caso de erro ao abrir o arquivo
*/

// Funçâo para carregar o arquivo .csv, que contém os cadastros dos produtos
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

/*
Função calcularFaturamentoTotal
Descrição: Calcula o faturamento total somando quantidade * preço de todas as vendas.
Parâmetros:
    • quantidades[]
    • precos[]
    • n: número de registros
Retorno:
    • Valor total do faturamento (float)
*/
// --- FUNCAO CALCULAR FATURAMENTO TOTAL ---
float calcularFaturamentoTotal(int quantidades[],float precos[],int n){
    float resultado = 0;
    for (int i = 0; i < n; i++ ){
        resultado += quantidades[i] * precos[i];
    }
    return resultado;
}


// --- FUNCAO ENCONTRAR PRODUTO MAIS VENDIDO
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


// ================== FUNÇÔES DE BUSCA =============================

/*
GY:
    Função buscaLinear
OK  int buscaLinear(int ids[], int n, int idProcurado);
    Descrição: Realiza busca sequencial no array de IDs.
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
            printf("O ID do produto se encontra na posicao %d\n",i);
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


//int buscaVendaBinaria(int v[], int n, int valor)
int buscaVendaBinaria(int ids[], int qtdVendas, int idProcurado) {
    int inicio=0;
    int fim=qtdVendas-1;
    //Repetir ate nao restar mais elementos
    while(inicio<=fim){

        //elemento do meio é dado pela formula do professor => meio = inicial + (final - inicial) / 2
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



// ================== FUNÇÔES DE ORDENAÇÃO =============================

//Função bubbleSortVendaPorId 
/*Gy:
    Função bubbleSortVendaPorId
        void bubbleSortVendaPorId(int ids[], int produtoIds[], int quantidades[], float precos[],int n);
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
        void insertionSortVendaPorId(int ids[],int produtoIds[],int quantidades[],float precos[],int n);
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
        void selectionSortPorId(int ids[],int produtoIds[],int quantidades[],float precos[],int n);
    Descrição:
    Ordena os dados em ordem crescente de id utilizando o algoritmo Selection Sort.
    Parâmetros:
    • Arrays paralelos (ids, produtoIds, quantidades, precos)
    • n: número de elementos
    Retorno:
    • Não possui retorno 
*/

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
    // EDU: ALTERAR ESSE IF DEPOIS, POIS NA BUSCA BINARIA NAO SERA ORDENADA COM O SELECTION SORT
    // EDU: TAMBEM REMOVER O DIGITADO COMO UM PARAMETRO NA LINHA DA FUNCAO
    if (digitado==1){
        imprimir(ids, produtoIds, quantidades, precos, qtdVendas);
    }
}


int main(){
    // ARRAYS DO ARQUIVO produto.csv (contendo o id e o nome de cada produto catalogado)
    int produtoIdsCatalogo[MAX];//Gy:lista de todos os produtos
    char descricoes[MAX][50];   //Gy: nome do produto

    // ARRAY DAS VENDAS do arquivo vendas.txt, contendo todas as vendas com suas respectivas informaçôes
    int ids[MAX];        // ID DA VENDA                    
    int produtoIds[MAX]; // ID DO PRODUTO VENDIDO                      
    int quantidades[MAX]; //Gy: Quantidades vendidas
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
    printf("Sucesso! %d produtos e %d vendas carregados.\n\n", qtdProdutos, qtdVendas);


    int opcao;
    while(1) {
        printf("\n\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
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
            case 1: { // MOSTRAR VENDAS POR ID - abre o submenu
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
                            //bubbleSortVendaPorId();
                            controleSubMenuVendas = 0; // neste ponto, assim que a funcao for chamada e realizada, vai parar o while
                            break; // o break vai sair do laço do switch case interno / subcase (esse para escolher o bubble)
                        }
                        case 2: { // INSERTION SORT
                            //insertionSortVendaPorId();
                            controleSubMenuVendas = 0; 
                            break;
                        }
                        case 3: { // SELECTION SORT
                            //  EDU: ALTERAR DEPOIS EXCLUINDO O PARAMETRO opcao, EXPLICACAO NA FUNCAO DO SELECTION
                            selectionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas, opcao);
                            controleSubMenuVendas = 0; 
                            break;
                        }
                        case 4: { // QUICK SORT
                            //quickSortVendaPorId();
                            controleSubMenuVendas = 0; 
                            break;
                        }
                        case 5: { // MERGE SORT
                            //mergeSortVendaPorId();
                            controleSubMenuVendas = 0; 
                            break;
                        }
                        case 6: {
                            controleSubMenuVendas = 0; 
                            break;
                        }
                        default:{
                            printf("OPCAO INVALIDA. DIGITE UMA OPCAO EXISTENTE");
                            break;
                        }
                    }
                }
            }
            break;
            case 2: { // BUSCAR VENDAS POR ID - abre o submenu
                    int opcaoBusca;
                    int controleSubMenuBusca = 1;
                while(controleSubMenuBusca){
                    printf("\n\nEscolha o algoritmo de busca:\n"
                    "1. Busca Linear\n"
                    "2. Busca Binaria\n"
                    "3. Retornar ao menu principal\n"
                    "ESCOLHA UMA OPCAO: ");
                    scanf("%d", &opcaoBusca);
                    
                    switch (opcaoBusca){
                    case 1:{
                        int idProcurado;
                        printf("Digite o ID do produto procurado: ");
                        scanf("%d", &idProcurado);
                        buscaLinear(ids, qtdVendas, idProcurado);
                        controleSubMenuBusca = 0; // neste ponto, assim que a funcao for chamada e realizada, vai parar o while
                        break; // o break vai sair do laço do switch case interno / subcase (esse para escolher o linear)
                    }
                    case 2: {
                        int idProcurado;
                        printf("Digite o ID do produto procurado: ");
                        scanf("%d", &idProcurado);   
                        // EDU: MUDAR O METODO DE ORDENACAO PARA OU MERGE OU QUICK SORT                     
                        selectionSortVendaPorId(ids, produtoIds, quantidades, precos, qtdVendas, opcao);
                        buscaVendaBinaria(ids, qtdVendas, idProcurado);
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
            default: {
                printf("\nOPCAO INVALIDA, DIGITE UMA OPCAO VALIDA");
                break;
            }
        }
    }
        return 0;
}
