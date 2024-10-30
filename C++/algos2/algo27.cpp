#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct yablochki {
    int x, y, z, r;
    bool isfl;
};

bool isColliding(const yablochki& a, const yablochki& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dz = a.z - b.z;
    int dl = dx * dx + dy * dy + dz * dz;
    int sumr = (a.r + b.r) * (a.r + b.r);
    return dl <= sumr;
}

void dfs(vector<yablochki>& apples, int ind) {
    apples[ind].isfl = true;
    for (int i = 0; i < apples.size(); ++i) {
        if (i != ind && !apples[i].isfl && isColliding(apples[ind], apples[i])) {
            dfs(apples, i);
        }
    }
}

int main() {
    int N;
    cin >> N;
    vector<yablochki> apples(N);
    for (int i = 0; i < N; ++i) {
        cin >> apples[i].x >> apples[i].y >> apples[i].z >> apples[i].r;
        apples[i].isfl = false;
    }
    dfs(apples, 0);
    vector<int> fap;
    for (int i = 0; i < N; ++i) {
        if (apples[i].isfl) {
            fap.push_back(i + 1);
        }
    }
    cout << fap.size() << endl;
    for (int apple : fap) {
        cout << apple << " ";
    }
    cout << endl;
    return 0;
}