#include <iostream>
using namespace std;

int main() {
    double a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;

    double c = x2 - x1;
    double d = y2 - y1;

    double cross_product = (a - x1) * d - (b - y1) * c;
    if (cross_product != 0) {
        cout << "NO" << endl;
        return 0;
    }

    double dot_product = (a - x1) * c + (b - y1) * d;
    if (dot_product < 0) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    return 0;
}
