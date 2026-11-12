#include <iostream>
#include <iomanip>
using namespace std;

class Time {
private:
    int hours;
    int minutes;

public:
    Time(int h = 0, int m = 0) {
        hours = (h >= 0 && h < 24) ? h : 0;
        minutes = (m >= 0 && m < 60) ? m : 0;
    }

    void display() const {
        cout << setfill('0') << setw(2) << hours << ":" 
             << setfill('0') << setw(2) << minutes;
    }

    // Friend function declaration
    friend Time laterOf(Time t1, Time t2);
};

// Friend function definition
Time laterOf(Time t1, Time t2) {
    if (t1.hours > t2.hours) {
        return t1;
    } else if (t1.hours < t2.hours) {
        return t2;
    } else {
        // Hours are equal, compare minutes
        return (t1.minutes >= t2.minutes) ? t1 : t2;
    }
}

int main() {
    Time t1(14, 30);
    Time t2(14, 45);

    Time later = laterOf(t1, t2);

    cout << "Time 1: "; t1.display(); cout << endl;
    cout << "Time 2: "; t2.display(); cout << endl;
    cout << "Later time: "; later.display(); cout << endl;

    return 0;
}