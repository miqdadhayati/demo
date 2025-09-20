#include <iostream> 

using namespace std;

int countHoles(int number) {
    if (number == 0) {
        return 1; 
    }
    if (number < 10) {
        if ((number == 1)|| (number ==2) || (number == 3) || (number == 5) || ( number == 7)) {
            return 0; 
        } else if (number == 4 || number == 6 || number == 9) {
            return 1; 
        } else if (number == 8) {
            return 2; 
        }
    }
    int temp = number % 10;
    int holes = countHoles(temp);
    return holes + countHoles(number / 10);
}
int countHoles(const char *str) {
    if (*str == '\0') {
        return 0; 
    }
    char ch = *str;
    int holes = 0; 
    if ((ch == 'A') || (ch == 'D') || (ch =='O') || (ch == 'P') || (ch == 'Q') || (ch == 'R')) {
        holes = 1; 
    } else if (ch == 'B') {
        holes = 2; 
    } else {
        holes = 0; 
    }
    return holes + countHoles(str + 1);}
int main() {
    char choice;
    cout << "Enter d to input a number or s to input a string: ";
    cin >> choice;
    if (choice == 'd') {
        int number;
        cout << "Enter a number: ";
        cin >> number;
        int holes = countHoles(number);
        cout << "Number of holes is: " << holes << endl;
    } else if (choice == 's') {
        string input;
        cout << "Enter a string: ";
        cin >> input;
        int holes = countHoles(input.c_str());
        cout << "Number of holes are : " << holes << endl;
    } else {
        cout << "Invalid choice. Please enter d or s." << endl;
    }
    return 0;
}

