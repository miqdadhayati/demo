#include <iostream>
using namespace std;

int count_even(int *arr, int size) {
    int *p = arr ; 
    int count = 0; 
    for (int i = 0; i < size; i++){
        int temp = 0;
        temp = *p ;
        cout << temp << endl;
        if (temp%2 == 0) {
            count++;
        }
        p++; }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ev = count_even(arr, n);
    cout << "Number of even elements: " << ev << endl;

    delete[] arr;
    return 0;
}
