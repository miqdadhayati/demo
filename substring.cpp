#include <iostream>
#include <string>
using namespace std;

int longest(string s) {
    int maxLen = 0;
    for (int i = 0; i < s.size(); ++i) {
        bool used[256] ; 
        int currentLen = 0;
        for (int j = i; j < s.size(); ++j) {
            if (used[(unsigned char)s[j]]) break;
            used[(unsigned char)s[j]] = true;
            ++currentLen;
        }
        if (currentLen > maxLen) maxLen = currentLen;
    }
    return maxLen;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << "longest"
         << longest(s) << endl;
    return 0;
}