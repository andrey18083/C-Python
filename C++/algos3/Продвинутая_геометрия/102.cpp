#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point &p) const {
        return (x == p.x) ? (y < p.y) : (x < p.x);
    }
};

int crs(const Point &O, const Point &A, const Point &B) {
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

double perimetr(const vector<Point> &tc) {
    double p = 0;
    for (size_t i = 0; i < tc.size(); i++) {
        size_t next = (i + 1) % tc.size();
        p += sqrt(pow(tc[next].x - tc[i].x, 2) + pow(tc[next].y - tc[i].y, 2));
    }
    return p;
}

double ploshad(const vector<Point> &tc) {
    double a = 0;
    for (size_t i = 0; i < tc.size(); i++) {
        size_t next = (i + 1) % tc.size();
        a += tc[i].x * tc[next].y - tc[next].x * tc[i].y;
    }
    return abs(a) / 2.0;
}

vector<Point> qwer(vector<Point> &points) {
    sort(points.begin(), points.end());
    vector<Point> tc;
    for (const auto &p : points) {
        while (tc.size() >= 2 && crs(tc[tc.size()-2], tc[tc.size()-1], p) <= 0)
            tc.pop_back();
        tc.push_back(p);
    }
    size_t t = tc.size() + 1;
    for (int i = points.size()-1; i >= 0; i--) {
        const auto &p = points[i];
        while (tc.size() >= t && crs(tc[tc.size()-2], tc[tc.size()-1], p) <= 0)
            tc.pop_back();
        tc.push_back(p);
    }
    tc.pop_back();
    return tc;
}

int main() {
    int N;
    cin >> N;
    vector<Point> points(N);

    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    vector<Point> tc = qwer(points);
    double p = perimetr(tc);
    double a = ploshad(tc);
    cout.precision(10);
    cout << fixed << p << endl;
    cout << fixed << a << endl;
    return 0;
}
