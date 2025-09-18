#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int Comp(int a, int b) {
    return a - b;  
}

void swapping(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(int inputArray[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (Comp(inputArray[j], inputArray[j + 1]) > 0) {
                swapping(inputArray[j], inputArray[j + 1]);
            }
        }
    }
}

int main(){
    cout << "Enter number of values: ";
    int vals;
    cin >> vals;
    int valArray[vals];
    int *ptr;
    ptr = valArray;
    int userIn; int min; int max; float mean=0;
    for (int i =1; i<=vals; i++){
        cout << "Enter value " << i << ": " ;
        cin >> userIn;
        mean = mean + userIn;
        *(ptr+(i-1))=userIn;
    }
    mean = mean/vals;
    sort(valArray,vals);
    float median;
    if (vals % 2 == 0) {
        median = (valArray[vals/2 - 1] + valArray[vals/2]) / 2.0;
    } else {
        median = valArray[vals/2];
    }

    int mode = -1;
    int maxCount = 1;     
    int currentCount = 1;

    for (int i = 1; i < vals; i++) {
        if (valArray[i] == valArray[i - 1]) {
            currentCount++;
        } else {
            currentCount = 1;
        }

        if (currentCount > maxCount) {
            maxCount = currentCount;
            mode = valArray[i];
        }
    }

    bool meanPresent = false, medianPresent = false, modePresent = false;
    for (int i = 0; i < vals; i++) {
        if (valArray[i] == mean) meanPresent = true;
        if (valArray[i] == median) medianPresent = true;
        if (valArray[i] == mode) modePresent = true;
    }

    cout << "Mean: " << mean;
    if (meanPresent) {
        cout << " (present)" << endl;
    } else {
        cout << " (not present)" << endl;
    }

    cout << "Median: " << median;
    if (medianPresent) {
        cout << " (present)" << endl;
    } else {
        cout << " (not present)" << endl;
    }
    if (mode == -1) {
        cout << "Mode: None (not present)" << endl;
    } else {
        cout << "Mode: " << mode;
        if (modePresent) {
            cout << " (present)" << endl;
        } else {
            cout << " (not present)"<< endl;
        }
    }

    return 0;
}
    