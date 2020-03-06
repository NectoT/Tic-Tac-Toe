#include "classes.h"

using namespace std;

int main() {
	// пример обращения к Путину
	TicTacToe& game = TicTacToe::get();
	game.start();
	return 0;
}
