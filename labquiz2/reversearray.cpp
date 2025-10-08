#include <iostream>
using namespace std;

void reverse_arr(int *arr, int size){
    int* p  = arr;
    int* ptr = new int[size] ;
    int* ptr_temp = ptr + size - 1; 
    // ptr here signals ptr_temp about the new reversed array so pointer points towards the new array
    for (int i =0 ; i < size; i++){
        *ptr_temp = *p;
        ptr_temp--;
        p++;
    }
    // putting the reversed array back to orignal array
    p = &arr[0];
    for (int i = 0; i<size; i++){
        *p = ptr[i];
        p++;
    }
    delete[] ptr;
    
}
// ALTERNATIVE METHOD EASY METHOD:

// void reverse_arr(int *arr, int size) {
//     int *left = arr;           // start pointer
//     int *right = arr + size - 1; // end pointer

//     while (left < right) {
//         int temp = *left;
//         *left = *right;
//         *right = temp;

//         left++;   // move forward
//         right--;  // move backward
//     }
// }

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    reverse_arr(arr, n);

    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;
    return 0;
}
