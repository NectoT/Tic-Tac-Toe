#include "classes.h"

using namespace std;

int main() {
	// пример обращения к TicTacToe
	TicTacToe& game = TicTacToe::get();
	game.start();
	return 0;
}