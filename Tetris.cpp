#include <string>
#include <iostream>
#include "Tetris.h"

    Tetris::Tetris(int c){
        this->c = c;
        l = 0;
        jogo = new char[1][c];
        jogo = {'*'};
    }

    Tetris::~Tetris(){}
    
    char Tetris::get(int c,int l){
        return jogo[l][c];
    }

    int Tetris::getNumColunas(){
        return c;
    }

    int Tetris::getAltura(int c){
        return 0;
    }
    int Tetris::getAltura(){
        return 0;
    }

    bool Tetris::adicionaForma(int coluna,int linha, char id, int rotacao){

    }

    void Tetris::removeColuna(int c){

    }

    void Tetris::removeLinhasCompletas(){

    }

    void Tetris::exibeJogo(){
        for (int i = l-1; i>=0; i--){
            for (int j = 0; j<c; j++){
                cout << jogo[i][j] << " ";
            }
            cout << endl;
        }
    }