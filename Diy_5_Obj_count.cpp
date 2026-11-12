#include <iostream>
using namespace std;

class Counter {
private:
    int count;
    static int totalCreated;
    static int currentlyAlive;

public:
    
    Counter(int c = 0) : count(c) {
        totalCreated++;
        currentlyAlive++;
    }

    
    Counter(const Counter& other) : count(other.count) {
        totalCreated++;
        currentlyAlive++;
    }


    ~Counter() {
        currentlyAlive--;
    }

    void increment() { count++; }
    int getValue() const { return count; }

    static void reportStats() {
        cout << "Total created: " << totalCreated 
             << " | Currently alive: " << currentlyAlive << endl;
    }
};


int Counter::totalCreated = 0;
int Counter::currentlyAlive = 0;

int main() {
    Counter::reportStats(); 

    Counter c1;
    Counter c2(10);
    Counter::reportStats(); 

    {
        Counter c3;
        Counter::reportStats(); 
    } // c3 goes out of scope and is destroyed here

    Counter::reportStats(); 
    return 0;
}