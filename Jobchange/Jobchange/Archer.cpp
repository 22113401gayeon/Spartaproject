#include "Archer.h"
#include <iostream>
using namespace std;

Archer::Archer(string nickname) : Player(nickname) {
    job_name = "±Ã¼ö";
    cout << "* ±Ã¼ö·Î ÀüÁ÷ÇÏ¿´½À´Ï´Ù." << endl;
     accuracy= 80;
}
void Archer::attack() {
    cout << "* È°À» ½ð´Ù" << endl;
}