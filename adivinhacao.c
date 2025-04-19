#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "advbib.h"

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
    srand(time(NULL));
    int numerosecreto = rand() % 100;
    int chute = 0;  
    int tentativas = 0;
    int truenot = 0;
    int continuar = 1;
    int dificuldade = 0;
    int max_tentativas = 0;
    
    while (continuar) {
    int pontos = 1000;
    int pontosperdidos =0;
    boasvindas();
    printf("\nEscolha o nivel de dificuldade:\n ");
    printf("\n1 - Facil\n2 - Medio\n3 - Dificil\n");
    printf("\nInforme sua escolha: ");
    if (scanf("%d", &dificuldade) != 1) {
        printf("Entrada invalida! Por favor, insira um numero.\n");
        limparbuffer();
        continue;
    }
    printf("\n");
    if (dificuldade == 1){  
        max_tentativas = 20;
    } else if (dificuldade == 2) {
        max_tentativas = 15;
    } else {
        max_tentativas = 6;
    }
    
    for (int i = 1; i <= max_tentativas; i++)
    {       
        tentativas = i;    
       
    printf("Tentativa %d de %d\n", tentativas, max_tentativas);
    printf("\nQual eh o seu chute? ");
   
    if (scanf("%d", &chute) != 1) // Inválida caracteres como *, #, etc.
    {
        printf("Entrada invalida! Por favor, insira um numero.\n");
        limparbuffer();
        continue;
    }
    pontos = pontos - (double)(abs(numerosecreto - chute)/2.0);
    pontosperdidos = 1000 - (double)pontos;
    if (pontos < 0){
        pontos = 0;
    }
    printf("O seu chute foi: %d\n", chute);
    limparbuffer();

    if (chute == numerosecreto){
        printf("Parabens! Voce acertou.\n");
        break;
    } else if (chute > numerosecreto) {
        printf("O seu chute foi maior do que o numero secreto.\n");
    } else {
        printf("O seu chute foi menor do que o numero secreto.\n");
        } if (tentativas == max_tentativas) {
        printf("\nOPS! AS TENTATIVAS ESGOTARAM-SE.\n");
        }
        
    }
    printf("\nVoce fez %d de 1000 pontos\n", pontos);
    printf("Pontos perdidos: %d\n\n", pontosperdidos);
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