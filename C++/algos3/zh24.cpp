#include <iostream>

using namespace std;

string determine(int xA, int yA, int xB, int yB, int xC, int yC) {
    int ABx = xB - xA;
    int ABy = yB - yA;

    int ACx = xC - xA;
    int ACy = yC - yA;

    int cross = ABx * ACy - ABy * ACx;

    if (cross > 0) {
        return "LEFT";
    } else {
        return "RIGHT";
    }
}

int main() {
    int xA, yA, xB, yB, xC, yC;

    cin >> xA >> yA;
    cin >> xB >> yB;
    cin >> xC >> yC;

    cout << determine(xA, yA, xB, yB, xC, yC);
}