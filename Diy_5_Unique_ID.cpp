#include <iostream>
#include <string>
using namespace std;

class Order {
private:
    int orderID;
    string itemName;
    static int nextID;

public:
    Order(string item) : itemName(item) {
        orderID = nextID++;
    }

    void displayOrder() const {
        cout << "Order ID: " << orderID << " | Item: " << itemName << endl;
    }
};


int Order::nextID = 1001;

int main() {
    Order o1("Laptop");
    Order o2("Wireless Mouse");
    Order o3("Mechanical Keyboard");

    o1.displayOrder(); 
    o2.displayOrder(); 
    o3.displayOrder(); 

    return 0;
}