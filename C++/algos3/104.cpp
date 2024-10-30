#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double X, Y;
    cin >> X >> Y;
    
    double x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    double mx = (x1 + x2 + x3 + x4) / 4;
    double my = (y1 + y2 + y3 + y4) / 4;
    
    double scaleX = (x2 - x1) / X;
    double scaleY = (y3 - y1) / Y;
    
    double fixedPointX = mx / (scaleX / X);
    double fixedPointY = my / (scaleY / Y);
    
    cout << fixed << setprecision(3) << fixedPointX << " " << fixedPointY << endl;
    
    return 0;
}
