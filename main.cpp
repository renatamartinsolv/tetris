#include <iostream>
#include "Tetris.h"

using namespace std;

int main() {

	Tetris tetris = Tetris(4);
	tetris.exibeJogo();
	tetris.adicionaForma(0, 5, 'I', 0);
	tetris.exibeJogo();
	tetris.~Tetris();
	return 0;
}
