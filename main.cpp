#include <iostream>
#include "Tetris.h"

using namespace std;

int main() {

	
	Tetris game = Tetris(28);
	game.adicionaForma(0, 6, 'I', 0);
	game.exibeJogo();
	game.adicionaForma(1, 6, 'I', 0);
	game.exibeJogo();
	game.adicionaForma(6, 4, 'I', 90);
	game.exibeJogo();
	game.adicionaForma(6, 5, 'I', 90);
	game.exibeJogo();
	game.adicionaForma(3, 8, 'I', 270);
	game.exibeJogo();
	game.adicionaForma(5, 3, 'I', 180);
	game.exibeJogo();
	cout << "Removendo coluna 6" << endl;
	game.removeColuna(6);
	game.exibeJogo();
	cout << "Removendo coluna 4" << endl;
	game.removeColuna(4);
	game.exibeJogo();
	game.adicionaForma(1, 1, 'O', 0);
	game.exibeJogo();
	game.adicionaForma(7, 3, 'O', 90);
	game.exibeJogo();
	game.adicionaForma(2, 1, 'O', 180);
	game.exibeJogo();
	game.adicionaForma(10, 10, 'O', 270);
	game.exibeJogo();
	game.adicionaForma(18, 8, 'J', 0);
	game.exibeJogo();
	game.adicionaForma(20, 11, 'J', 180);
	game.exibeJogo();
	game.adicionaForma(12, 5, 'J', 90);
	game.exibeJogo();

	return 0;
}
