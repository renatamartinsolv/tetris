#include <iostream>
#include "Tetris.h"

using namespace std;

void exibeJogo(Tetris &game){
    int alturaMaxima = game.getAltura();
    cout << "------------------------ TETRIS ------------------------" << endl;
    for (int i = alturaMaxima-1; i>=0; i--){
        for (int j = 0; j<game.getNumColunas(); j++){
            cout << game.get(j, i);
        }
        cout << endl;
    }
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i<game.getNumColunas(); i++){
        cout << game.getAltura(i);
    }
    cout << endl;
} 

int main(){
    Tetris game7(17);
    exibeJogo(game7);

    game7.adicionaForma(0, 0, 'I', 270);
    exibeJogo(game7);

    game7.removeLinhasCompletas();
    game7.removeColuna(16);
    exibeJogo(game7);

    game7.adicionaForma(0, 1, 'I', 90);
    game7.adicionaForma(4, 0, 'I', 90);
    game7.adicionaForma(8, 0, 'I', 90);
    game7.adicionaForma(12, 0, 'I', 90);
    exibeJogo(game7);

    game7.adicionaForma(4, 1, 'I', 90);
    game7.adicionaForma(8, 1, 'I', 90);
    game7.adicionaForma(12, 1, 'I', 90);
    exibeJogo(game7);

    game7.adicionaForma(0, 2, 'I', 90);
    game7.adicionaForma(4, 2, 'I', 90);
    game7.adicionaForma(8, 2, 'I', 90);
    game7.adicionaForma(12, 2, 'I', 90);
    game7.adicionaForma(8, 3, 'I', 90);
    game7.adicionaForma(0, 4, 'I', 90);
    game7.adicionaForma(4, 4, 'I', 90);
    game7.adicionaForma(8, 4, 'I', 90);
    game7.adicionaForma(12, 4, 'I', 90);

    exibeJogo(game7);
    
    game7.adicionaForma(10, 5, 'I', 90);
    game7.adicionaForma(1, 5, 'I', 90);
    exibeJogo(game7);

    game7.removeLinhasCompletas();
    exibeJogo(game7);

    Tetris game9 = game7;
    exibeJogo(game9);
     
    game7.removeColuna(0);
    game7.removeColuna(0);
    game7.removeColuna(0);
    game7.removeColuna(0);
    game7.removeColuna(0);
    exibeJogo(game7);

    game7.removeColuna(game7.getNumColunas()-1);
    game7.removeColuna(game7.getNumColunas()-1);
    game7.removeColuna(game7.getNumColunas()-1);
    game7.removeColuna(game7.getNumColunas()-1);
    exibeJogo(game7);
    
    return 0;
}