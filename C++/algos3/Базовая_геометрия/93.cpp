#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    double a, b, c, d, e;
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    c = (-(y1 - y2) * (x4 - x3) + (y3 - y4) * (x2 - x1));
    d = ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1));
    e = ((y1 - y2) * (x3 * y4 - x4 * y3) - (y3 - y4) * (x1 * y2 - x2 * y1));

    if (c != 0) {
        a = d / c;
        b = e / c;
        cout << "1 " << a << " " << b << endl;
    } else if (d == 0 && e == 0) {
        cout << "2" << endl;
    } else {
        cout << "0" << endl;
    }
    return 0;
}
