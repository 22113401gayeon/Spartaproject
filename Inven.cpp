#include <iostream>
using namespace std;

template <typename T>
class Inventory {
private:
    T* pItems_;    
    int capacity_;  
    int size_;      

public:
    
    Inventory(int capacity = 10)
        : capacity_(capacity > 0 ? capacity : 1), size_(0) {
        pItems_ = new T[capacity_];
    }

    ~Inventory() {
        delete[] pItems_;
        pItems_ = nullptr;
    }

    void AddItem(const T& item) {
        if (size_ < capacity_) {
            pItems_[size_] = item;
            ++size_;
        }
        else {
            cout << "인벤토리가 꽉 찼습니다!" << endl;
        }
    }

    void RemoveLastItem() {
        if (size_ > 0) {
            --size_;
        }
        else {
            cout << "인벤토리가 비어있습니다." << endl;
        }
    }

    
    int GetSize() const {
        return size_;
    }

    
    int GetCapacity() const {
        return capacity_;
    }

   
    void PrintAllItems() const {
        if (size_ == 0) {
            cout << "(비어있음)" << endl;
            return;
        }

        for (int i = 0; i < size_; ++i) {
            pItems_[i].PrintInfo(); 
        }
    }
};

class Item {
private:
    string name_;
    int price_;
public:
    Item(string name = "Unknown", int price = 0) : name_(name), price_(price) {}

    void PrintInfo() const {
        cout << "[이름: " << name_ << ", 가격: " << price_ << "G]" << endl;
    }
};

int main() {
    Inventory<Item> inv(3);

    inv.AddItem(Item("포션", 50));
    inv.AddItem(Item("칼", 200));
    inv.AddItem(Item("방패", 150));
    inv.AddItem(Item("활", 300)); 

    cout << "현재 아이템 (" << inv.GetSize() << "/" << inv.GetCapacity() << "):" << endl;
    inv.PrintAllItems();

    inv.RemoveLastItem();
    cout << "\n마지막 아이템 제거 후:" << endl;
    inv.PrintAllItems();

    inv.RemoveLastItem();
    cout << "\n마지막 아이템 제거 후:" << endl;
    inv.PrintAllItems();

    inv.RemoveLastItem();
    cout << "\n마지막 아이템 제거 후:" << endl;
    inv.PrintAllItems();

    return 0;
}