#include <string>
#include <iostream>
#include "Tetris.h"

    Tetris::Tetris(const int c){
        colunas = c;
        alturas = new int[colunas];

        jogo = new char*[colunas];
        for(int i = 0; i <colunas; i++){
            jogo[i] = new char;
            alturas[i] = 0;
        }
    }

    Tetris::~Tetris(){
        for (int i=0; i < colunas; i++)
            delete (jogo[i]);
        delete (jogo);
    }
    
    char Tetris::get(int c,int l){
        if (l<alturas[c] && c<colunas) return jogo[l][c];
        return ' ';
    }

    int Tetris::getNumColunas(){
        return colunas;
    }

    int Tetris::getAltura(int c){
        return alturas[c];
    }

    int Tetris::getAltura(){
        int alturaMaxima = 0;
        for (int i = 0; i<colunas; i++){
            if (alturas[i]>alturaMaxima) alturaMaxima = alturas[i];
        }
        return alturaMaxima;
    }

    bool Tetris::adicionaForma(int coluna,int linha, char id, int rotacao){
        if (coluna > colunas-1) {
            cout << "Não é possível adicionar a peça fora do tabuleiro (coluna > colunas-1)" << endl;
            return false;
        }
        bool resposta = false;
        switch(id){
            case 'I':
                cout << "Adicionando a peca " << id << endl;
                resposta = adicionaI(coluna, linha, rotacao);
                break;
            case 'J':
                resposta = adicionaJ(coluna, linha, rotacao);
                break;
            case 'L':
                resposta = adicionaL(coluna, linha, rotacao);
                break;
            case 'O':
                resposta = adicionaO(coluna, linha, rotacao);
                break;
            case 'S':
                resposta = adicionaS(coluna, linha, rotacao);
                break;
            case 'T':
                resposta = adicionaT(coluna, linha, rotacao);
                break;
            case 'Z':
                resposta = adicionaZ(coluna, linha, rotacao);
                break;
        }
        return resposta;

    }

    bool Tetris::adicionaI(int coluna,int linha, int rotacao){
        switch (rotacao){
            case 0:
                if (linha-4 < 0) {
                    cout << "Não há altura o suficiente para adicionar abaixo desta linha (linha-4 < 0)" << endl;
                    return false;
                }
                for (int i = linha; i>linha-4; i--){
                    cout << jogo[i][coluna] << endl;
                    if (jogo[i][coluna]){
                        cout << "Pixel preenchido com " << jogo[i][coluna] << endl;
                        return false;   
                    }
                }
                for (int i = 0; i<4; i++){
                    jogo[linha+i][coluna] = 'I';
                    cout << linha+1 << " " << coluna << " " << jogo[linha+i][coluna] << endl;
                }
                alturas[coluna]+=4;
                return true;
            case 90:

                break;
            case 180:
                if (linha-4 < 0) return false;
                for (int i = linha; i>linha-4; i--){
                    if (!jogo[i][coluna]) return false;   
                }
                jogo[linha][coluna] = 'I';
                jogo[linha-1][coluna] = 'I';
                jogo[linha-2][coluna] = 'I';
                jogo[linha-3][coluna] = 'I';
                return true;
            case 270:
                break;
        }
        return false;
    }

    bool Tetris::adicionaJ(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    bool Tetris::adicionaL(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    bool Tetris::adicionaO(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    bool Tetris::adicionaS(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    bool Tetris::adicionaT(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    bool Tetris::adicionaZ(int coluna,int linha, int rotacao){
        bool resposta = false;
        switch (rotacao){
            case 0:
                break;
            case 90:
                break;
            case 180:
                break;
            case 270:
                break;
        }
        return resposta;
    }

    void Tetris::removeColuna(int c){

    }

    void Tetris::removeLinhasCompletas(){

    }

    void Tetris::exibeJogo(){
        int altura;
        int alturaMaxima = getAltura();

        for (int i = 0; i<alturaMaxima; i++){
            for (int j = 0; j<colunas; j++){
                if (i < alturas[j]){
                    cout << jogo[i][j] << " ";
                }
            }
            cout << endl;
        }
    }