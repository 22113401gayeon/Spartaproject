#include "Magician.h"
#include <iostream>
using namespace std;

Magician::Magician(string nickname) : Player(nickname) {
    job_name = "마법사";
    cout << "* 마법사로 전직하였습니다." << endl;
    MP = 80;
}
void Magician::attack() {
    cout << "* 마법을 부린다" << endl;
}