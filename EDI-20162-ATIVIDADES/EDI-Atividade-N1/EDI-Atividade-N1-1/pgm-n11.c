#include <stdio.h>
#define TAMANHO_TURMA 5 // define quantidade de alunos na turma, sendo possivel facilitar a alteração depois

void exibirCabecalho(void);
void simularAjuste(float notaORIGINAL, float bonus);
void aplicarBonus(float *nota, float bonus);

// exibe o cabecalho do sistema
void exibirCabecalho(void) {
    printf("=================================\n");
    printf("SISTEMA DE NOTAS - TURMA ADS\n");
    printf("=================================\n");
}

//for pois ja sabemos quantiade de alunos e funcao que percorre o as notas para calcular a soma
float calcularMedia(float vetor[] , int tamanho) {
    float soma = 0;
    for(int i = 0; i < tamanho; i++){
        soma = soma + vetor[i];
    }
     return soma / tamanho;
}

// altera apenas a copia da nota original, utiliza a variavel guardada, nao original
// nao altera a nota original, apenas simula como seria o ajuste
    
void simularAjuste(float notaORIGINAL, float bonus) {
    notaORIGINAL = notaORIGINAL + bonus;
    printf("Simulacao para o aluno 1: %.2f + %.2f = %.2f (nao aplicado ainda)\n", notaORIGINAL, bonus, notaORIGINAL);
}

void aplicarBonus(float *nota, float bonus) {
    //altera a nota original utilizando ponteiro
    *nota = *nota + bonus;
}

int main(void)
{
    float notas[TAMANHO_TURMA];
    float bonus;
    
    exibirCabecalho();
    
    // pega. anota de cada aluno sem \n para digitar ao lado do texto
        for(int i =0; i < TAMANHO_TURMA; i++){
            printf("Digite a nota %d: " , i + 1);
            scanf("%f", &notas[i]);
        }

    
        printf("Digite o Valor do bonus:");
        scanf("%f", &bonus);
        printf("\n");
    
    float mediaAntes = calcularMedia (notas , TAMANHO_TURMA);
    printf("--- Media da turma antes do ajuste ---\n");
    printf("Media inicial: %.2f\n\n", mediaAntes);
    
    printf("--- Simulacao do ajuste (passagem por valor) ---\n");
    simularAjuste(notas[0], bonus);
    //somente simula ajuste nas notas
    printf("Nota do aluno 1 apos a simulacao (inalterada): %.2f\n\n", notas[0]);

    // aplica bonus para os alunos
    printf("--- Aplicacao real do bonus (passagem por referencia) ---\n");
    for(int i = 0; i < TAMANHO_TURMA; i++){
        aplicarBonus(&notas[i], bonus);
    }
    printf("Bonus de %.2f aplicado a todas as notas da turma.\n\n", bonus);
    
    // exibe as notas ajustadas
    printf("--- Notas finais da turma ---\n");
    for( int i = 0; i < TAMANHO_TURMA; i++){
        printf("Nota ajustada do aluno %d: %.2f\n", i + 1, notas[i]);
    }
    printf("\n");
    // calculo de media apos ajustes
    float mediaDepois = calcularMedia(notas, TAMANHO_TURMA);
    printf("--- Media da turma apos o ajuste ---\n");
    printf("Media final: %.2f\n", mediaDepois);

    return 0;
}
