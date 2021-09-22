#include "Tetris.h"
#include <iostream>

using namespace std;

//-------------------------------------------------- AUXILIARES

bool Tetris::isSmallerThen(int a, int b)const{return a < b;}

bool Tetris::isBiggerThen(int a, int b)const{ return a > b;}

bool Tetris::areEquals(int a, int b)const{ return a == b;}

const char Tetris::empty()const{return ' ';}

bool Tetris::isFilled(int c, int l)const{
    return (isSmallerThen(c, this->columns) && 
            isSmallerThen(l, this->alturas[c]));
}

//-------------------------------------------------- INICIALIZAÇÃO

//Construtor
Tetris::Tetris(const int size){
    this->columns = size;
    this->jogo = new char*[size];
    this->alturas = new int[size];

    int i = 0;
    while(isSmallerThen(i, size)){
        this->jogo[i] = new char[0];
        this->alturas[i] = 0;
        i++;
    }
}

//Destrutor
Tetris::~Tetris(){
    delete [] this->alturas;

    int i = 0;
    while(isSmallerThen(i, this->columns)){
        delete [] this->jogo[i];
        i++;
    }
    delete [] this->jogo;
}

//Construtor de cópias
Tetris::Tetris(const Tetris &otherTetris){
    int newWidth = otherTetris.columns;
    this->jogo = new char*[newWidth];
    this->alturas = new int[newWidth];
    this->columns = newWidth;
    int i = 0;
    while(isSmallerThen(i, newWidth)){
        this->jogo[i] = new char[0];
        this->alturas[i] = 0;
        i++;
    }
    *this = otherTetris;
}

//Operador de Atribuição
Tetris &Tetris::operator=(const Tetris &otherTetris){

    if(this==&otherTetris) return *this;
    
    int i = 0;
    delete [] alturas;
    while(isSmallerThen(i, this->columns)){
        delete [] this->jogo[i];
        i++;
    }
    delete [] jogo;

    int newWidth = otherTetris.columns;
    this->columns = newWidth;
    this->alturas = new int [newWidth];
    this->jogo = new char *[newWidth];

    i = 0;
    while(isSmallerThen(i, newWidth)){
        int newHeight = otherTetris.alturas[i];
        this->jogo[i] = new char[newHeight];
        int j = 0;
        while(isSmallerThen(j, newHeight)){
            this->jogo[i][j] = otherTetris.jogo[i][j];
            j++;
        }
        this->alturas[i] = newHeight;
        i++;
    }
    return *this;
}

//-------------------------------------------------- GETS

//Retorna conteúdo do pixel especificado
char Tetris::get(const int c, const int l)const{

    if (isSmallerThen(c, this->columns) && 
        isSmallerThen(l, this->alturas[c])){

        return this->jogo[c][l];

    } else {

        return empty();
    }
}

//Retorna quantidade de colunas existentes no jogo
int Tetris::getNumColunas()const{return this->columns;}

//Retorna a altura da coluna C
int Tetris::getAltura(int c)const{return this->alturas[c];}

//Retorna a altura máxima do jogo
int Tetris::getAltura()const{
    int i = 0;
    int maxHeight = 0;
    while(isSmallerThen(i, this->columns)){
        if (alturas[i] > maxHeight) maxHeight = i;
        i++;
    }
    return maxHeight;
}

//Retorna a altura mínima do jogo
int Tetris::getMinHeight()const{
    int i = 0;
    int minHeight = getAltura();
    while(isSmallerThen(i, this->columns)){
        if (alturas[i] < minHeight) minHeight = i;
        i++;
    }
    return minHeight;
}

//-------------------------------------------------- SETS

void Tetris::set(int c, int l, char value){
    int oldHeight = alturas[c];
    int newHeight = l+1;
    if (isFilled(c, l)){
        this->jogo[c][l] = value;
        return;
    } 
    char * newColumn = new char [newHeight];
    int i = 0;
    while (isSmallerThen(i, newHeight)){
        if (areEquals(i, l)) newColumn[i] = value;
        else if (isSmallerThen(i, oldHeight)) newColumn[i] = this->jogo[c][i];
        else newColumn[i] = empty();
        i++;
    }
    delete [] this->jogo[c];
    this->jogo[c] = new char [newHeight];
    i = 0;
    while (isSmallerThen(i, newHeight)){
        this->jogo[c][i] = newColumn[i];
        i++;
    }
    alturas[c] = newHeight;
    delete [] newColumn;

}

