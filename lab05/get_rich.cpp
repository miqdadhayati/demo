#ifndef GET_RICH
#define GET_RICH

/*
Write your solution here.
*/
#include <iostream>
using namespace std; 

class TollBooth {
    private:
        unsigned int total_cars;
        unsigned int total_cash;
    public:
        TollBooth() : total_cars(0), total_cash(0) {}
        void payingCar() {
            total_cars++;
            total_cash += 50;
        }
        void nopayCar() {
            total_cars++;
        }
        void display() {
            cout << "Total cars: " << total_cars << endl;
            cout << "Total cash: " << total_cash << endl;
        }

}; 
int main() {
    TollBooth booth = TollBooth();
    char input;
    cout << " p for paying car, n for non paying car, 'q' to quit: ";
    while (true) {
        cin >> input;
        if (input == 'p') {
            booth.payingCar();
        } else if (input == 'n') {
            booth.nopayCar();
        } else if (input == 'q') {
            break;
        } else {
            cout << "Invalid input. Please enter p, n, or q: ";
        }
    }
    booth.display();
    return 0;
}
#endif  // GET_RICH
