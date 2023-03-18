// Projeto de Jogo de Adivinhação, desenvolvido por Vinicius Ferreira Florencio como parte do curso "C: conhecendo a Linguagem das Linguagens" da plataforma Alura.
// Curso disponível em https://cursos.alura.com.br/course/introducao-a-programacao-com-c-parte-1

// Inserção de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() // Declaração da função principal.
{

    int num_random, num_user, dificuldade, tentativas, sec; // Declaração das variáveis.
    sec = time(0);
    srand(sec);
    num_random = rand() % 100;
    double score = 100;

    printf("*****************************************\n"); // Mensagem de boas-vindas ao jogo.
    printf("* Bem-vindo(a) ao jogo de adivinhacao! *\n");
    printf("*****************************************\n\n");

    printf("O jogo possui tres niveis de dificuldade.\n"); // Mensagem de seleção de dificuldade do jogo.
    printf("Selecione a dificuldade desejada:\n");
    printf("Facil (1) Medio (2) Dificil (3): ");
    scanf("%d", &dificuldade); // Inserção do valor da variável 'dificuldade' pelo usuário.

    switch (dificuldade) // Função 'switch' para alteração da variável 'tentativas' através do valor inserido em 'dificuldade' pelo usuário.
    {

    case 1:
        tentativas = 15;
        break;

    case 2:
        tentativas = 10;
        break;

    default:
        tentativas = 5;
        break;
    }

    printf("\nAgora chute um numero de 0 a 100: ");
    scanf("%d", &num_user); // Início do jogo própriamente dito. Usuário insere um valor na variável 'num_user' que serve como chute no jogo.

    for (int i = 1; i < tentativas; i++)
    {

        if (num_random == num_user) // Se o valor inserido for igual ao valor gerado pelo programa o jogador vence o jogo.
        {
            printf("\nParabens! Voce acertou o numero secreto %d!\n", num_random); // Mensagem de vitória.
            printf("A sua pontuacao foi %.1f!\n", score); // Mensagem de pontuação.
            break; // Quebra do laço de repetição.
        }

        else if (num_random > num_user) // Caso o valor inserido seja menor que o valor do número gerado pelo programa.
        {
            score = score - ((num_random - num_user) / 2.0); // Fórmula de cálculo da pontuação.
            printf("\nO numero inserido e menor que o numero secreto. Tente novamente.\n");
            printf("Tentativa %d de %d.\n", i, tentativas); // Mensagem de alerta da quantidade de tentativas restantes.
            scanf("%d", &num_user);
        }

        else // Caso o valor inserido seja maior que o valor do número gerado pelo programa.
        {
            score = score - ((num_user - num_random) / 2.0); // Fórmula de cálculo da pontuação.
            printf("\nO numero inserido e maior que o numero secreto. Tente novamente.\n");
            printf("Tentativa %d de %d.\n", i, tentativas); // Mensagem de alerta da quantidade de tentativas restantes.
            scanf("%d", &num_user);
        }
    }

    if (num_random != num_user)
    {
        printf("\nVoce nao conseguiu adivinhar o numero secreto. Ele era o numero %d!\n", num_random); // Mensagem caso o jogador não consiga adivinhar o número secreto.

        if (score < 0) // Caso a pontuação seja inferior a 0, exibir mensagem.
        {
            printf("A sua pontuacao foi 0.0!\n");
        }
        else
        {
            printf("A sua pontuacao foi %.1f!\n", score); // Caso seja superior a 0, exibir mensagem.
        }
    }

    system("\npause"); // Aguardar comando do usuário para encerrar o programa.

    return 0;
}
