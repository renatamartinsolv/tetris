#include <string>
#include <iostream>
#include "Tetris.h"

    Tetris::Tetris(const int c){
        colunas = c;
        alturas = new int[colunas];

        //inicialização do vetor de alturas em 0
        for (int i = 0; i<colunas; i++){
            alturas[i] = 0;
        }

        jogo = new char*[colunas];
    }

    Tetris::~Tetris(){
        for (int i=0; i < colunas; i++)
            delete (jogo[i]);
        delete (jogo);
    }
    

    char Tetris::get(int c,int l){
        //verificação da existência do pixel no jogo
        if (l<alturas[c] && c<colunas) 
            return jogo[c][l];

        return ' ';
    }

    int Tetris::getNumColunas(){
        return colunas;
    }

    int Tetris::getAltura(int c){
        //verificação da existência da coluna no jogo
        if (c < colunas)
            return alturas[c];
        return 0;
    }

    int Tetris::getAltura(){
        int alturaMaxima = 0;
        for (int i = 0; i<colunas; i++){
            if (alturas[i]>alturaMaxima) 
                alturaMaxima = alturas[i];
        }
        return alturaMaxima;
    }

    void Tetris::set(int c, int l, char valor){
        
    }

    void Tetris::removeColuna(int c){
        for (int i = c+1; i<colunas; i++){
            for (int j = 0; j<alturas[i]; j++){
                jogo[i-1][j] = jogo[i][j];
            }
        }
        for (int i = c+1; i<colunas; i++){
            alturas[i-1] = alturas[i];
        }
        colunas--;
        alturas[getNumColunas()] = 0;;
    }

    void Tetris::removeLinhasCompletas(){

    }


    void Tetris::exibeJogo(){
        int altura;
        int alturaMaxima = getAltura();

        for (int i = 0; alturaMaxima; i++){
            for (int j = 0; j<colunas; j++){
                cout << get(j, i) << " " << endl;
            }
            cout << endl;
        }
    }


    bool Tetris::adicionaForma(int coluna,int linha, char id, int rotacao){
        //verifica se o pixel de referência existe no tabuleiro
        if (coluna > colunas-1) {
            cout << "Não é possível adicionar a peça fora do tabuleiro (coluna > colunas-1)" << endl;
            return false;
        }
        bool resposta = false;
        switch(id){
            case 'I':
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
                //verifica se o pixel de referência está numa altura que permite a adição da peça
                if (linha-4 < 0) {
                    cout << "Não há altura o suficiente para adicionar abaixo desta linha (linha-4 < 0)" << endl;
                    return false;
                }
                //verifica se os espaços que serão utilizados estão vazios
                if (get(coluna, linha) == ' ' && get(coluna, linha-1) == ' ' && get(coluna, linha-2) == ' ' && get(coluna, linha-3) == ' '){
                    //acrescenta a peça
                    for (int i = 0; i<4; i++){
                        jogo[linha-i][coluna] = 'I';
                    }
                    //atualização da altura da coluna 
                    if (linha > alturas[coluna]) alturas[coluna] = linha;
                    //preenchimento dos espaços em branco abaixo da peça 
                    for (int i = 0; i<alturas[coluna]; i++){
                        jogo[coluna][i] = get(coluna, i);
                    }
                } else return false;
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