//-------------------------------------------------- REMOVES
void Tetris::removeColuna(int c){
    
    if(isSmallerThen(c, 0) || 
       isBiggerThen(c, this->columns) || 
       areEquals(c, this->columns)) 
            return;

    int oldWidth = this->columns;
    int newWidth = oldWidth-1;

    int i = c;
    //Todas as colunas seguintes à c devem ser modificadas
    while (isSmallerThen(i, newWidth)){
    
        int newHeight = alturas[i+1];
        int oldHeight = alturas[i];
        char * newColumn = new char [newHeight];

        int j = 0;
        while (isSmallerThen(j, newHeight)){
            newColumn[j] = this->jogo[i+1][j];
            j++;
        }

        delete [] this->jogo[i];
        this->jogo[i] = new char [newHeight];

        j = 0;
        while (isSmallerThen(j, newHeight)){
            this->jogo[i][j] = newColumn[j];
            j++;
        }
        delete [] newColumn;
        i++;
    }
    delete [] jogo[newWidth];

    //Realocação do vetor de alturas
    int * newHeights = new int [newWidth];

    int j = 0;
    while (isSmallerThen(j, newWidth)){
        if (isSmallerThen(j, c)) newHeights[j] = this->alturas[j];
        else newHeights[j] = this->alturas[j+1];
        j++;
    }

    delete [] this->alturas;
    this->alturas = new int [newWidth];

    j = 0;
    while (isSmallerThen(j, newWidth)){
        this->alturas[j] = newHeights[j];
        j++;
    }
    delete [] newHeights;

    //Atualização da largura do jogo
    this->columns = newWidth;

}

void Tetris::removeLinhasCompletas(){


}

//-------------------------------------------------- ADIÇÕES

bool Tetris::adicionaForma(int c, int l, char id, int r){
    
    //C e L devem ser valores não negativos existentes nos limites do tabuleiro
    if (isSmallerThen(c, 0) || isSmallerThen(l, 0)) return false;
    if (isBiggerThen(c, this->columns) || areEquals(c, this->columns)) return false;

    //Cada id identifica uma peça que será chamada
    switch(id){
        case 'I':
            return addI(c, l, r);
         case 'J':
            return addJ(c, l, r);
        case 'L':
            return addL(c, l, r);
        case 'O':
            return addO(c, l, r);
        case 'S':
            return addS(c, l, r);
        case 'T':
            return addT(c, l, r);
        case 'Z':
            return addZ(c, l, r); 
        default:
            return false;
    }
    return false;
}

bool Tetris::addI(int c, int l, int r){

    char value = 'I';
    
    if (areEquals(r, 0) || 
        areEquals(r, 180)){
        
        if (areEquals(c, this->columns) ||
            isBiggerThen(c, this->columns) ||
            isSmallerThen(l-3, 0))
                return false;

        if (get(c, l) != empty() ||
            get(c, l-1) != empty() ||
            get(c, l-2) != empty() ||
            get(c, l-3) != empty())
                return false;

        set(c, l, value);
        set(c, l-1, value);
        set(c, l-2, value);
        set(c, l-3, value);

        return true;

    } else{

        if (areEquals(c+3, this->columns) ||
            isBiggerThen(c+3, this->columns) ||
            isSmallerThen(l, 0))
                return false;

        if (get(c, l) != empty() ||
            get(c+1, l) != empty() ||
            get(c+2, l) != empty() ||
            get(c+3, l) != empty()){
                return false;
            }

        set(c, l, value);
        set(c+1, l, value);
        set(c+2, l, value);
        set(c+3, l, value);     

        return true;
    }
    return false;
}

