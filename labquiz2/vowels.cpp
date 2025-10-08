#include <iostream>
#include <cstring>
using namespace std;

bool is_vowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int count_vowels(char *str) {
    int count = 0;
    char *p = str;
    while (*p != '\0') {
        if (is_vowel(*p)) {
            count++;
        }
        p++;
    }
    return count;
}

int main() {
    const int MAX = 1000;
    char str[MAX];
    cout << "Enter a string: ";
    cin.getline(str, MAX);

    int v = count_vowels(str);
    cout << "Number of vowels: " << v << endl;
    return 0;
}
