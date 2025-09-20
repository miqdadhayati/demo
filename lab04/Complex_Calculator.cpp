#include <iostream>
using namespace std;

void show(double complex[2]) {
    cout << complex[0] << " + " << complex[1] << "i" << endl;
}
void add(double complex1[2], double complex2[]) {
    complex1[0] = complex1[0] + complex2[0];
    complex1[1] = complex1[1] + complex2[1];
}
void add(double complex[2], double realNum) {
    complex[0] = complex[0] + realNum;
}
void subtract(double complex1[2], double complex2[2]) {
    complex1[0] = complex1[0] - complex2[0];
    complex1[1] = complex1[1] - complex2[1];
}
void subtract(double complex[2], double realNum) {
    complex[0] = complex[0] - realNum;
}
void multiply(double complex1[2], double complex2[2]) {
    double a = complex1[0];
    double b = complex1[1];
    double c = complex2[0];
    double d = complex2[1];
    complex1[0] = a * c - b * d;
    complex1[1] = a * d + b * c;
}
void multiply(double complex[2], double realNum) {
    complex[0] = complex[0] * realNum;
    complex[1] = complex[1] * realNum;
}
int main() {
    double c1[2], c2[2];
    cout << "Enter c1: ";
    cin >> c1[0] >> c1[1];
    cout << "Enter c2: ";
    cin >> c2[0] >> c2[1];
    cout << "Enter d1: ";
    double d1;
    cin >> d1;

    double temp[2];
    temp[0] = c1[0]; temp[1] = c1[1];
    add(temp, c2);
    cout << "c1+c2: ";
    show(temp);
    temp[0] = c1[0]; temp[1] = c1[1];
    subtract(temp, c2);
    cout << "c1-c2: ";
    show(temp);
    temp[0] = c1[0]; temp[1] = c1[1];
    multiply(temp, c2);
    cout << "c1*c2: ";
    show(temp);
    temp[0] = c1[0]; temp[1] = c1[1];
    add(temp, d1);
    cout << "c1+d1: ";
    show(temp);
    temp[0] = c1[0]; temp[1] = c1[1];
    subtract(temp, d1);
    cout << "c1-d1: ";
    show(temp);
    temp[0] = c1[0]; temp[1] = c1[1];
    multiply(temp, d1);
    cout << "c1*d1: ";
    show(temp);
    return 0;
}