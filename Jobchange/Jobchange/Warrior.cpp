#include "warrior.h"
#include <iostream>
using namespace std;

Warrior::Warrior(string nickname) : Player(nickname) {
    job_name = "전사";
    cout << "* 전사로 전직하였습니다." << endl;
    HP = 80;
}
void Warrior::attack() {
    cout << "* 장검을 휘두른다" << endl;
}