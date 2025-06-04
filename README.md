a# ⚓ Projeto Batalha Naval em C

Este projeto é um desafio de programação em linguagem C, proposto pela faculdade, com o objetivo de desenvolver e evoluir um jogo de Batalha Naval, através de três níveis de dificuldade: **Novato**, **Aventureiro** e **Mestre**. Cada fase propõe novos desafios que permitem aplicar os conhecimentos adquiridos em vetores, matrizes, condicionais e estruturas de repetição.

---

## 💡 Desafio Nível Novato - Tabuleiro de Batalha Naval

### Funcionalidades
- Inicialização de um tabuleiro 10x10 com valores `0`, representando água.
- Inserção manual de navios, representados pelo valor `3`, em posições fixas ou aleatórias.
- Impressão do tabuleiro na tela, com representação clara dos espaços ocupados.

### 🛠 Tecnologias Utilizadas
- Linguagem C  
- Compilador GCC  
- Terminal (entrada e saída padrão)

### 📚 Conceitos Aplicados
- Matrizes bidimensionais  
- Loops aninhados (`for`)  
- Estruturação de dados com `int`  
- Impressão formatada com `printf`


---

## 🧭 Desafio Nível Aventureiro - Inserção de Navios e Visualização Estratégica

### Funcionalidades
- Inserção de navios no tabuleiro com validação de coordenadas.
- Representação visual clara com símbolos distintos para água (`0`) e navios (`3`).
- Validação para evitar que navios sejam colocados fora dos limites da matriz ou sobrepostos.

### 🛠 Tecnologias Utilizadas
- Linguagem C  
- Compilador GCC  
- Terminal (entrada e saída padrão)

### 📚 Conceitos Aplicados
- Condicionais (`if`, `else`)  
- Validação de entrada  
- Manipulação de matrizes  
- Organização e clareza na exibição de dados

### 💻 Exemplo de saída


---

## 🧠 Desafio Nível Mestre - Habilidades Especiais e Áreas de Efeito

### 💥 Habilidades Implementadas
Cada habilidade possui uma matriz de efeito própria, com valores `1` (área afetada) e `0` (área neutra). As habilidades são:

- **Cone:** Área em formato de cone invertido, expandindo do topo até a base.
- **Cruz:** Formato de cruz com o ponto de origem ao centro da matriz.
- **Octaedro (Losango):** Área em formato de losango, com o centro como origem.

### Funcionalidades
- Geração dinâmica das matrizes de habilidades (5x5) com loops e condicionais.
- Definição de um ponto de origem (linha e coluna) no tabuleiro principal.
- Sobreposição da área de efeito no tabuleiro com valor `5`.
- Exibição do tabuleiro com:
  - `0`: Água  
  - `3`: Navio  
  - `5`: Área afetada pela habilidade

### 🛠 Tecnologias Utilizadas
- Linguagem C  
- Compilador GCC  
- Terminal (entrada e saída padrão)

### 📚 Conceitos Aplicados
- Loops aninhados e condicionais  
- Manipulação de múltiplas matrizes  
- Sobreposição de matrizes com tratamento de bordas  
- Representação visual de áreas de ataque estratégicas

### 💻 Exemplo de saída (Cone)