bool Tetris::addJ(int c, int l, int r){

    char value = 'J';

    switch (r){
        case 0:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+3, this->columns) ||
                isBiggerThen(c+3, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c, l) != empty() ||
                get(c+1, l) != empty() ||
                get(c+2, l) != empty() ||
                get(c+3, l) != empty() ||
                get(c+3, l-1) != empty())
                    return false;

            //Adição da peça
            set(c, l, value);
            set(c+1, l, value);
            set(c+2, l, value);
            set(c+3, l, value);
            set(c+3, l-1, value);

            return true;

        case 90:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-3, 0))
                    return false;

            if (get(c+1, l) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+1, l-2) != empty() ||
                get(c+1, l-3) != empty() ||
                get(c, l-3) != empty())
                    return false;

            set(c+1, l, value);
            set(c+1, l-1, value);
            set(c+1, l-2, value);
            set(c+1, l-3, value);
            set(c, l-3, value);     

            return true;

        case 180:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+3, this->columns) ||
                isBiggerThen(c+3, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+2, l-1) != empty() ||
                get(c+3, l-1) != empty())
                    return false;

            //Adição da peça
            set(c, l, value);
            set(c, l-1, value);
            set(c+1, l-1, value);
            set(c+2, l-1, value);
            set(c+3, l-1, value);

            return true;

        case 270:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-3, 0))
                    return false;

            if (get(c, l) != empty() ||
                get(c+1, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c, l-2) != empty() ||
                get(c, l-3) != empty())
                    return false;

            set(c, l, value);     
            set(c+1, l, value);
            set(c, l-1, value);
            set(c, l-2, value);
            set(c, l-3, value);

            return true;
    }
    return false;
}

bool Tetris::addL(int c, int l, int r){
    
    char value = 'L';

    switch (r){
        case 0:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+3, this->columns) ||
                isBiggerThen(c+3, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c, l) != empty() ||
                get(c+1, l) != empty() ||
                get(c+2, l) != empty() ||
                get(c+3, l) != empty() ||
                get(c, l-1) != empty())
                    return false;

            //Adição da peça
            set(c, l, value);
            set(c+1, l, value);
            set(c+2, l, value);
            set(c+3, l, value);
            set(c, l-1, value);

            return true;

        case 90:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-3, 0))
                    return false;

            if (get(c+1, l) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+1, l-2) != empty() ||
                get(c+1, l-3) != empty() ||
                get(c, l) != empty())
                    return false;

            set(c+1, l, value);
            set(c+1, l-1, value);
            set(c+1, l-2, value);
            set(c+1, l-3, value);
            set(c, l-3, value);     

            return true;

        case 180:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+3, this->columns) ||
                isBiggerThen(c+3, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c+3, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+2, l-1) != empty() ||
                get(c+3, l-1) != empty())
                    return false;

            //Adição da peça
            set(c+3, l, value);
            set(c, l-1, value);
            set(c+1, l-1, value);
            set(c+2, l-1, value);
            set(c+3, l-1, value);

            return true;

        case 270:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-3, 0))
                    return false;

            if (get(c, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c, l-2) != empty() ||
                get(c, l-3) != empty() ||
                get(c+1, l-3) != empty())
                    return false;

            set(c, l, value);     
            set(c, l-1, value);
            set(c, l-2, value);
            set(c, l-3, value);
            set(c+1, l-3, value);

            return true;
    }
    return false;
}

bool Tetris::addO(int c, int l, int r){
    char value = 'O';
        
    if (areEquals(c+1, this->columns) ||
        isBiggerThen(c+1, this->columns) ||
        isSmallerThen(l-1, 0))
            return false;

    if (get(c, l) != empty() ||
        get(c, l-1) != empty() ||
        get(c-1, l) != empty() ||
        get(c-1, l-1) != empty())
            return false;

    set(c, l, value);
    set(c, l-1, value);
    set(c-1, l, value);
    set(c-1, l-1, value);

    return true;
}

