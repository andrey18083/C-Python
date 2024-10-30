#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(char ch) {
    static const string vowels = "AEIOU";
    return vowels.find(ch) != string::npos;
}


int main() {
    int n, k;
    cin >> n >> k;
    string letters = "ABCDEFGHIJKLMNOPQRSTVWXYZU";
    sort(letters.begin(), letters.end());

    string current =letters.substr(0,n);
    string lper = letters.substr(letters.size() - n);

    do {
        int vowel_count = 0;
        for (char letter : current) {
            if (isVowel(letter)) {
                vowel_count++;
            }
        }
        if (vowel_count >= k) {
            cout << current << endl;
    
        }
    } 
    while (nes(current.begin(), current.end()) && current < lper);

    return 0;
}