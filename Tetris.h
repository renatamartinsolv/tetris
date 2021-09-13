#ifndef TETRIS_H
#define TETRIS_H
#include <string>

using namespace std;

class Tetris{

    private:

        int colunas;
        int *alturas;
        char **jogo;

    public:

        Tetris(const int);
        ~Tetris();

        char get(int c,int l);
        void set(int c, int l, char valor);

        int getNumColunas();
        int getAltura(int c);
        int getAltura();

        bool adicionaForma(int coluna,int linha, char id, int rotacao);
        void removeColuna(int c);
        void removeLinhasCompletas();

        void exibeJogo(); 
        bool adicionaI(int, int, int); 
        bool adicionaJ(int, int, int);
        bool adicionaL(int, int, int);
        bool adicionaO(int, int, int);
        bool adicionaS(int, int, int);
        bool adicionaT(int, int, int);
        bool adicionaZ(int, int, int);
};
#endif