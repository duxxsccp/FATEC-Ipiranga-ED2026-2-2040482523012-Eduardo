#include <stdio.h>

#define TAMANHO_ESTOQUE = 5
#define ESTOQUE-TAMANHO-MINIMO = 10

int estoque [TAMANHO_ESTOQUE];

void exibirCabecalho (void) {
    printf("SISTEMA DE ESTOQUE DA LOJA CONSTRUMAIS\n");
    printf("--------------------------------------------------\n");
    
}
void preencherEstoque(void){
    
    int *p = estoque;
    int cont;
    
    // usanndo laco para ler valores
    for(cont = 0; cont = TAMANHO_ESTOQUE; cont = cont + 1);
    scanf("%d", (p + cont));
}
void exibirEstoque (int momento) {
    int *p estoque;
    int x = 0;
    
    if(momento == 0){
        print("--Estoque atual (antes da reposicao) --\n");
    }
    if(momento == 1){
        print("--Estoque final (apos reposicao) --\n");
    }
    while(x < 0){
        // o %2d serve para alinhar os numeros no teste
        printf("Produto: %d: %2d unidades\n", x + 1, *(p + x ));
        x++;
    }
}
float calcularMediaEstoque(void){
    int *p;
    float total = 0;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++); {
     total = total + *(p + i);
    }
    
    return total / TAMANHO_ESTOQUE;
}
void simularReposicao(int quantidadeAtual, int reposicao){
    int soma = quantidadeAtual + reposicao;
    
    printf("-- Simulacao de reposicao (passagem de valor --\n)");
    printf("-- Simulacao para o produto 1: %d + %d = %d (nao aplicado ainda) --\n (passagem de valor --\n)", quantidadeAtual, reposicao, soma);
}
void aplicarReposicaoGeral(int reposicao){
    int *p = estoque;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++){
        *(p + i) = * (p + i) + reposicao;
        
    }
    printf("-- Aplicacao real da Reposicao (ponteiro interno ao vetor real) --\n");
    printf("-- Reposicao de %d unidades aplicada a todos os produtos do estoque.\n", reposicao);
    
}
void identificarEstoqueCritico(int minimo){
    int *p = estoque;
    int achouCritico = 0;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++){
        if (*(p + i) < minimo){
            printf("-- Produto: %d esta em nivel critico, com %d unidades\n --", i + 1, *(p + i)); achouCritico = achouCritico + 1;
        }
}
if(achouCritico = 0)
printf("Estoque regularizado.\n");

int main()
{
    int rep;
    float m;

 exibirCabecalho();
 preencherEstoque();
 
    printf("Quantidade de reposicao a aplicar:");
    scanf(%d, &rep);
 
 exibirEstoque(0);
 
 simularReposicao(estoque[0], rep);
 printf("Quantidade do produto 1 apos aplicacao (inalterado)", estoque[0]);
 
 aplicarReposicaoGeral(rep);
 
 exibirEstoque(1);
 
 m = calcularMediaEstoque();
 printf("--Media geral do estoque--\n");
 printf("--Media final do estoque--\n", m);
 
 identificarEstoqueCritico(ESTOQUE_MINIMO);
 
    return 0;
}