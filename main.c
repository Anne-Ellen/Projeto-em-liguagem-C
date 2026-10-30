#include <stdio.h>
#include <stdlib.h> 
#include <locale.h> // Biblioteca necessária para acentuar

int main(void) {

    setlocale(LC_ALL, "Portuguese");

    int configValida = 1;

    // Configuração inicial
    int equipes, jogos, opcao = 0, i;

    // Variáveis 
    int vitorias = 0, empates = 0, derrotas = 0, pontos = 0;

    // Variávei Acumuladoras
    int registroCompleto = 0;
    int totalVitorias = 0, totalEmpates = 0, totalDerrotas = 0, somaPontos = 0;
    int qtdExcelente = 0, qtdBoa = 0, qtdRegular = 0, qtdRuim = 0;
    int maiorPontuacao = 0, equipeMaior = 0, qtdEmpatadosMaior = 0;
    int menorPontuacao = 0, equipeMenor = 0, qtdEmpatadosMenor = 0;
    float mediaPontos = 0;

    // Variáveis da Simulação
    int qtdSimulacoes, s, simVitorias, simEmpates, simDerrotas, simPontos;

    // Número de equipes
    while (1) {
        printf("Informe a quantidade de equipes (de 3 a 10):\n");
        scanf("%d", &equipes);

        if (equipes < 3 || equipes > 10) {
            printf("Valor inválido! Tente novamente.\n\n");
        }
        else {
            break;
        }
    }

    // Número de jogos
    while (1) {
        printf("Informe a quantidade de jogos (de 1 a 10):\n");
        scanf("%d", &jogos);

        if (jogos < 1 || jogos > 10) {
            printf("Valor inválido! Tente novamente.\n\n");
        }
        else if (jogos != equipes - 1) {
            printf("Valor inválido! Com %d equipes, cada uma joga %d jogos.\n\n", equipes, equipes - 1);
        }
        else {
            break;
        }
    }

    printf("\nTodas as %d equipes disputaram %d jogos cada.\n", equipes, jogos);

    // Menu principal
    while (opcao != 5) {

        printf("\n==================MENU====================\n");
        printf("1 - Registrar resultados do campeonato\n");
        printf("2 - Mostrar resumo do campeonato\n");
        printf("3 - Mostrar regulamento\n");
        printf("4 - Simular campanha de uma equipe\n");
        printf("5 - Encerrar sistema\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {

        case 1:
            // Acumuladores Reiniciadas
            registroCompleto = 0;
            totalVitorias = 0;
            totalEmpates = 0;
            totalDerrotas = 0;
            somaPontos = 0;
            qtdExcelente = 0;
            qtdBoa = 0;
            qtdRegular = 0;
            qtdRuim = 0;
            maiorPontuacao = 0;
            equipeMaior = 0;
            qtdEmpatadosMaior = 0;
            menorPontuacao = 0;
            equipeMenor = 0;
            qtdEmpatadosMenor = 0;

            for (i = 1; i <= equipes; i++) {

                printf("\nA soma das vitórias, empates e derrotas deve ser igual a quantidade de jogos (%d).", jogos);

                // Teste de Válidade 
                while (1) {
                    printf("\nInforme quantas vitórias a equipe %d tem:\n", i);
                    scanf("%d", &vitorias);

                    printf("Informe quantos empates a equipe %d tem:\n", i);
                    scanf("%d", &empates);

                    printf("Informe quantas derrotas a equipe %d tem:\n", i);
                    scanf("%d", &derrotas);

                    if (vitorias < 0 || empates < 0 || derrotas < 0) {
                        printf("Inválido! Digite apenas números positivos.\n");
                    }
                    else if (vitorias + empates + derrotas != jogos) {
                        printf("Inválido! A soma dos valores deve ser igual a quantidade de jogos (%d).\n", jogos);
                    }
                    else {
                        break;
                    }
                }

                pontos = (3 * vitorias) + empates + (derrotas * 0);

                printf("\nEquipe %d: %d vitórias, %d empates e %d derrotas\n", i, vitorias, empates, derrotas);
                printf("Pontuação: %d pontos\n", pontos);

                // Campanha + Contagem por situação
                if (pontos >= 15) {
                    printf("Situação: Excelente campanha\n");
                    qtdExcelente++;
                }
                else if (pontos >= 10) {
                    printf("Situação: Boa campanha\n");
                    qtdBoa++;
                }
                else if (pontos >= 5) {
                    printf("Situação: Campanha regular\n");
                    qtdRegular++;
                }
                else {
                    printf("Situação: Campanha ruim\n");
                    qtdRuim++;
                }

                // Total
                totalVitorias += vitorias;
                totalEmpates += empates;
                totalDerrotas += derrotas;
                somaPontos += pontos;

                // Maior e menor pontuação
                if (i == 1) {
                    maiorPontuacao = pontos;
                    equipeMaior = i;
                    qtdEmpatadosMaior = 1;
                    menorPontuacao = pontos;
                    equipeMenor = i;
                    qtdEmpatadosMenor = 1;
                }
                else {
                    if (pontos > maiorPontuacao) {
                        maiorPontuacao = pontos;
                        equipeMaior = i;
                        qtdEmpatadosMaior = 1;
                    }
                    else if (pontos == maiorPontuacao) {
                        qtdEmpatadosMaior++;
                    }

                    if (pontos < menorPontuacao) {
                        menorPontuacao = pontos;
                        equipeMenor = i;
                        qtdEmpatadosMenor = 1;
                    }
                    else if (pontos == menorPontuacao) {
                        qtdEmpatadosMenor++;
                    }
                }
            }

            // Registro só é completo depois de validar todas as equipes
            registroCompleto = 1;
            printf("\nRegistro concluído!\n");
            break;

        case 2:
            if (registroCompleto == 0) {
                printf("Registre os resultados primeiro.\n");
            }
            else {
                mediaPontos = (float)somaPontos / equipes;

                printf("\n=== RESUMO DO CAMPEONATO ===\n");
                printf("Quantidade de equipes: %d\n", equipes);
                printf("Jogos por equipe: %d\n", jogos);
                printf("Total de vitórias: %d\n", totalVitorias);
                printf("Total de empates: %d\n", totalEmpates);
                printf("Total de derrotas: %d\n", totalDerrotas);
                printf("Soma dos pontos: %d\n", somaPontos);
                printf("Média de pontos: %.2f\n", mediaPontos);
                printf("Equipes com excelente campanha: %d\n", qtdExcelente);
                printf("Equipes com boa campanha: %d\n", qtdBoa);
                printf("Equipes com campanha regular: %d\n", qtdRegular);
                printf("Equipes com campanha ruim: %d\n", qtdRuim);
                printf("Maior pontuação: %d (equipe %d)\n", maiorPontuacao, equipeMaior);
                printf("Equipes empatadas na maior pontuação: %d\n", qtdEmpatadosMaior);
                printf("Menor pontuação: %d (equipe %d)\n", menorPontuacao, equipeMenor);
                printf("Equipes empatadas na menor pontuação: %d\n", qtdEmpatadosMenor);
            }
            break;

        case 3:
            printf("\n=== REGULAMENTO ===\n");
            printf("Pontuação: vitória = 3 pontos, empate = 1 ponto, derrota = 0 pontos.\n");
            printf("Situações:\n");
            printf("  15 pontos ou mais: Excelente campanha\n");
            printf("  De 10 a 14 pontos: Boa campanha\n");
            printf("  De 5 a 9 pontos: Campanha regular\n");
            printf("  Menos de 5 pontos: Campanha ruim\n");
            printf("Limites: de 3 a 10 equipes e de 1 a 10 jogos por equipe.\n");
            printf("Cada equipe joga contra todas as outras, ou seja, jogos = equipes - 1.\n");
            break;

        case 4:
            // Quantidade de simulações (1 a 5)
            while (1) {
                printf("Quantas simulações deseja realizar (de 1 a 5)?\n");
                scanf("%d", &qtdSimulacoes);

                if (qtdSimulacoes < 1 || qtdSimulacoes > 5) {
                    printf("Valor inválido! Tente novamente.\n\n");
                }
                else {
                    break;
                }
            }

            for (s = 1; s <= qtdSimulacoes; s++) {

                while (1) {
                    printf("\nSimulação %d - vitórias:\n", s);
                    scanf("%d", &simVitorias);

                    printf("Simulação %d - empates:\n", s);
                    scanf("%d", &simEmpates);

                    printf("Simulação %d - derrotas:\n", s);
                    scanf("%d", &simDerrotas);

                    if (simVitorias < 0 || simEmpates < 0 || simDerrotas < 0) {
                        printf("Inválido! Digite apenas números positivos.\n");
                    }
                    else if (simVitorias + simEmpates + simDerrotas != jogos) {
                        printf("Inválido! A soma dos valores deve ser igual a quantidade de jogos (%d).\n", jogos);
                    }
                    else {
                        break;
                    }
                }

                simPontos = (3 * simVitorias) + simEmpates + (simDerrotas * 0);

                printf("\nSimulação %d: %d vitórias, %d empates e %d derrotas\n", s, simVitorias, simEmpates, simDerrotas);
                printf("Pontuação: %d pontos\n", simPontos);

                if (simPontos >= 15) {
                    printf("Situação: Excelente campanha\n");
                }
                else if (simPontos >= 10) {
                    printf("Situação: Boa campanha\n");
                }
                else if (simPontos >= 5) {
                    printf("Situação: Campanha regular\n");
                    }
               else {
                    printf("Situação: Campanha ruim\n");
                }
                }
               break;
         case 5:
                    printf("Sistema encerrado com sucesso.\n");
                    printf("Obrigado por utilizar o noss sistema.\n");
               break;
               default:
                    printf("Opção inválida! Tente novamente.\n");
                }
                }
               return 0;
                }
