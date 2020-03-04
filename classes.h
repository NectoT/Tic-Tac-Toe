#pragma once

#include <tuple>

using namespace std;

class Player {
public:

	virtual tuple<int, int, const char*> makeTurn(int const& fields) const; // виртуальная функция - то есть в классах наследниках она переопределена

private:
	Player(); // Конструктор в привате чтобы нельзя было создать базовый класс Player, только его наследников

protected:
	char* name;
};

class Human : public Player {
public:

	Human();

	Human(const char* name);

private:

};

class AI : public Player {
public:

	AI();

private:

};

class Game {
public:

	Game(Player p1, Player p2);

	~Game();

	void gameflow();

	void menu();

	void reset();

	char* drawFields() const;

	char* drawX() const;

	char* drawO() const;

	char* drawE() const;

	void setField(int x, int y, char state);

	void editSave(int x, int y, char state);

	void loadSave(int id);

	void deleteSave();

	void checkVictory() const;

private:
	Player player1;
	Player player2;

	int* fields; // Двумерный массив 3x3

	tuple<bool, const char*> game_state; // первый элемент - само состояние, второй - описание причины этого состояния

	static int quantity;
	int id;
};