bool Tetris::addS(int c, int l, int r){

    char value = 'S';
    
    if (areEquals(r, 0) || 
        areEquals(r, 180)){
        
        if (areEquals(c+2, this->columns) ||
            isBiggerThen(c+2, this->columns) ||
            isSmallerThen(l-1, 0))
                return false;

        if (get(c+1, l) != empty() ||
            get(c, l-1) != empty() ||
            get(c+2, l) != empty() ||
            get(c+1, l-1) != empty())
                return false;

        set(c+1, l, value);
        set(c, l-1, value);
        set(c+2, l, value);
        set(c+1, l-1, value);

        return true;

    } else{

        if (areEquals(c+1, this->columns) ||
            isBiggerThen(c+1, this->columns) ||
            isSmallerThen(l-2, 0))
                return false;

        if (get(c, l) != empty() ||
            get(c, l-1) != empty() ||
            get(c+1, l-1) != empty() ||
            get(c+1, l-2) != empty())
                return false;

        set(c, l, value);
        set(c, l-1, value);
        set(c+1, l-1, value);
        set(c+1, l-2, value);     

        return true;
    }
    return false;
}

bool Tetris::addT(int c, int l, int r){
    
    char value = 'T';

    switch (r){
        case 0:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+2, this->columns) ||
                isBiggerThen(c+2, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c, l) != empty() ||
                get(c+1, l) != empty() ||
                get(c+2, l) != empty() ||
                get(c+1, l-1) != empty())
                    return false;

            //Adição da peça
            set(c, l, value);
            set(c+1, l, value);
            set(c+2, l, value);
            set(c+1, l-1, value);

            return true;

        case 90:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-2, 0))
                    return false;

            if (get(c+1, l) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+1, l-2) != empty() ||
                get(c, l-1) != empty())
                    return false;

            set(c+1, l, value);
            set(c+1, l-1, value);
            set(c+1, l-2, value);
            set(c, l-1, value);     

            return true;

        case 180:
            
            //Possibilidade de encaixe no tabuleiro
            if (areEquals(c+2, this->columns) ||
                isBiggerThen(c+2, this->columns) ||
                isSmallerThen(l-1, 0))
                    return false;

            //Disponibilidade dos pixels 
            if (get(c+1, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c+1, l-1) != empty() ||
                get(c+2, l-1) != empty())
                    return false;

            //Adição da peça
            set(c+1, l, value);
            set(c, l-1, value);
            set(c+1, l-1, value);
            set(c+2, l-1, value);

            return true;

        case 270:
            if (areEquals(c+1, this->columns) ||
                isBiggerThen(c+1, this->columns) ||
                isSmallerThen(l-2, 0))
                    return false;

            if (get(c, l) != empty() ||
                get(c, l-1) != empty() ||
                get(c, l-2) != empty() ||
                get(c+1, l-1) != empty())
                    return false;

            set(c, l, value);     
            set(c, l-1, value);
            set(c, l-2, value);
            set(c+1, l-1, value);

            return true;
    }
    return false;
}

bool Tetris::addZ(int c, int l, int r){

    char value = 'Z';
    
    if (areEquals(r, 0) || 
        areEquals(r, 180)){
        
        if (areEquals(c+2, this->columns) ||
            isBiggerThen(c+2, this->columns) ||
            isSmallerThen(l-1, 0))
                return false;

        if (get(c+1, l) != empty() ||
            get(c, l) != empty() ||
            get(c+2, l-1) != empty() ||
            get(c+1, l-1) != empty())
                return false;

        set(c+1, l, value);
        set(c, l, value);
        set(c+2, l-1, value);
        set(c+1, l-1, value);

        return true;

    } else{

        if (areEquals(c+1, this->columns) ||
            isBiggerThen(c+1, this->columns) ||
            isSmallerThen(l-2, 0))
                return false;

        if (get(c, l-1) != empty() ||
            get(c, l-2) != empty() ||
            get(c+1, l) != empty() ||
            get(c+1, l-1) != empty())
                return false;

        set(c, l-1, value);
        set(c, l-2, value);
        set(c+1, l, value);
        set(c+1, l-1, value);     

        return true;
    }
    return false;
}
