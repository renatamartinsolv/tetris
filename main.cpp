#include <iostream>
#include "Tetris.h"

using namespace std;

int main() {

	Tetris game = Tetris(5);
	cout << game.getAltura() << endl; 
	cout << game.getAltura(1) << endl; 
	cout << game.get(0,0) << endl;

	game.exibeJogo();
	game.~Tetris();
	return 0;
}
