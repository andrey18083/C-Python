#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>

using namespace std;

struct Village {
    int x, y;
};

double distance(const Village &a, const Village &b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double totalDistance(const vector<Village> &villages, const vector<int> &path) {
    double total = distance(villages[path.back()], villages[path[0]]);
    for (size_t i = 0; i < path.size() - 1; ++i) {
        total += distance(villages[path[i]], villages[path[i + 1]]);
    }
    return total;
}

void simulatedAnnealing(vector<Village> &villages, int iterations, double startTemp, double endTemp) {
    int n = villages.size();
    vector<int> currentPath(n);
    iota(currentPath.begin(), currentPath.end(), 0);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    vector<int> bestPath = currentPath;
    double bestDistance = totalDistance(villages, currentPath);

    for (double temp = startTemp; temp > endTemp; temp *= 0.99) {
        for (int i = 0; i < iterations; ++i) {
            int idx1 = rand() % (n - 1) + 1; 
            int idx2 = rand() % (n - 1) + 1; 
            if (idx1 == idx2) continue;

            swap(currentPath[idx1], currentPath[idx2]);
            double newDistance = totalDistance(villages, currentPath);
            double delta = newDistance - bestDistance;

            if (delta < 0 || exp(-delta / temp) > dis(gen)) {
                if (newDistance < bestDistance) {
                    bestDistance = newDistance;
                    bestPath = currentPath;
                }
            } else {
                swap(currentPath[idx1], currentPath[idx2]);
            }
        }
    }

    cout << "1";
    for (int i = 1; i < bestPath.size(); ++i) {
        cout << " " << bestPath[i] + 1; 
    }
    cout << " 1" << endl; 
}

int main() {
    int N;
    cin >> N;
    vector<Village> villages(N);

    for (int i = 0; i < N; ++i) {
        cin >> villages[i].x >> villages[i].y;
    }

    int iterations = 1000;
    double startTemp = 10000;
    double endTemp = 0.1;

    simulatedAnnealing(villages, iterations, startTemp, endTemp);

    return 0;
}
