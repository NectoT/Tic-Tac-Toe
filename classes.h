#pragma once

#include <tuple>
#include <fstream>
#include <string>

using namespace std;

class Player {
public:

	virtual tuple<int, int> makeTurn(int const& fields) const; // виртуальная функция - то есть в классах наследниках она может быть переопределена

	virtual char getSide() const;

	virtual char* getName() const;

private:

	virtual void setSide(char side);

	virtual void setName();

protected:
	Player(); // Конструктор в протектеде чтобы нельзя было создать базовый класс Player, только его наследников

	char* name;
	char side; // Сторона, за которую играет Player - 'x' или 'o'
};

class Human : public Player {
public:

	Human(char side);

	Human(const char* name, char side);

private:

};

class AI : public Player {
public:

	AI(char side);

private:

};

class Menu {
public:

	// ссылка на ещё не определённых игроков, одна из задач меню - определить их
	// id_save - позднее используется в создании объекта Game, который может загрузить сохранение под номером id_save
	Menu(Player& player1, Player& player2, int* id_save);

	void drawMenu() const;

	void menu();

private:

	Player& player1;
	Player& player2;

};

class Game {
public:

	Game(const Player& player1, const Player& player2);

	Game(int id); // при загрузке сохранённой партии с номером id 

	~Game();

	void gameflow();

private:

	char* drawFields() const;

	char* drawX() const;

	char* drawO() const;

	char* drawE() const;

	void setField(int x, int y, char state);

	void createSave();

	void editSave(int x, int y, char state);

	void deleteSave();

	void checkVictory();

	const Player* player1;
	const Player* player2;

	int** fields; // Двумерный массив 3x3

	tuple<bool, const char*> game_state; // первый элемент - само состояние, второй - описание причины этого состояния

	int id; // Последний существовавший id хранится в saves.txt, id для нового класса - предыдущий id + 1
};

class TicTacToe { // должен быть singleton
public:
	~TicTacToe();

	static TicTacToe& get(); // возвращает ссылку на объект TicTacToe, который создаётся в первый вызов этой функции
	// Код выглядит примерно так:
	//	static TicTacToe instance;
	//	return instance;

	void start();

	// максимально абстрактный порядок работы TicTacToe:
	//	int id_save_holder;
	//	menu = Menu(player1, player2, &id_save_holder);
	//	menu.menu();
	//	if (id_save_holder = 0)
	//		game = Game(player1, player2)
	//	else
	//		game = Game(id_save_holder)
	//	game.gameflow()


	// Делаем невозможным присваивание и копирование экземляра этого класса
	void operator=(const TicTacToe&) = delete;
	TicTacToe(const TicTacToe&) = delete;

private:

	TicTacToe();

	Menu menu;
	Game game;
	Player* player1;
	Player* player2;
};