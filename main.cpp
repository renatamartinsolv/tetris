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
	return 0;
}
