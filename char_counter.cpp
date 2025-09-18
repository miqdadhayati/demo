#include <iostream> 

using namespace std;
int main() {
    int maxlen = 670; 
    char str[maxlen];     
    char ch;                   
    int count = 0;             
    cout << "Enter a string: ";
    cin.getline(str, maxlen); 

    cout << "Enter a character to search for: ";
    cin >> ch;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == ch) {
            count++;
        }
    }
    cout << "Number of occurences of '" << ch << "': " << count  << endl;
    return 0;
}