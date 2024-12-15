#pragma once
#ifndef GAME_H
#define GAME_H

#define MAX_PUZZLES 3
#define MAX_PHRASES 3
#define MAX_ATTEMPTS 3

#include "Phrase.h"
#include "Player.h"
#include "Puzzle.h"
#include <string>

class Game {
private:
    Player player;
    Puzzle puzzles[MAX_PUZZLES];
    Phrase phrases[MAX_PHRASES];
    int currentPuzzle;

public:
    Game();
    void initializePuzzles();
    void initializePhrases();
    void setPlayerName(const std::string& playerName); // ���������� std::string
    const std::string& getPlayerName() const; // ���������� std::string
    int getPlayerScore() const;
    const std::string& getRandomPhrase() const; // ���������� std::string
    bool checkAnswer(int puzzleIndex, int answerIndex);
    void printPuzzle(int puzzleIndex) const;
    void printHint(int puzzleIndex) const;
    void startGame();
    void getAnswerAndCheck(int puzzleIndex);

    // ������ ��� ������������ ������ � ��������� ��������
    void printAllPuzzles();
    void demoTwoDimensionalArray();
};

#endif // GAME_H