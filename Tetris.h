#ifndef TETRIS_H
#define TETRIS_H
#include <string>

using namespace std;

class Tetris{

    private:

        int colunas;
        int *alturas;
        char **jogo;

        bool addI(int, int, int); 
        bool addJ(int, int, int);
        bool addL(int, int, int);
        bool addO(int, int, int);
        bool addS(int, int, int);
        bool addT(int, int, int);
        bool addZ(int, int, int);

        bool estaPreenchido(int, int);

    public:

        Tetris(const int);
        ~Tetris();

        char get(int c,int l) const;
        void set(int c, int l, char valor);

        int getNumColunas() const;
        int getAltura(int c) const;
        int getAltura() const;

        void exibeJogo(); 

        bool adicionaForma(int coluna,int linha, char id, int rotacao);
        void removeColuna(int c);
        void removeLinhasCompletas();

};
#endif