#include <stdio.h>
#include <stdlib.h> // Necessário para usar a função abs()

#define TAM 10
#define TAM_HAB 5

// Inicializa a matriz com zeros
void inicializarMatriz(int matriz[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = 0;
        }
    }
}

// Imprime o tabuleiro com legenda
void imprimirTabuleiro(int matriz[TAM][TAM]) {
    printf("Legenda: 0=Água | 3=Navio | 5=Habilidade\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Posiciona navio na horizontal (tamanho 3)
int posicionarNavioHorizontal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (coluna + 3 > TAM) return 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0;
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
    return 1;
}

// Posiciona navio na vertical (tamanho 3)
int posicionarNavioVertical(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM) return 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
    return 1;
}

// Posiciona navio em diagonal principal
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM || coluna + 3 > TAM) return 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna + i] = 3;
    }
    return 1;
}

// Posiciona navio em diagonal secundária
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM][TAM], int linha, int coluna) {
    if (linha + 3 > TAM || coluna - 2 < 0) return 0;
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) return 0;
    }
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna - i] = 3;
    }
    return 1;
}

// Cria matriz de cone (pirâmide invertida) 5x5
void criarMatrizCone(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = 0;
        }
    }
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = TAM_HAB / 2 - i; j <= TAM_HAB / 2 + i; j++) {
            if (j >= 0 && j < TAM_HAB) {
                matriz[i][j] = 1;
            }
        }
    }
}

// Cria matriz em cruz 5x5
void criarMatrizCruz(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            matriz[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Cria matriz losango (octaedro em 2D) 5x5
void criarMatrizOctaedro(int matriz[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2);
            matriz[i][j] = (dist <= 2) ? 1 : 0;
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int hab[TAM_HAB][TAM_HAB], int linha, int coluna) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int li = linha + i - TAM_HAB / 2;
            int co = coluna + j - TAM_HAB / 2;
            if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
                if (hab[i][j] == 1 && tabuleiro[li][co] == 0) {
                    tabuleiro[li][co] = 5;
                }
            }
        }
    }
}

// Função principal
int main() {
    int tabuleiro[TAM][TAM];
    inicializarMatriz(tabuleiro);

    // Posiciona os navios
    posicionarNavioHorizontal(tabuleiro, 0, 1);
    posicionarNavioVertical(tabuleiro, 2, 0);
    posicionarNavioDiagonalPrincipal(tabuleiro, 4, 4);
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 9);

    // Criação das matrizes de habilidades
    int cone[TAM_HAB][TAM_HAB], cruz[TAM_HAB][TAM_HAB], octaedro[TAM_HAB][TAM_HAB];
    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Aplicação das habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 5);
    aplicarHabilidade(tabuleiro, cruz, 5, 2);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Imprime o tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
