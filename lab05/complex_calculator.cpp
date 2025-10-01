#ifndef COMPLEX_CALCULATOR
#define COMPLEX_CALCULATOR

/*
Write your solution here.
*/
#include <iostream>
using namespace std;
class Complex {
    private:
        double real ;
        double imag; 
    public:
        Complex (): real(0), imag(0) {} ;
        Complex (double r, double i) : real(r), imag(i) {} ; 
        Complex add (Complex c2) {
            Complex result;
            result.real = real + c2.real;
            result.imag = imag + c2.imag;
            return result;
        }
        Complex add (double d1) {
            Complex result;
            result.real = real + d1;
            result.imag = imag;
            return result;
        }
        Complex subtract (Complex c2) {
            Complex result;
            result.real = real - c2.real;
            result.imag = imag - c2.imag;
            return result;
        }
        Complex subtract (double d1) {
            Complex result;
            result.real = real - d1;
            result.imag = imag;
            return result;
        }
        Complex multiply (Complex c2) {
            Complex result;
            result.real = real * c2.real - imag * c2.imag;
            result.imag = real * c2.imag + imag * c2.real;
            return result;
        }
        Complex multiply (double d1) {
            Complex result;
            result.real = real * d1;
            result.imag = imag * d1;
            return result;
        }
        void show() {
            if (imag >= 0) {
                cout << real << " + " << imag << "i" << endl;
            } else {
                cout << real << " - " << -imag << "i" << endl;
            }
        }

};



int main(){
    double real, imag;
    cin>>real >>imag;
    Complex c1 = {real, imag};
    cin>>real >>imag;
    Complex c2 = {real, imag};
    double d1;
    cin>>d1;
    Complex result;
    //showing the numbers:
    cout<<"c1: "; c1.show();
    cout<<"c2: "; c2.show();
    cout<<"d1: "<<d1<<endl;
    // Check the opertions where both operands are complex result = c1.add(c2);
    result = c1.add(c2);
    cout<<"c1+c2: "; result.show();
    result = c1.subtract(c2);
    c1.subtract (c2);
    cout<<"c1-c2: "; result.show();
    result = c1.multiply(c2);
    c1.multiply (c2);
    cout<<"c1*c2: "; result.show();
    // Check the opertions where one operator is complex, other is double 
    result = c1.add(d1);
    cout<<"c1+d1: "; result.show();
    result = c1.subtract (d1);
    cout<<"c1-d1: "; result.show();
    result = c1.multiply (d1);
    cout << "c1*d1: "; result.show();
    return 0;
}
#endif  // COMPLEX_CALCULATOR
