#include <iostream>
using namespace std;

unsigned long int modulExponentiation(unsigned long int x, unsigned long int y, unsigned long int N)  {
    if (y == 0) return 1;
    unsigned long int z = modulExponentiation(x, y / 2, N);
    z = (z * z) % N;
    if (y % 2 == 0)
        return z;
    else
        return (x * z) % N;
}

int main() {
    unsigned long int base, exponent, modul;
    cin >> base;
    cin >> exponent;
    cin >> modul;
    cout << modulExponentiation(base % modul, exponent, modul) << endl;
    return 0;
}