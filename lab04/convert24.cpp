#include <iostream>
using namespace std; 

void printclock(int hours, int minutes, int seconds) {
    if (hours < 10)
        cout << "0";
    cout << hours << ":";
    if (minutes < 10)
        cout << "0";
    cout << minutes << ":";
    if (seconds < 10)
        cout << "0";
    cout << seconds;
}
void convert24(int seconds) {
    int minutes = seconds / 60;
    seconds = seconds % 60;
    int hours = seconds / 3600;
    printclock(hours, minutes, seconds);
    cout << endl;

}
void convert24(int minutes, int seconds){
    minutes = minutes + (seconds / 60) ;
    seconds = seconds % 60;
    int hours = minutes / 60;
    minutes = minutes % 60;
    printclock(hours, minutes, seconds);
    cout << endl;
}

void convert24(int hours, int minutes, int seconds) {
    minutes += seconds / 60;
    seconds = seconds % 60;
    hours += minutes / 60;
    minutes = minutes % 60;
    int days = hours / 24;
    hours = hours % 24;
    cout << "+" << days << ", ";
    printclock(hours, minutes, seconds);
    cout << endl;
}

int main(){
    int hours, minutes, seconds;
    cout << "Enter hours: "; 
    cin >> hours;
    cout << "Enter minutes: ";
    cin >> minutes;
    cout << "Enter seconds: ";
    cin >> seconds;
    if (hours == 0 && minutes == 0) {
        convert24(seconds); 
    } else if (hours == 0) {
        convert24(minutes, seconds) ;
    } else {
        convert24(hours, minutes, seconds); 
    }
    
}