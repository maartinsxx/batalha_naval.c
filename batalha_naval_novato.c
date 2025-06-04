#include <stdio.h>

#define TAM_TABULEIRO 10   // Define o tamanho fixo do tabuleiro 10x10
#define TAM_NAVIO 3        // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para imprimir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTABULEIRO BATALHA NAVAL:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe na linha e não ultrapassa o limite
    if (coluna + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    // Verifica se as posições estão livres
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0)
            return 0;
    }

    // Posiciona o navio com valor 3
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }

    return 1;
}

// Função para posicionar navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    // Verifica se o navio cabe na coluna e não ultrapassa o limite
    if (linha + TAM_NAVIO > TAM_TABULEIRO)
        return 0;

    // Verifica se as posições estão livres
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0)
            return 0;
    }

    // Posiciona o navio com valor 3
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }

    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    inicializarTabuleiro(tabuleiro);

    // Coordenadas iniciais dos navios (definidas diretamente no código)
    int linhaNavioH = 2;
    int colunaNavioH = 4;

    int linhaNavioV = 5;
    int colunaNavioV = 6;

    // Tenta posicionar o navio horizontal
    if (!posicionarNavioHorizontal(tabuleiro, linhaNavioH, colunaNavioH)) {
        printf("Erro ao posicionar o navio horizontal!\n");
        return 1;
    }

    // Tenta posicionar o navio vertical
    if (!posicionarNavioVertical(tabuleiro, linhaNavioV, colunaNavioV)) {
        printf("Erro ao posicionar o navio vertical!\n");
        return 1;
    }

    // Exibe o tabuleiro com os navios
    exibirTabuleiro(tabuleiro);

    return 0;
}
