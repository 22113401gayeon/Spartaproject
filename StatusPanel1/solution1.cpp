#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
    cout << "* ������ ���޵Ǿ����ϴ�. (HP, MP ���� �� " << count << "��)" << endl;
}

int main() {
    int HP = 0,
        MP = 0,
        atk = 0,
        def = 0;
    int status[4] = { HP, MP, atk, def };

    do {
        cout << "HP�� MP�� �Է����ּ���: ";
        cin >> HP >> MP;

        if (HP <= 50 || MP <= 50) {
            cout << "HP�� MP�� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
        }
    } while (HP <= 50 || MP <= 50);


    do {
        cout << "���ݷ°� ������ �Է����ּ���: ";
        cin >> atk >> def;

        if (atk <= 0 || def <= 0) {
            cout << "���ݷ��̳� ���� ���� �ʹ� �۽��ϴ�. �ٽ� �Է����ּ���." << endl;
        }
    } while (atk <= 0 || def <= 0);

    int hpPotion = 0;
    int mpPotion = 0;

    setPotion(5, &hpPotion, &mpPotion);

    cout << "=============================================" << endl;
    cout << "<���� ���� �ý���>" << endl
        << "1. HP ȸ��" << endl
        << "2. MP ȸ��" << endl
        << "3. HP ��ȭ" << endl
        << "4. MP ��ȭ" << endl
        << "5. ���� ��ų ���" << endl;
    while (true) {
        cout << "��ȣ�� �������ּ���: ";
        int option = 0;
        cin >> option;

        if (option == 1) {
            if (hpPotion <= 0) {
                cout << "������ �����մϴ�." << endl;
            }
            else {
                hpPotion -= 1;
                HP += 20;
                cout << "* HP�� 20 ȸ�� �Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl
                    << "���� HP: " << HP << endl
                    << "���� ���� �� : " << hpPotion << endl;
            }
        }
        else if (option == 2) {
            if (mpPotion <= 0) {
                cout << "������ �����մϴ�." << endl;
            }
            else {
                mpPotion -= 1;
                MP += 20;
                cout << "* MP�� 20 ȸ�� �Ǿ����ϴ�. ������ 1�� �����˴ϴ�." << endl
                    << "���� MP: " << MP << endl
                    << "���� ���� �� : " << mpPotion << endl;
            }
        }
        else if (option == 3) {
            HP *= 2;
            cout << "* HP�� 2��� ���� �Ͽ����ϴ�." << endl
                << "���� HP: " << HP << endl;
        }
        else if (option == 4) {
            MP *= 2;
            cout << "* MP�� 2��� ���� �Ͽ����ϴ�." << endl
                << "���� MP: " << MP << endl;
        }
        else {
            if (MP < 50) {
                cout << "��ų ����� �Ұ� �մϴ�." << endl;
            }
            else {
                MP -= 50;
                cout << "* ��ų�� ����Ͽ� MP�� 50 �Ҹ� �Ǿ����ϴ�." << endl
                    << "���� MP: " << MP << endl;
            }
        }

    }
}