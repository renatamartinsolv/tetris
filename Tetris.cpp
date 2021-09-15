#include <iostream>
#include "Tetris.h"

    Tetris::Tetris(const int c){
        colunas = c;
        alturas = new int[colunas];

        //inicializacao do vetor de alturas em 0
        for (int i = 0; i<colunas; i++){
            alturas[i] = 0;
        }

        //inicialização do vetor principal
        jogo = new char*[colunas];

        //inicialização de cada vetor secundário
        for (int i = 0; i<colunas; i++)
            jogo[i] = new char;
    }

    Tetris::~Tetris(){
        for (int i=0; i < colunas; i++)
            //apaga todos os vetores dentro do vetor principal
            delete (jogo[i]);
        //apaga o vetor principal
        delete (jogo);
    }
    

    char Tetris::get(int c,int l){
        //verificacao da existência do pixel no jogo
        if (l<alturas[c]  && c<colunas) 
            return jogo[c][l];
        return '*';
    }

    int Tetris::getNumColunas(){
        return colunas;
    }

    int Tetris::getAltura(int c){
        //verificacao da existência da coluna no jogo
        if (c < colunas)
            return alturas[c];
        return 0;
    }

    int Tetris::getAltura(){
        int alturaMaxima = 0;

        //para cada valor de altura, verifica se é maior que a altura máxima encontrada até o momento
        for (int i = 0; i<colunas; i++){
            if (alturas[i]>alturaMaxima) 
                //se for, substitui
                alturaMaxima = alturas[i];
        }
        return alturaMaxima;
    }


    void Tetris::set(int c, int l, char valor){
        //preenchimento do pixel
        jogo[c][l] = char(valor);
    }


    void Tetris::removeColuna(int c){
        //passa os dados das colunas seguintes a c para sua antecessora
        for (int i = c+1; i<colunas; i++){
            for (int j = 0; j<alturas[i]; j++){
                jogo[i-1][j] = jogo[i][j];
            }
            alturas[i-1] = alturas[i];
        }
        //apaga a última coluna da matriz
        colunas--;
        delete jogo[colunas];
        alturas[colunas] = 0;
    }

    void Tetris::removeLinhasCompletas(){

    }



    bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){
        
        //verifica se a coluna do pixel de referência existe no tabuleiro
        if (coluna > colunas-1) {
            cout << "Nao é possível adicionar a peca fora do tabuleiro (coluna > colunas-1)" << endl;
            return false;
        }
        bool resposta = false;

        //delega conforme a peça
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

    bool Tetris::adicionaI(int coluna, int linha, int rotacao)
    {
        if (rotacao == 0 || rotacao == 180)
        {
            //verifica se o pixel de referência esta numa altura que permite a adicao da peca
            if (linha-3 < 0)
            {
                cout << "Nao ha altura o suficiente para adicionar abaixo desta linha (linha-4 < 0)" << endl;
                return false;
            }

            //verifica se os espacos que serao utilizados estao vazios
            if (get(coluna, linha) == '*' 
                && get(coluna, linha-1) == '*' 
                && get(coluna, linha-2) == '*' 
                && get(coluna, linha-3) == '*')
            {                

                //acrescenta a peca
                for (int i = 0; i<4; i++){
                    set(coluna, linha-i, 'I');
                }

                //preenche os espacos abaixo da peca 
                for (int i = 0; i<linha-3; i++){
                    set(coluna, i, get(coluna, i));
                }
                
                //atualiza aa altura da coluna 
                if (linha > alturas[coluna])
                {
                    alturas[coluna] = linha+1;
                }

            } else{
                return false;
            } 

            return true;

        }else
        {

            //verifica se o pixel de referência esta numa largura que permite a adicao da peca
            if (coluna + 3 > getNumColunas() - 1)
            {
                cout << "Nao ha largura o suficiente para adicionar abaixo desta linha." << endl;
                return false;
            }

            //verifica se os espacos que serao utilizados estao vazios
            if(get(coluna, linha) == '*' 
                && get(coluna+1, linha) == '*' 
                && get(coluna+2, linha) == '*' 
                && get(coluna+3, linha) == '*')
            {

                
                //acrescenta a peca
                for (int i = 0; i<4; i++){
                    set(coluna+i, linha, 'I');
                }   

                //preenchimento dos espacos abaixo da peca 
                for (int i = coluna; i<coluna+4; i++){
                    for (int j = 0; j<linha; j++){
                        set(i, j, get(i, j));
                    }
                }

                //atualizacao da altura da coluna 
                for (int i = coluna; i<coluna+4; i++){
                    if (alturas[i] < linha){
                        alturas[i] = linha+1;
                    }
                }

            } else
            {
                return false;
            }
        }
        return true;
    }

    bool Tetris::adicionaJ(int coluna, int linha, int rotacao){
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

    bool Tetris::adicionaL(int coluna, int linha, int rotacao){
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

    bool Tetris::adicionaO(int coluna, int linha, int rotacao){
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

    bool Tetris::adicionaS(int coluna, int linha, int rotacao){
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
    
    
    void Tetris::exibeJogo(){
        int altura;
        int alturaMaxima = getAltura();
        cout << "------------------------ TETRIS ------------------------" << endl;
        for (int i = alturaMaxima-1; i>=0; i--){
            for (int j = 0; j<colunas; j++){
                cout << get(j, i) << " ";
            }
            cout << endl;
        }
        cout << "--------------------------------------------------------" << endl;
    }

