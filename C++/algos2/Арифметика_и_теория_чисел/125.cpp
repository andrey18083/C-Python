#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    bool otv;
    cin >> b;
    otv = false;
    for (int q = 2; q <= trunc(sqrt(b)) + 1; q++) {
        if (b % q == 0) {
            a = b / q;
            cout << a << ' ' << b - a;
            otv = true;
            break;
        }
    }
    if (!otv) {
        cout << 1 << ' ' << b - 1;
    }
    return 0;
}