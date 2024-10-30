#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> cpf(const string& s) {
    int n = s.size();
    vector<int> pr(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && s[i] != s[j]) {
            j = pr[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        pr[i] = j;
    }
    return pr;
}

int main() {
    string i;
    cin >> i;
    vector<int> pa = cpf(i);
    for (const auto& v : pa) {
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}