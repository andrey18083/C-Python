#include <iostream>

using namespace std;

int main() {

    int x1, y1;
    int x2, y2;
    int x3, y3;

    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    
    int x4 = x2 + x3 - x1;
    int y4 = y2 + y3 - y1;


    cout << x4 << " " << y4;
    return 0;
} 