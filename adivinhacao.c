#include <stdio.h>
#include "advbib.h"
#define MAX_TENTATIVAS 3

void boasvindas(){
    // Output para recepcionar o jogador.
    printf(".................................\n");
    printf(".Bem-vindo ao Jogo de Advinhacao.\n");
    printf(".................................\n");
}

void limparbuffer(){
    // Limpa o lixo do buffer do sistema.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    
    // Declaração de variáveis que serão utilizadas
    const int numerosecreto = 42;
    int chute = 0;  
    int tentativas = 0;
    int truenot = 0;
    int continuar = 1;
    
    while (continuar) {
    boasvindas();
    for (int i = 1; i <= MAX_TENTATIVAS; i++) // Loop infinito até que o usuário acerte o número secreto.
    {       
        tentativas = i;    
       
    printf("\nTentativa %d de %d\n", tentativas, MAX_TENTATIVAS);
    printf("\nQual eh o seu chute? ");
    if (scanf("%d", &chute) != 1) // Inválida caracteres como *, #, etc.
    {
        printf("Entrada invalida! Por favor, insira um numero.\n");
        limparbuffer();
        continue;
    }
    printf("O seu chute foi: %d\n", chute);
    limparbuffer();

    if (chute == numerosecreto){
        printf("Parabens! Voce acertou.\n");
        break;
    } else {
        if (chute > numerosecreto) {
            printf("O seu chute foi maior do que o numero secreto.\n");
            continue;
        }
        if (chute < numerosecreto) {
            printf("O seu chute foi menor do que o numero secreto.\n\n");
            continue;
        }

        limparbuffer();
        continue;
    }
    
    }
    printf(".............\n");
    printf(".Fim de jogo.\n");
    printf(".............\n\n");

    while (1) {
    printf("Deseja jogar novamente?\n");
    printf("1 - SIM\n");
    printf("2 - NAO\n");
    printf("Sua escolha: ");
    if (scanf("%d", &truenot) != 1)
    limparbuffer();
        
    switch (truenot){
        case 1:
           continuar = 1;
           break;

        case 2: 
           printf("\nObrigado por jogar!\n");
           continuar = 0;
           return 0;

        default:
        printf("\nDigite uma opcao valida, por favor.\n\n");
        continue;
    }
    break;
}
}
return 0;
}               