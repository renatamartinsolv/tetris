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
	game.adicionaForma(0, 13, 'L', 180);
	game.exibeJogo();
	game.adicionaForma(12, 5, 'J', 90);
	game.exibeJogo();
	game.adicionaForma(15, 5, 'J', 270);
	game.exibeJogo();
	game.adicionaForma(22, 4, 'L', 0);
	game.exibeJogo();
	game.adicionaForma(0, 10, 'L', 90);
	game.exibeJogo();
	game.adicionaForma(0, 20, 'L', 180);
	game.exibeJogo();
	game.adicionaForma(10, 20, 'L', 270);
	game.exibeJogo();
	return 0;
}
