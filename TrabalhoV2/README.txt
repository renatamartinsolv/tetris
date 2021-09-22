Eu li as regras
Nome: Renata Martins Oliveira
Matrícula: 99868

O trabalho consiste em um jogo Tetris onde não há simulação de gravidade. 
Todas as funções foram feitas utilizando alocação dinâmica de uma matriz 
principal (jogo), com N colunas de tamanhos diversos. Cada tamanho está 
armazenado no vetor alturas[N], também alocado dinamicamente. 
O jogo permite a adição de 7 peças, com 4 rotações cada, representadas com
sua respectiva letra do alfabeto. Além disso, existes as funções de remoção
de linhas completas, conforme o jogo original, e a remoção de determinada
coluna, para encurtamento do tabuleiro. 
Para facilitar a leitura e implementação, utilizei as funções isBiggerThen,
isSmallerThen, areEquals e isFilled, que fazem as respectivas verificações, 
e empty(),que retorna o espaço vazio. Além disso, há a função set, que é
responsávelpor preencher o pixel passado, e tratar todas as implicações disso, 
como a correção da altura e alocação dos pixels em branco abaixo, e a função

As fontes utilizadas foram:
- Aulas e tira-dúvidas da disciplina INF213
- Materiais disponibilizados pelo professor
- Documentação sobre ponteiros, new e delete da linguagem c++