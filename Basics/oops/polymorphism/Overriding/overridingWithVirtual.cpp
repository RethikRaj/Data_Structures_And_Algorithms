#include <iostream>
using namespace std;

class Payment {
public:
    virtual void pay(int amount) {  
        cout << "Generic payment of " << amount << endl;
    }
};

class CreditCard : public Payment {
public:
    void pay(int amount) override{ 
        cout << "Paid " << amount << " using Credit Card" << endl;
    }
};

class UPI : public Payment {
public:
    void pay(int amount) override{
        cout << "Paid " << amount << " using UPI" << endl;
    }
};

int main() {
    // Upcasting
    CreditCard cc;
    Payment* p1 = &cc;   
    p1->pay(100); // OUTPUT : Paid 100 using Credit Card

    // Downcasting
    UPI *u = (UPI*) (new Payment());
    u->pay(100); // OUTPUT : Generic payment of 100
    delete u;  
    return 0;
}
