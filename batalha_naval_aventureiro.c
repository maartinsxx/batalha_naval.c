#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3
#define OCUPADO 3

// Inicializa o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Exibe o tabuleiro no console
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\nTABULEIRO BATALHA NAVAL:\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Verifica se as posições estão livres e dentro dos limites para um navio horizontal
int posicionarNavioHorizontal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha][coluna + i] != 0) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha][coluna + i] = OCUPADO;
    }

    return 1;
}

// Verifica se as posições estão livres e dentro dos limites para um navio vertical
int posicionarNavioVertical(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna] != 0) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna] = OCUPADO;
    }

    return 1;
}

// Verifica e posiciona um navio na diagonal principal (↘)
int posicionarNavioDiagonalPrincipal(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna + TAM_NAVIO > TAM_TABULEIRO) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna + i] != 0) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna + i] = OCUPADO;
    }

    return 1;
}

// Verifica e posiciona um navio na diagonal secundária (↙)
int posicionarNavioDiagonalSecundaria(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int linha, int coluna) {
    if (linha + TAM_NAVIO > TAM_TABULEIRO || coluna - TAM_NAVIO + 1 < 0) return 0;

    for (int i = 0; i < TAM_NAVIO; i++) {
        if (tabuleiro[linha + i][coluna - i] != 0) return 0;
    }

    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linha + i][coluna - i] = OCUPADO;
    }

    return 1;
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Posicionamentos definidos diretamente no código
    int sucesso = 1;

    // Navio 1 - Horizontal
    sucesso &= posicionarNavioHorizontal(tabuleiro, 0, 0);

    // Navio 2 - Vertical
    sucesso &= posicionarNavioVertical(tabuleiro, 4, 2);

    // Navio 3 - Diagonal principal (↘)
    sucesso &= posicionarNavioDiagonalPrincipal(tabuleiro, 6, 6);

    // Navio 4 - Diagonal secundária (↙)
    sucesso &= posicionarNavioDiagonalSecundaria(tabuleiro, 2, 9);

    if (!sucesso) {
        printf("Erro ao posicionar um ou mais navios. Verifique sobreposição ou limites.\n");
        return 1;
    }

    exibirTabuleiro(tabuleiro);

    return 0;
}
