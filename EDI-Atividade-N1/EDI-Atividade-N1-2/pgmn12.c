#include <stdio.h>

#define TAMANHO_ESTOQUE 5
#define ESTOQUE_TAMANHO_MINIMO 10

int estoque [TAMANHO_ESTOQUE];


void exibirCabecalho (void) {
    printf("SISTEMA DE ESTOQUE - LOJA CONSTRUMAIS\n");
    printf("--------------------------------------------------\n");
    
}
void preencherEstoque(void){
    
    int *p = estoque;
    int cont;
    
    // usanndo laco para ler valores
    for(cont = 0; cont < TAMANHO_ESTOQUE; cont = cont + 1){
        printf("Qauntidade do produto %d: ", cont + 1);
        scanf("%d", (p + cont));
    }
}
void exibirEstoque (int momento) {
    int *p = estoque;
    int x = 0;
    
    if(momento == 0){
        print("--Estoque atual (antes da reposicao) --\n");
    }
    if(momento == 1){
        print("--Estoque final (apos reposicao) --\n");
    }
    while(x < TAMANHO_ESTOQUE){
        // o %2d serve para alinhar os numeros no teste, e while para variar um pouco tambem
        printf("Produto: %d: %2d unidades\n", x + 1, *(p + x ));
        x++;
    }
}
float calcularMediaEstoque(void){
    int *p = estoque;
    float total = 0;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++) {
        //(p + i) eh o espaco da memoria em si (endereco)
        //*(p + i) eh o valor de verdade q ta guardado la dentro
     total = total + *(p + i);
    }
    
    return total / TAMANHO_ESTOQUE;
}
void simularReposicao(int quantidadeAtual, int reposicao){
    int soma = quantidadeAtual + reposicao;
    
    //passagem por valor simples pois eh somente simulacao, vetor global continua intacto
    printf("-- Simulacao de reposicao (passagem de valor --\n)");
    printf("-- Simulacao para o produto 1: %d + %d = %d (nao aplicado ainda) --\n (passagem de valor --\n)", quantidadeAtual, reposicao, soma);
}
void aplicarReposicaoGeral(int reposicao){
    int *p = estoque;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++){
        // conta direto no endereco do ponteiro, alterando o valor do vetor glocal
        *(p + i) = * (p + i) + reposicao;
        
    }
    printf("-- Aplicacao real da Reposicao (ponteiro interno ao vetor real) --\n");
    printf("-- Reposicao de %d unidades aplicada a todos os produtos do estoque.\n", reposicao);
    
}
void identificarEstoqueCritico(int minimo){
    int *p = estoque;
    // variavel flag
    int achouCritico = 0;
    int i;
    
    for(i = 0; i < TAMANHO_ESTOQUE; i++){
        if (*(p + i) < minimo){
            printf("-- Produto: %d esta em nivel critico, com %d unidades\n --", i + 1, *(p + i));
            // achou divergencia no estoque
            achouCritico = achouCritico + 1;
        }
    }
}
// nao achou nada abaixo do minimo
if(achouCritico == 0)
printf("Estoque regularizado.\n");

int main()
{
    int rep;
    float m;

 exibirCabecalho();
 preencherEstoque();
 
    printf("Quantidade de reposicao a aplicar:");
    scanf("%d, &rep);
 
 exibirEstoque(0);
 
 simularReposicao(estoque[0], rep);
 printf("Quantidade do produto 1 apos aplicacao (inalterado): %d\n", estoque[0]);
 
 aplicarReposicaoGeral(rep);
 
 exibirEstoque(1);
 
 m = calcularMediaEstoque();
 printf("--Media geral do estoque--\n");
 printf("--Media final do estoque: %.2f --\n", m);
 
 identificarEstoqueCritico(ESTOQUE_MINIMO);
 
    return 0;
}
