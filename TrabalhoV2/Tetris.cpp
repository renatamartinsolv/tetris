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
            isSmallerThen(l, this->heights[c]));
}

//-------------------------------------------------- INICIALIZAÇÃO

//Construtor
Tetris::Tetris(const int size){
    this->columns = size;
    this->game = new char*[size];
    this->heights = new int[size];
    for(int i=0; i<size; i++){
        this->game[i] = new char[0];
        this->heights[i] = 0;
    }
}

//Destrutor
Tetris::~Tetris(){
    delete [] this->heights;

    int i = 0;
    while(isSmallerThen(i, this->columns)){
        delete [] this->game[i];
        i++;
    }
    delete [] this->game;
}

//Construtor de cópias
Tetris::Tetris(const Tetris &otherTetris){
    int gameColumns = otherTetris.columns;
    this->game = new char*[gameColumns];
    this->heights = new int[gameColumns];
    this->columns = gameColumns;
    int i = 0;
    while(isSmallerThen(i, gameColumns)){
        this->game[i] = new char[0];
        this->heights[i] = 0;
        i++;
    }
    *this = otherTetris;
}

//Operador de Atribuição
Tetris &Tetris::operator=(const Tetris &otherTetris){
    /* if(this == &otherTetris) return *this;
    int i = 0;
    delete [] heights;
    while(isSmallerThen(i, this->columns)){
        delete [] this->game[i];
        i++;
    }
    delete [] this->game;

    int gameColumns = otherTetris.columns;

    this->columns = gameColumns;
    this->game = new char*[gameColumns];
    this->heights = new int[gameColumns];

    i = 0;
    while(isSmallerThen(i, gameColumns)){
        int newHeight = otherTetris.heights[i];
        this->game[i] = new char[newHeight];
        for(int j = 0; j < newHeight; j++){
            this->game[i][j] = otherTetris.game[i][j];
        }
        this->heights[i] = newHeight;
        i++;
    }

    return *this; */
    if(this==&otherTetris) return *this;
    
    for(int i=0; i < columns; i++){
        delete [] game[i];
    }
    delete [] game;
    delete [] heights;

    this->columns = otherTetris.columns;
    this->heights = new int [otherTetris.columns];
    this->game = new char *[otherTetris.columns];

    for(int i = 0; i < otherTetris.columns; i++) {
        heights[i] = otherTetris.heights[i];
        game[i] = new char[otherTetris.heights[i]];
        for(int j = 0; j < otherTetris.heights[i]; j++){
            game[i][j] = otherTetris.game[i][j];
        }
    } 

    return *this;
}

//-------------------------------------------------- GETS

//Retorna conteúdo do pixel especificado
char Tetris::get(const int c, const int l)const{

    if (isSmallerThen(c, this->columns) && 
        isSmallerThen(l, this->heights[c])){

        return this->game[c][l];

    } else {

        return empty();
    }
}

//Retorna quantidade de colunas existentes no jogo
int Tetris::getNumColunas()const{return this->columns;}

//Retorna a altura da coluna C
int Tetris::getAltura(int c)const{return this->heights[c];}

//Retorna a altura máxima do jogo
int Tetris::getAltura()const{
    int i = 0;
    int maxHeigth = 0;
    while(isSmallerThen(i, this->columns)){
        if (heights[i] > maxHeigth) maxHeigth = i;
        i++;
    }
    return maxHeigth;
}

//-------------------------------------------------- SETS

void Tetris::set(int c, int l, char value){
    int oldHeight = heights[c];
    int newHeight = l+1;
    if (isFilled(c, l)){
        this->game[c][l] = value;
        return;
    } 
    char * newColumn = new char [newHeight];
    int i = 0;
    while (isSmallerThen(i, newHeight)){
        if (areEquals(i, l)) newColumn[i] = value;
        else if (isSmallerThen(i, oldHeight)) newColumn[i] = this->game[c][i];
        else newColumn[i] = empty();
        i++;
    }
    delete [] this->game[c];
    this->game[c] = new char [newHeight];
    i = 0;
    while (isSmallerThen(i, newHeight)){
        this->game[c][i] = newColumn[i];
        i++;
    }
    heights[c] = newHeight;
    delete [] newColumn;

}

//-------------------------------------------------- REMOVES
void Tetris::removeColuna(int c){

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
