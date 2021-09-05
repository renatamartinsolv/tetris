#include <iostream>
#include <iomanip>
#include <string.h>
#include "Tetris.h"

using namespace std;

int main(int argc, char *argv[]) {

	Tetris tetris = Tetris(4);
	tetris.exibeJogo();
	return 0;
}
