#include "classes.h"

using namespace std;

int main() {
	// пример обращения к Game и к классам игроков
	Human p1 = Human("Misha");
	AI p2 = AI();
	Game game = Game(p1, p2);
	game.gameflow();
	return 0;
}