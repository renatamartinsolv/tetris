#ifndef TETRIS_H
#define TETRIS_H
#include <string>

using namespace std;

class Tetris{

    private:

        int c;
        int l;
        char** jogo;

    public:

        Tetris();
        ~Tetris();

        Tetris(int c);

        char get(int c,int l);

        int getNumColunas();
        int getAltura(int c);
        int getAltura();

        bool adicionaForma(int coluna,int linha, char id, int rotacao);
        void removeColuna(int c);
        void removeLinhasCompletas();

        void exibeJogo();  
};

#endif