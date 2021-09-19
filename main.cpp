#include <iostream>
#include "Tetris.h"

using namespace std;

int main() {

	
	Tetris game = Tetris(8);
	game.adicionaForma(0, 0, 'I', 90);
	game.exibeJogo();
	game.adicionaForma(4, 0, 'I', 90);
	game.exibeJogo();
	game.adicionaForma(0, 2, 'J', 180);
	game.exibeJogo();
	game.adicionaForma(4, 2, 'J', 180);
	game.exibeJogo();
	cout << "removendo" << endl;
	game.removeLinhasCompletas();
	game.exibeJogo();
	/* game.adicionaForma(2, 1, 'O', 180);
	game.exibeJogo();
	game.adicionaForma(10, 10, 'O', 270);
	game.exibeJogo();
	game.adicionaForma(18, 8, 'J', 0);
	game.exibeJogo();
	game.adicionaForma(12, 5, 'J', 90);
	game.exibeJogo();
	game.adicionaForma(15, 5, 'J', 270);
	game.exibeJogo();
	game.adicionaForma(22, 4, 'L', 0);
	game.exibeJogo();
	game.adicionaForma(0, 10, 'L', 90);
	game.exibeJogo();
	game.adicionaForma(0, 14, 'L', 180);
	game.exibeJogo();
	game.adicionaForma(10, 20, 'L', 270);
	game.exibeJogo();
	game.adicionaForma(15, 20, 'S', 0);
	game.exibeJogo();
	game.adicionaForma(20, 20, 'S', 180);
	game.exibeJogo();
	game.adicionaForma(13, 15, 'S', 90);
	game.exibeJogo();
	game.adicionaForma(20, 15, 'S', 270);
	game.exibeJogo();
	game.adicionaForma(18, 3, 'Z', 0);
	game.exibeJogo();
	game.adicionaForma(8, 15, 'Z', 180);
	game.exibeJogo();
	game.adicionaForma(5, 15, 'Z', 90);
	game.exibeJogo();
	game.adicionaForma(2, 4, 'Z', 270);
	game.exibeJogo();
	game.adicionaForma(30, 3, 'T', 0);
	game.exibeJogo();
	game.adicionaForma(30, 15, 'T', 180);
	game.exibeJogo();
	game.adicionaForma(36, 15, 'T', 90);
	game.exibeJogo();
	game.adicionaForma(30, 10, 'T', 270);
	game.exibeJogo(); */
	game.~Tetris();
	return 0;
}
