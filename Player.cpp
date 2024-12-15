#include "Player.h"

// ����������� �� ���������
Player::Player() : name(""), score(0) {}

// ����������� � ����������
Player::Player(const std::string& playerName) : name(playerName), score(0) {}

// ����� ��� ��������� ����� ������
const std::string& Player::getName() const {
    return name;
}

// ����� ��� ��������� ����� ������
int Player::getScore() const {
    return score;
}

// ����� ��� ���������� �����
void Player::incrementScore() {
    score++;
}

// ����� ��� ������ �����
void Player::resetScore() {
    score = 0;
}

// ����� ��� ��������� �����
void Player::setName(const std::string& playerName) {
    name = playerName;
}