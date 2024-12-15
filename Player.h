#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    std::string name; // ���������� std::string ������ ������� char
    int score;

public:
    Player(); // ����������� �� ���������
    Player(const std::string& playerName); // ����������� � ����������
    const std::string& getName() const; // ����� ��� ��������� �����
    int getScore() const; // ����� ��� ��������� �����
    void incrementScore(); // ����� ��� ���������� �����
    void resetScore(); // ����� ��� ������ �����
    void setName(const std::string& playerName); // ����� ��� ��������� �����
};

#endif // PLAYER_H