#define _CRT_SECURE_NO_WARNINGS
#include "Game.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

Game::Game() : currentPuzzle(0) {}

void Game::initializePuzzles() {
    puzzles[0] = Puzzle("��� ����� ���� ����� � ����, �� ��� ���� �� ���������?", 0, "� ����� �������� ���� ���������.", "�� ������ ��������� ��� � ������.", "��� �������� ����� ������������ ����� �������.", "��������", "���������", "����");
    puzzles[1] = Puzzle("�� �� �����, �� �� �������, ���������� - � ����� �������.", 1, "��� ����������� ����������.", "� ���� ���� ������ � ����� �������.", "� ���� ��� �����.", "���������", "�������", "������");
    puzzles[2] = Puzzle("� ������ ��� ��� � ����� ��� ����. ��� � �����?", 1, "��� ��������� �������, ������� �� ������ ��������.", "��� ���������, ����� ���� ���������� �� �����������.", "�� ������ ������� ��� � ����� ��� �������.", "�����", "���", "�����");
}

void Game::initializePhrases() {
    phrases[0] = Phrase("� ���� ������� ������� �����.\n");
    phrases[1] = Phrase("� ���� ������� ������� �����.\n");
    phrases[2] = Phrase("��� ������� �������� �� �������.\n");
}

void Game::setPlayerName(const std::string& playerName) {
    player = Player(playerName);
}

const std::string& Game::getPlayerName() const {
    return player.getName();
}

int Game::getPlayerScore() const {
    return player.getScore();
}

const std::string& Game::getRandomPhrase() const {
    int randomIndex = rand() % MAX_PHRASES;
    return phrases[randomIndex].getText();
}

bool Game::checkAnswer(int puzzleIndex, int answerIndex) {
    if (answerIndex == puzzles[puzzleIndex].getCorrectAnswerIndex()) {
        player.incrementScore();
        return true;
    }
    else {
        puzzles[puzzleIndex].incrementAttempts();
        return false;
    }
}

void Game::printPuzzle(int puzzleIndex) const {
    std::cout << "\n�������: " << puzzles[puzzleIndex].getQuestion() << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ") " << puzzles[puzzleIndex].getOption(i) << std::endl;
    }
}

void Game::printHint(int puzzleIndex) const {
    int attempts = puzzles[puzzleIndex].getAttempts();
    if (attempts < MAX_HINTS) {
        std::cout << "���������: " << puzzles[puzzleIndex].getHint(attempts) << std::endl;
    }
}

void Game::startGame() {
    for (currentPuzzle = 0; currentPuzzle < MAX_PUZZLES; currentPuzzle++) {
        printPuzzle(currentPuzzle);
        getAnswerAndCheck(currentPuzzle);
    }
    std::cout << "���� ���������! " << getPlayerName() << " �����(�) " << getPlayerScore() << " �������." << std::endl;
    if (getPlayerScore() == 0) {
        std::cout << "�� �� ������ �� ����� �������. ���������� �����!\n" << std::endl;
        player.resetScore();
        startGame();
    }
}

void Game::getAnswerAndCheck(int puzzleIndex) {
    int answerIndex = 0;
    bool validInput = false;

    while (!validInput) {
        try {
            std::cout << "������� ����� ������ (1-3): ";
            std::cin >> answerIndex;
            if (std::cin.fail() || answerIndex < 1 || answerIndex > 3) {
                throw std::invalid_argument("������� ����� �� 1 �� 3.");
            }
            validInput = true;
        }
        catch (const std::invalid_argument& e) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << e.what() << std::endl;
        }
    }

    if (checkAnswer(puzzleIndex, answerIndex - 1)) {
        std::cout << "���������! �������!\n" << std::endl;
        std::cout << getRandomPhrase() << std::endl;
    }
    else {
        if (puzzles[puzzleIndex].getAttempts() < MAX_ATTEMPTS) {
            printHint(puzzleIndex);
            getAnswerAndCheck(puzzleIndex);
        }
        else {
            std::cout << "��� ������� �������. ������� � ��������� �������.\n" << std::endl;
        }
    }
}

// ����� ��� ������������ ������ � ���������� �������� ��������
void Game::printAllPuzzles() {
    for (const auto& puzzle : puzzles) {
        std::cout << puzzle.getQuestion() << std::endl;
    }
}

// ����� ��� ������������ ������ � ��������� �������� ��������
void Game::demoTwoDimensionalArray() {
    Puzzle puzzleMatrix[2][2] = {
        {puzzles[0], puzzles[1]},
        {puzzles[2], Puzzle("�������������� �������", 0, "��������� 1", "��������� 2", "��������� 3", "������� 1", "������� 2", "������� 3")}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            std::cout << puzzleMatrix[i][j].getQuestion() << std::endl;
        }
    }
}