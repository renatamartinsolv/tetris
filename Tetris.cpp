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


    bool Tetris::estaPreenchido(int c,int l){
        //verificacao da existência do pixel no jogo
        return (l<alturas[c] && c<colunas);
    }


    bool Tetris::adicionaForma(int coluna, int linha, char id, int rotacao){
        
        //verifica se a coluna do pixel de referência existe no tabuleiro
        if (coluna > colunas-1) {
            cout << "Nao é possível addr a peca fora do tabuleiro (coluna > colunas-1)" << endl;
            return false;
        }

        //delega conforme a peça
        switch(id){
            case 'I':
                return addI(coluna, linha, rotacao);
            case 'J':
                return addJ(coluna, linha, rotacao);
            case 'L':
                return addL(coluna, linha, rotacao);
            case 'O':
                return addO(coluna, linha, rotacao);
            case 'S':
                return addS(coluna, linha, rotacao);
            case 'T':
                return addT(coluna, linha, rotacao);
            case 'Z':
                return addZ(coluna, linha, rotacao);
        }
        return false;

    }

    bool Tetris::addI(int coluna, int linha, int rotacao)
    {
        if (rotacao == 0 || rotacao == 180)
        {
            //verifica se o pixel de referência esta numa altura que permite a adicao da peca
            if (linha-3 < 0 && coluna >= getNumColunas())
            {
                cout << "Nao ha altura o suficiente para addr abaixo desta linha (linha-4 < 0)" << endl;
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
                    if (!estaPreenchido(coluna, i))
                        set(coluna, i, '*');
                }
                
                //atualiza a altura da coluna 
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
            if (coluna + 3 >= getNumColunas() || linha < 0)
                return false;

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
                        if (!estaPreenchido(i, j)) 
                            set(i, j, '*');
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

    bool Tetris::addJ(int coluna, int linha, int rotacao){

        switch (rotacao){
            case 0:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 1 < 0 || coluna + 3 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna+1, linha) == '*'
                    && get(coluna+2, linha) == '*'
                    && get(coluna+3, linha) == '*'
                    && get(coluna+3, linha-1) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'J');
                    set(coluna+1, linha, 'J');
                    set(coluna+2, linha, 'J');
                    set(coluna+3, linha, 'J');
                    set(coluna+3, linha-1, 'J');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<3; i++){
                        for (int j = 0; j<linha; j++){
                            if (!estaPreenchido(coluna+i, j))
                                set(coluna+i, j, '*');
                        }
                    }
                    for (int j = 0; j<linha-1; j++){
                        if (!estaPreenchido(coluna+3, j))
                            set(coluna+3, j, '*');
                    }

                    //atualiza a altura da coluna
                    for (int i = 0; i<4; i++){
                        if (alturas[coluna+i] <= linha+1)
                            alturas[coluna+i] = linha+1;
                    } 

                } else 
                    return false;

                return true;

            case 90:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 3 < 0 || coluna + 1 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna+1, linha) == '*'
                    && get(coluna+1, linha-1) == '*'
                    && get(coluna+1, linha-2) == '*'
                    && get(coluna+1, linha-3) == '*'
                    && get(coluna, linha-3) == '*')
                {
                    //acrescenta a peca
                    set(coluna+1, linha, 'J');
                    set(coluna+1, linha-1, 'J');
                    set(coluna+1, linha-2, 'J');
                    set(coluna+1, linha-3, 'J');
                    set(coluna, linha-3, 'J');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<linha-3; i++){
                        if (!estaPreenchido(coluna, i))
                            set(coluna, i, '*');
                        if (!estaPreenchido(coluna+1, i))
                            set(coluna+1, i, '*');
                    }

                    //atualiza a altura da coluna
                    if (alturas[coluna] <= linha-3) 
                        alturas[coluna] = linha-2;
                    if (alturas[coluna+1] < linha) 
                        alturas[coluna+1] = linha+1;

                } else 
                    return false;

                return true;
            case 180:

                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 1 < 0 || coluna + 3 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna, linha-1) == '*'
                    && get(coluna+1, linha-1) == '*'
                    && get(coluna+2, linha-1) == '*'
                    && get(coluna+3, linha-1) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'J');
                    set(coluna, linha-1, 'J');
                    set(coluna+1, linha-1, 'J');
                    set(coluna+2, linha-1, 'J');
                    set(coluna+3, linha-1, 'J');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<4; i++){
                        for (int j = 0; j<linha-1; j++){
                            if (!estaPreenchido(coluna+1, j))
                                set(coluna+i, j, '*');
                        }
                    }

                    //atualiza a altura da coluna
                    for (int i = 1; i<4; i++){
                        if (alturas[coluna+i] <= linha)
                            alturas[coluna+i] = linha;
                    } 
                     if (alturas[coluna] <= linha+1)
                            alturas[coluna] = linha+1;

                } else 
                    return false;

                return true;
            case 270:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 3 < 0 || coluna + 1 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna, linha-1) == '*'
                    && get(coluna, linha-2) == '*'
                    && get(coluna, linha-3) == '*'
                    && get(coluna+1, linha) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'J');
                    set(coluna, linha-1, 'J');
                    set(coluna, linha-2, 'J');
                    set(coluna, linha-3, 'J');
                    set(coluna+1, linha, 'J');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<linha-3; i++){
                        if (!estaPreenchido(coluna, i))
                            set(coluna, i, '*');
                        
                    }
                    for (int i = 0; i<linha; i++){
                       if (!estaPreenchido(coluna+1, i))
                            set(coluna+1, i, '*');   
                    }

                    //atualiza a altura da coluna
                    for (int i = 0; i<2; i++){
                       if (alturas[coluna+i] <= linha) 
                            alturas[coluna+i] = linha+1;
                    }

                } else 
                    return false;

                return true;

            default:
                return false;
        }
    }

    bool Tetris::addL(int coluna, int linha, int rotacao){
        switch (rotacao){
            case 0:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 1 < 0 || coluna + 3 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna, linha-1) == '*'
                    && get(coluna+1, linha) == '*'
                    && get(coluna+2, linha) == '*'
                    && get(coluna+3, linha) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'L');
                    set(coluna, linha-1, 'L');
                    set(coluna+1, linha, 'L');
                    set(coluna+2, linha, 'L');
                    set(coluna+3, linha, 'L');

                    //preenche os espacos abaixo da peca 
                    for (int i = 1; i<4; i++){
                        for (int j = 0; j<linha; j++){
                            if(!estaPreenchido(coluna+i, j))
                                set(coluna+i, j, '*');
                        }
                    }
                    for (int j = 0; j<linha-1; j++){
                        if(!estaPreenchido(coluna, j))
                            set(coluna, j, '*');
                    }

                    //atualiza a altura da coluna
                    for (int i = 0; i<4; i++){
                        if (alturas[coluna+i] <= linha)
                            alturas[coluna+i] = linha+1;
                    } 

                } else 
                    return false;    
                
                return true;
            case 90:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 3 < 0 || coluna + 1 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna+1, linha) == '*'
                    && get(coluna+1, linha-1) == '*'
                    && get(coluna+1, linha-2) == '*'
                    && get(coluna+1, linha-3) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'L');
                    set(coluna+1, linha, 'L');
                    set(coluna+1, linha-1, 'L');
                    set(coluna+1, linha-2, 'L');
                    set(coluna+1, linha-3, 'L');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<linha-3; i++){
                        if (!estaPreenchido(coluna+1, i))
                            set(coluna+1, i, '*');
                    }
                    for (int i = 0; i<linha; i++){
                        if (!estaPreenchido(coluna, i))
                            set(coluna, i, '*');

                    }

                    //atualiza a altura da coluna
                    for (int i = 0; i<2; i++){
                        if (alturas[coluna+i] <= linha) 
                            alturas[coluna+i] = linha+1;
                    }
                } else 
                    return false;

                return true;
            case 180:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 1 < 0 || coluna + 3 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna+3, linha) == '*'
                    && get(coluna, linha-1) == '*'
                    && get(coluna+1, linha-1) == '*'
                    && get(coluna+2, linha-1) == '*'
                    && get(coluna+3, linha-1) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha-1, 'L');
                    set(coluna+1, linha-1, 'L');
                    set(coluna+2, linha-1, 'L');
                    set(coluna+3, linha-1, 'L');
                    set(coluna+3, linha, 'L');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<4; i++){
                        for (int j = 0; j<linha-1; j++){
                            if (!estaPreenchido(coluna+i, j))
                                set(coluna+i, j, '*');
                        }
                    }

                    //atualiza a altura da coluna
                    for (int i = 0; i<3; i++){
                        if (alturas[coluna+i] <= linha-1)
                            alturas[coluna+i] = linha;
                    } 
                     if (alturas[coluna+3] <= linha)
                            alturas[coluna+3] = linha+1;

                } else 
                    return false;

                return true;
            case 270:
                //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
                if (linha - 3 < 0 || coluna + 1 >= getNumColunas()) 
                    return false;

                //verifica se os espacos que serao utilizados estao vazios
                if (get(coluna, linha) == '*'
                    && get(coluna, linha-1) == '*'
                    && get(coluna, linha-2) == '*'
                    && get(coluna, linha-3) == '*'
                    && get(coluna+1, linha-3) == '*')
                {
                    //acrescenta a peca
                    set(coluna, linha, 'L');
                    set(coluna, linha-1, 'L');
                    set(coluna, linha-2, 'L');
                    set(coluna, linha-3, 'L');
                    set(coluna+1, linha-3, 'L');

                    //preenche os espacos abaixo da peca 
                    for (int i = 0; i<linha-3; i++){
                        if (!estaPreenchido(coluna, i))
                            set(coluna, i, '*');
                        if (!estaPreenchido(coluna+1, i))
                            set(coluna+1, i, '*');    
                        
                    }

                    //atualiza a altura da coluna
                    if (alturas[coluna] <= linha) 
                        alturas[coluna] = linha+1;
                    if (alturas[coluna+1] <= linha-3) 
                        alturas[coluna+1] = linha-2;

                } else 
                    return false;

                return true;
        }
    }

    bool Tetris::addO(int coluna, int linha, int rotacao){

        //verifica se o pixel de referência esta numa altura/largura que permite a adicao da peca
        if (linha - 1 < 0 && coluna + 1 >= getNumColunas()) 
            return false;

        //verifica se os espacos que serao utilizados estao vazios
        if (get(coluna, linha) == '*'
            && get(coluna+1, linha) == '*'
            && get(coluna, linha-1) == '*'
            && get(coluna+1, linha-1) == '*')
        {
            //acrescenta a peca
            set(coluna, linha, 'O');
            set(coluna+1, linha, 'O');
            set(coluna, linha-1, 'O');
            set(coluna+1, linha-1, 'O');

            //preenche os espacos abaixo da peca 
            for (int i = 0; i<linha-1; i++){
                if (!estaPreenchido(coluna, i))
                    set(coluna, i, '*');
                if (!estaPreenchido(coluna+1, i))
                    set(coluna+1, i, '*');
            }

            //atualiza a altura da coluna
            for (int i = 0; i<2; i++){
                if (alturas[coluna+i] <= linha)
                    alturas[coluna+i] = linha+1;
            } 

        } else 
            return false;

        return true;
    }

    bool Tetris::addS(int coluna, int linha, int rotacao){
        if (rotacao == 0 || rotacao == 180){

            //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
            if (linha - 1 < 0 || coluna + 2 >= getNumColunas()) 
                return false;

            //verifica se os espacos que serao utilizados estao vazios
            if (get(coluna, linha-1) == '*'
                && get(coluna+1, linha) == '*'
                && get(coluna+2, linha) == '*'
                && get(coluna+1, linha-1) == '*')
            {
                //acrescenta a peca
                set(coluna, linha-1, 'S');
                set(coluna+1, linha, 'S');
                set(coluna+2, linha, 'S');
                set(coluna+1, linha-1, 'S');

                //preenche os espacos abaixo da peca 
                for (int i = 0; i<2; i++){
                    for (int j = 0; j<linha-1; j++){
                        if(!estaPreenchido(coluna+i, j))
                            set(coluna+i, j, '*');
                    }
                }
                for (int j = 0; j<linha; j++){
                    if(!estaPreenchido(coluna+2, j))
                        set(coluna+2, j, '*');
                }

                //atualiza a altura da coluna
                for (int i = 1; i<3; i++){
                    if(alturas[coluna+i] <=linha)
                        alturas[coluna+i] = linha+1;
                } 
                if(alturas[coluna] <=linha-1)
                        alturas[coluna] = linha;

            } else 
                return false;    
            
            return true; 
        } else if (rotacao == 90 || rotacao == 270){
            //verifica se há altura/largura suficiente pra peca a partir do pixel de referencia 
            if (linha - 2 < 0 || coluna + 1 >= getNumColunas()) 
                return false;

            //verifica se os espacos que serao utilizados estao vazios
            if (get(coluna, linha) == '*'
                && get(coluna, linha-1) == '*'
                && get(coluna+1, linha-1) == '*'
                && get(coluna+1, linha-2) == '*')
            {
                //acrescenta a peca
                set(coluna, linha, 'S');
                set(coluna, linha-1, 'S');
                set(coluna+1, linha-1, 'S');
                set(coluna+1, linha-2, 'S');

                //preenche os espacos abaixo da peca 
                for (int j = 0; j<linha-1; j++){
                    if(!estaPreenchido(coluna, j))
                        set(coluna, j, '*');
                }
                for (int j = 0; j<linha-2; j++){
                    if(!estaPreenchido(coluna+1, j))
                        set(coluna+1, j, '*');
                }

                //atualiza a altura da coluna
                if(alturas[coluna] <=linha)
                    alturas[coluna] = linha+1;
                if(alturas[coluna+1] <=linha-1)
                        alturas[coluna+1] = linha;

            } else 
                return false;    
            
            return true;   
        }
        return false;
    }

    bool Tetris::addT(int coluna,int linha, int rotacao){
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

    bool Tetris::addZ(int coluna,int linha, int rotacao){
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

