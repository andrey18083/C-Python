#include <iostream>
#include <vector>
#include <string>

using namespace std;

const long long md = 1e9 + 9;

void hf(const vector<int>& dm, long long a, vector<long long>& b, vector<long long>& dg) {
    b.push_back(0);
    dg.push_back(1);
    for (size_t i = 0; i < dm.size(); ++i) {
        b.push_back((b.back() * a + dm[i]) % md);
        dg.push_back((dg.back() * a) % md);
    }
}

int ck(int f1, int f2, int k, const vector<long long>& b, const vector<long long>& dg) {
    long long first = (b[f1 + k - 1] - b[f1 - 1] * dg[k] % md + md) % md;
    long long second = (b[f2 + k - 1] - b[f2 - 1] * dg[k] % md + md) % md;
    return (first == second) ? 1 : 0;
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> dm(n);
    for (int i = 0; i < n; ++i) {
        dm[i] = s[i];
    }
    long long a = 27;
    vector<long long> dg, b;
    hf(dm, a, b, dg);
    for (int k = 1; k <= n; ++k) {
        bool o = true;
        for (int i = 1; i <= n + 1 - k; i += k) {
            if (ck(1, i, k, b, dg) == 0) {
                o = false;
                break;
            }
        }
        if (ck(1, k * (n / k) + 1, n % k, b, dg) == 0) {
            o = false;
        }
        if (o) {
            cout << k << endl;
            return 0; 
        }
    }
    return 0;
}