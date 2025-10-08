#include <iostream>
using namespace std;

double area(double radius) {
    const double PI = 3.141592653589793;
    return PI * radius * radius;
}

double area(double width, double height) {
    return width * height;
}

int main() {
    double r;
    cout << "Enter radius: ";
    cin >> r;
    cout << "Area of circle = " << area(r) << endl;

    double w, h;
    cout << "Enter width and height: ";
    cin >> w >> h;
    cout << "Area of rectangle = " << area(w, h) << endl;

    return 0;
}
