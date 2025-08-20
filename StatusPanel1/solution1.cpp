#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 " << count << "개)" << endl;
}

int main() {
    int HP = 0,
        MP = 0,
        atk = 0,
        def = 0;
    int status[4] = { HP, MP, atk, def };

    do {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> HP >> MP;

        if (HP <= 50 || MP <= 50) {
            cout << "HP나 MP는 값이 너무 작습니다. 다시 입력해주세요." << endl;
        }
    } while (HP <= 50 || MP <= 50);


    do {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> atk >> def;

        if (atk <= 0 || def <= 0) {
            cout << "공격력이나 방어력 값이 너무 작습니다. 다시 입력해주세요." << endl;
        }
    } while (atk <= 0 || def <= 0);

    int hpPotion = 0;
    int mpPotion = 0;

    setPotion(5, &hpPotion, &mpPotion);

    cout << "=============================================" << endl;
    cout << "<스탯 관리 시스템>" << endl
        << "1. HP 회복" << endl
        << "2. MP 회복" << endl
        << "3. HP 강화" << endl
        << "4. MP 강화" << endl
        << "5. 공격 스킬 사용" << endl;
    while (true) {
        cout << "번호를 선택해주세요: ";
        int option = 0;
        cin >> option;

        if (option == 1) {
            if (hpPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
            }
            else {
                hpPotion -= 1;
                HP += 20;
                cout << "* HP가 20 회복 되었습니다. 포션이 1개 차감됩니다." << endl
                    << "현재 HP: " << HP << endl
                    << "남은 포션 수 : " << hpPotion << endl;
            }
        }
        else if (option == 2) {
            if (mpPotion <= 0) {
                cout << "포션이 부족합니다." << endl;
            }
            else {
                mpPotion -= 1;
                MP += 20;
                cout << "* MP가 20 회복 되었습니다. 포션이 1개 차감됩니다." << endl
                    << "현재 MP: " << MP << endl
                    << "남은 포션 수 : " << mpPotion << endl;
            }
        }
        else if (option == 3) {
            HP *= 2;
            cout << "* HP가 2배로 증가 하였습니다." << endl
                << "현재 HP: " << HP << endl;
        }
        else if (option == 4) {
            MP *= 2;
            cout << "* MP가 2배로 증가 하였습니다." << endl
                << "현재 MP: " << MP << endl;
        }
        else {
            if (MP < 50) {
                cout << "스킬 사용이 불가 합니다." << endl;
            }
            else {
                MP -= 50;
                cout << "* 스킬을 사용하여 MP가 50 소모 되었습니다." << endl
                    << "현재 MP: " << MP << endl;
            }
        }

    }
}