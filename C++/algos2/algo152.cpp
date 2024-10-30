#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> strength(N);
    for (int i = 0; i < N; ++i) {
        cin >> strength[i];
    }

    vector<int> jumps(N, -1); // Для хранения количества прыжков до выхода за край
    vector<int> lastLanding(N); // Для хранения номера последней лунки перед вылетом за край

    for (int i = 0; i < M; ++i) {
        int type, a, b;
        cin >> type >> a;
        
        if (type == 0) {
            cin >> b;
            strength[a - 1] = b;
        } else {
            int jumpsCount = 0;
            int current = a - 1;
            while (current >= 0 && current < N) {
                if (jumps[current] != -1) { // Если уже посчитали прыжки для этой лунки
                    jumpsCount += jumps[current];
                    current = lastLanding[current];
                } else {
                    lastLanding[a - 1] = current;
                    jumps[a - 1] = jumpsCount + 1;
                    current += strength[current];
                    jumpsCount++;
                }
            }
            cout << lastLanding[a - 1] + 1 << " " << jumps[a - 1] << endl;
        }
    }

    return 0;
}