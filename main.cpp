#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
#include <cstdlib>
#include <ctime>
#include "Game.h"
#include "Player.h"
#include "Puzzle.h"

using namespace std;

#define MAX_HINT_LENGTH 200
#define MAX_OPTION_LENGTH 100
#define MAX_PHRASE_LENGTH 100
#define MAX_PUZZLES 3
#define MAX_ATTEMPTS 3
#define MAX_PHRASES 3
#define MAX_HINTS 3

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(NULL)); // Инициализация генератора случайных чисел

    Game game;

    // Работа с "статической" переменной
    Player staticPlayer;
    cout << "\nВведите ваше имя (используя английские символы): ";
    char name[MAX_OPTION_LENGTH];
    cin >> name;
    staticPlayer = Player(name);

    // Работа с динамической переменной
    Player* dynamicPlayer = new Player(staticPlayer);
    game.setPlayerName(dynamicPlayer->getName());
    game.initializePuzzles();
    game.initializePhrases();
    game.startGame();

    delete dynamicPlayer; // Освобождение памяти, выделенной для динамической переменной

    // Работа с динамическим массивом объектов класса
    int numPlayers;
    cout << "Введите количество игроков: ";
    cin >> numPlayers;
    Player* players = new Player[numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        players[i] = Player(name);
    }
    delete[] players; // Освобождение памяти, выделенной для динамического массива объектов

    // Работа с массивом динамических объектов класса
    Player** dynamicPlayers = new Player * [numPlayers];
    for (int i = 0; i < numPlayers; i++) {
        dynamicPlayers[i] = new Player();
        cout << "Введите имя игрока " << i + 1 << ": ";
        cin >> name;
        dynamicPlayers[i]->setName(name); // Задаем имя игрока через метод setName
    }

    for (int i = 0; i < numPlayers; i++) {
        delete dynamicPlayers[i];
    }
    delete[] dynamicPlayers; // Освобождение памяти, выделенной для массива указателей на динамические объекты

    // Демонстрация работы с одномерным массивом объектов
    cout << "\nВсе загадки:" << endl;
    game.printAllPuzzles();

    // Демонстрация работы с двумерным массивом объектов
    cout << "\nДвумерный массив загадок:" << endl;
    game.demoTwoDimensionalArray();

    return 0;
}