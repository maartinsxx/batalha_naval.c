⚓ Projeto Batalha Naval em C
Este projeto é um desafio de programação em linguagem C, proposto pela faculdade, com o objetivo de desenvolver e evoluir um jogo de Batalha Naval, através de três níveis de dificuldade: Novato, Aventureiro e Mestre. Cada fase propõe novos desafios que permitem aplicar os conhecimentos adquiridos em vetores, matrizes, condicionais e estruturas de repetição.

💡 Desafio Nível Novato - Tabuleiro de Batalha Naval
No primeiro nível, o desafio consiste em criar um tabuleiro 10x10 para representar o campo de batalha.

Funcionalidades:
Inicialização de um tabuleiro 10x10 com valores 0, representando água.

Inserção manual de navios, representados pelo valor 3, em posições fixas ou aleatórias.

Impressão do tabuleiro na tela, com representação clara dos espaços ocupados.

Tecnologias Utilizadas:
Linguagem C

Compilador GCC

Terminal (entrada e saída padrão)

Conceitos Aplicados:
Matrizes bidimensionais

Loops aninhados (for)

Estruturação de dados com int

Impressão formatada com printf

Exemplo de saída:
python-repl
Copiar
Editar
0 0 0 0 0 0 0 0 0 0
0 3 0 0 0 0 0 0 0 0
0 0 0 0 3 0 0 0 0 0
...
🧭 Desafio Nível Aventureiro - Inserção de Navios e Visualização Estratégica
No segundo nível, a lógica foi expandida para permitir a inserção dinâmica de navios e visualizar o posicionamento estratégico.

Funcionalidades:
Inserção de navios no tabuleiro com validação de coordenadas.

Representação visual clara com símbolos distintos para água (0) e navios (3).

Validação para evitar que navios sejam colocados fora dos limites da matriz ou sobrepostos.

Tecnologias Utilizadas:
Linguagem C

Compilador GCC

Terminal (entrada e saída padrão)

Conceitos Aplicados:
Condicionais (if, else)

Validação de entrada

Manipulação de matrizes

Organização e clareza na exibição de dados

Exemplo de saída:
python-repl
Copiar
Editar
0 0 3 0 0 0 0 0 0 0
0 3 3 3 0 0 0 0 0 0
...
🧠 Desafio Nível Mestre - Habilidades Especiais e Áreas de Efeito
O terceiro e último desafio adiciona um nível estratégico ao jogo, implementando habilidades especiais com áreas de efeito.

💥 Habilidades Implementadas:
Cada habilidade possui uma matriz de efeito própria, com valores 1 (área afetada) e 0 (área neutra). As habilidades são:

Cone: Área em formato de cone invertido, expandindo do topo até a base.

Cruz: Formato de cruz com o ponto de origem ao centro da matriz.

Octaedro (Losango): Área em formato de losango, com o centro como origem.

Funcionalidades:
Geração dinâmica das matrizes de habilidades (5x5) com loops e condicionais.

Definição de um ponto de origem (linha e coluna) no tabuleiro principal.

Sobreposição da área de efeito no tabuleiro com valor 5.

Exibição do tabuleiro com:

0: Água

3: Navio

5: Área afetada pela habilidade

Tecnologias Utilizadas:
Linguagem C

Compilador GCC

Terminal (entrada e saída padrão)

Conceitos Aplicados:
Loops aninhados e condicionais

Manipulação de múltiplas matrizes

Sobreposição de matrizes com tratamento de bordas

Representação visual de áreas de ataque estratégicas

Exemplo de saída (habilidade em cone):
Copiar
Editar
0 0 5 0 0
0 5 5 5 0
5 5 5 5 5
Exemplo de saída (habilidade em cruz):
Copiar
Editar
0 0 5 0 0
5 5 5 5 5
0 0 5 0 0
Exemplo de saída (habilidade em octaedro):
Copiar
Editar
0 0 5 0 0
0 5 5 5 0
0 0 5 0 0
✅ Funcionalidades Gerais Desenvolvidas
Criação e exibição de tabuleiro 10x10.

Inserção de navios com validação de posições.

Construção de matrizes para habilidades especiais.

Cálculo e exibição de áreas de efeito com sobreposição no tabuleiro.

Representação clara e organizada de todos os elementos visuais do jogo.

📚 Aprendizados
Este projeto consolidou o conhecimento em:

Declaração e manipulação de matrizes

Estruturas de repetição e condicionais

Lógica de sobreposição e verificação de bordas

Exibição visual organizada em linguagem C

Divisão do projeto em etapas evolutivas, simulando desenvolvimento real de software

📌 Como Executar
Para compilar e executar:

bash
Copiar
Editar
gcc batalha_naval.c -o batalha
./batalha


