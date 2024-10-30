#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Node {
    int eC;
    int vault_tec;
};

vector<Node> derevo;

int findPowerOfTwo(int n) {
    return log2(n);
}

void build(const vector<int>& arr, int a, int x, int y) {
    if (x == y) {
        derevo[a].eC = abs(arr[y] + 1) % 2;
        derevo[a].vault_tec = arr[y];
    } else {
        int M = (x + y) / 2;
        build(arr, a * 2 + 1, M + 1, y);
        build(arr, a * 2, x, M);
        derevo[a].eC = derevo[a * 2].eC + derevo[a * 2 + 1].eC;
    }
}

void update(int a, int la, int ra, int q, int p) {
    if (la == ra) {
        derevo[a].eC = abs(p + 1) % 2;
        derevo[a].vault_tec = p;
    } else {
        int mid = (la + ra) / 2;
        if (q > mid) {
            update(a * 2 + 1, mid + 1, ra, q, p);
        } else {
            update(a * 2, la, mid, q, p);
        }
        derevo[a].eC = derevo[a * 2].eC + derevo[a * 2 + 1].eC;
    }
}

int query(int a, int la, int ra, int l, int r) {
    if (l > r) {
        return 0;
    }
    if (l == la && r == ra) {
        return derevo[a].eC;
    }
    int mid = (la + ra) / 2;
    return query(a * 2, la, mid, l, min(r, mid)) + query(a * 2 + 1, mid + 1, ra, max(l, mid + 1), r);
}

int search(int a, int la, int ra, int k) {
    if (k > derevo[a].eC) {
        return -1;
    }
    if (la == ra) {
        return la;
    }
    int mid = (la + ra) / 2;
    if (derevo[a * 2].eC < k) {
        return search(a * 2 + 1, mid + 1, ra, k - derevo[a * 2].eC);
    } else {
        return search(a * 2, la, mid, k);
    }
}

int main(){
    int n;
    cin >> n;
    derevo.resize(4 * n);
    vector<int> arr(n);
    for (int q = 0; q < n; ++q) {
        cin >> arr[q];
    }
    build(arr, 1, 0, n - 1);
    int q;
    cin >> q;
    for (int q = 0; q < q; ++q) {
        int cmd;
        cin >> cmd;
        if (cmd == 2) {
            int pos, p;
            cin >> pos >> p;
            arr[pos] = p;
            update(1, 0, n - 1, pos, p);
        } else if (cmd == 1) {
            int pos;
            cin >> pos;
            int result = search(1, 0, n - 1, pos);
            result == -1 ? cout << "NONE\n" : cout << arr[result] << "\n";
        }
    }
    return 0;
}