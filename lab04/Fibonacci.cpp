#include <iostream>
using namespace std;
long fib(int n) {
    static long callCount = 0; 
    callCount++;
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}
int main() {
    int n;
    cout << "Enter a non-negative integer n to find the nth of Fibonacci number: ";
    cin >> n;
    if (n < 0) {
        cout << "Please enter a non-negative integer." << endl;
        return 1;
    }
    long result = fib(n);
    cout << "fib("<< n <<") = " << result << endl;
    return 0;
}
