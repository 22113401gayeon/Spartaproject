#include "Player.h"
#include <iostream>
using namespace std;

Player::Player(string nickname) {
    this->nickname = nickname;
    level = 1;
    HP = 0;
    MP = 0;
    power = 0;
    defence = 0;
    accuracy = 0;
    speed = 0;
}


void Player::printPlayerStatus() {
    cout << "------------------------------------" << endl;
    cout << "* ���� �ɷ�ġ" << endl;
    cout << "�г���: " << nickname << endl;
    cout << "Lv. " << level << endl;
    cout << "HP: " << HP << endl;
    cout << "MP: " << MP << endl;
    cout << "���ݷ�: " << power << endl;
    cout << "����: " << defence << endl;
    cout << "��Ȯ��: " << accuracy << endl;
    cout << "�ӵ�: " << speed << endl;
    cout << "------------------------------------" << endl;
}

string Player::getJobName() {
    return this ->job_name;
}
string Player::getNickname() {
    return this ->nickname;
}
int Player::getLevel() {
    return this ->level;
}
int Player::getHP() {
    return this ->HP;
}
int Player::getMP() {
    return this ->MP;
}
int Player::getPower() {
    return this ->power;
}
int Player::getDefence() {
    return this ->defence;
}
int Player::getAccuracy() {
    return this ->accuracy;
}
int Player::getSpeed() {
    return this ->speed;
}

void Player::setNickname(string nickname) {
    this->nickname = nickname;
}
bool Player::setHP(int HP) {
    this->HP = HP;
    return true;
}
bool Player::setMP(int MP) {
    this->MP = MP;
    return true;
}
void Player::setPower(int power) {
    this->power = power;
}
void Player::setDefence(int defence) {
    this->defence = defence;
}
void Player::setAccuracy(int accuracy) {
    this->accuracy = accuracy;
}
void Player::setSpeed(int speed) {
    this->speed = speed;
}