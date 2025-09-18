#include <iostream> 
#include <cstring>
using namespace std;

int comp(char *a,char *b){
    while (*a != '\0' && *b != '\0') {
        if (*a != *b) {
            return *a - *b;  
        }
        a++;
        b++;
    }
    
    return *a - *b;
}
void sort(char* str_array[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (comp(str_array[j], str_array[j + 1]) > 0) {
                char* temp = str_array[j];
                str_array[j] = str_array[j + 1];
                str_array[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    cin.ignore();
    char str_arr[n][100];
    char* str_array[n];
    for (int x = 0; x < n; x++) {
        cin.getline(str_arr[x], 100);
        str_array[x] = &str_arr[x][0];
    }
    sort(str_array, n);
    cout << "Sorted: " << endl;
    for (int i =0; i<n ; i++) {
        cout << str_array[i] << endl;
    }
    return 0;
}
