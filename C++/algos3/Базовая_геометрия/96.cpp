#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double area = 0.0;
    for (int i = 0; i < n; i++) {
        area += points[i].x * points[(i + 1) % n].y;
        area -= points[i].y * points[(i + 1) % n].x;
    }
    cout << fixed << setprecision(5) << abs(area) / 2.0 << endl;
    return 0;
}
