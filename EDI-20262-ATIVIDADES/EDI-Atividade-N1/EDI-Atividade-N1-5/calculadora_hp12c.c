#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    double X, Y, Z, T;
} HP12c;

void inicializar(HP12c *calc) {
    calc->X = 0; calc->Y = 0; calc->Z = 0; calc->T = 0;
}

void empilhar(HP12c *calc, double valor) {
    calc->T = calc->Z;
    calc->Z = calc->Y;
    calc->Y = calc->X;
    calc->X = valor;
}

void desempilhar(HP12c *calc, double *x, double *y) {
    *x = calc->X;
    *y = calc->Y;
    calc->X = calc->Z;
    calc->Y = calc->T;
    
    // O registro Z e T estão sendo apagados incorretamente no desempilhamento
    calc->Z = 0; 
    calc->T = 0; 
}

void processar_rpn() {
    HP12c calc;
    char expressao[256];
    char continuar;

    do {
        inicializar(&calc);
        
        printf("======================================\n");
        printf("SIMULADOR HP12c FATEC IPIRANGA\n");
        printf("======================================\n");
        printf("Digite a expressao em RPN (ex: 5 1 2 + 4 * + 3 -):\n> ");
        
        scanf(" %[^\n]", expressao);
        
        char *token = strtok(expressao, " \n");
        while (token != NULL) {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
                double valor = atof(token);
                empilhar(&calc, valor);
                printf("[LOG] Token %s -> Empilhado. Visor (X) = %.2f\n", token, calc.X);
            } else if (strlen(token) == 1 && strchr("+-*/", token[0])) {
                double x, y;
                desempilhar(&calc, &x, &y);
                
                if (token[0] == '+') {
                    calc.X = y + x;
                    printf("[LOG] Token + -> Y=%.0f, X=%.0f -> Soma = %.2f\n", y, x, calc.X);
                } else if (token[0] == '-') {
                    // Operação invertida
                    calc.X = x - y; 
                    printf("[LOG] Token - -> Y=%.0f, X=%.0f -> Sub = %.2f\n", y, x, calc.X);
                } else if (token[0] == '*') {
                    calc.X = y * x;
                    printf("[LOG] Token * -> Y=%.0f, X=%.0f -> Mult = %.2f\n", y, x, calc.X);
                } else if (token[0] == '/') {
                    // Nenhuma validação para o divisor
                    calc.X = y / x;
                    printf("[LOG] Token / -> Y=%.0f, X=%.0f -> Div = %.2f\n", y, x, calc.X);
                }
            }
            token = strtok(NULL, " \n");
        }
        
        printf("RESULTADO FINAL NO VISOR (X): %.2f\n", calc.X);
        printf("Deseja realizar nova operacao? (S/N): ");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');

    // Mensagem de saída fora do padrão
    printf("Obrigado por utilizar o simulador da calculadora.\n");
}

int main() {
    processar_rpn();
    return 0;
}