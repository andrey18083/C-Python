#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;
    double x, y, D, Dx, Dy;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    D = static_cast<double>(-(y1 - y2) * (x4 - x3) + (y3 - y4) * (x2 - x1));
    Dx = static_cast<double>((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) * (x2 - x1));
    Dy = static_cast<double>((y1 - y2) * (x3 * y4 - x4 * y3) - (y3 - y4) * (x1 * y2 - x2 * y1));

    if (D != 0) {
        x = Dx / D;
        y = Dy / D;
        printf("1 %.6lf %.6lf\n", x, y);
    } else if (Dx == 0 && Dy == 0) {
        printf("2\n");
    } else {
        printf("0\n");
    }

    return 0;
}
