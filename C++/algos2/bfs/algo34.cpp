#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> cord_var = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2},
                                    {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

set<pair<int, int>> gen_neighbors(pair<int, int> cord, int max_n, int max_m, set<pair<int, int>>& founded) {
    vector<pair<int, int>> res;
    for (auto cord_v : cord_var) {
        res.push_back({cord.first + cord_v.first, cord.second + cord_v.second});
    }

    set<pair<int, int>> result;
    for (auto el : res) {
        if (el.first >= 1 && el.first <= max_n && el.second >= 1 && el.second <= max_m && founded.find(el) == founded.end()) {
            result.insert(el);
            founded.insert(el);
        }
    }
    return result;
}

int bfs(pair<int, int> corm_cord, int max_n, int max_m, vector<pair<int, int>>& blohi_cords, vector<vector<int>>& pole) {
    pole[corm_cord.first][corm_cord.second] = 0;
    queue<pair<int, pair<int, int>>> q;
    q.push({0, corm_cord});
    int full_way = 0;
    int count_of_free_ways = max_n * max_m - 1;
    set<pair<int, int>> founded;
    while (count_of_free_ways != 0) {
        auto [dist, el] = q.front();
        q.pop();
        for (auto neighbor : gen_neighbors(el, max_n, max_m, founded)) {
            q.push({dist + 1, neighbor});

            if (pole[neighbor.first][neighbor.second] == -1) {
                pole[neighbor.first][neighbor.second] = dist + 1;
                count_of_free_ways--;
            }
        }

        if (q.empty()) {
            break;
        }
    }

    full_way = 0;
    for (auto bloha_cord : blohi_cords) {
        if (pole[bloha_cord.first][bloha_cord.second] == -1) {
            return -1;
        }
        full_way += pole[bloha_cord.first][bloha_cord.second];
    }

    return full_way;
}

vector<pair<int, int>> get_blohi(int Q, queue<string>& d) {
    vector<pair<int, int>> blohi;
    for (int i = 0; i < Q; i++) {
        string line = d.front();
        d.pop();
        int x, y;
        sscanf(line.c_str(), "%d %d", &x, &y);
        blohi.push_back({x, y});
    }
    return blohi;
}

int main() {
    ifstream f_in("input.txt");
    queue<string> d;
    string line;
    while (getline(f_in, line)) {
        d.push(line);
    }

    int N, M, S, T, Q;
    sscanf(d.front().c_str(), "%d %d %d %d %d", &N, &M, &S, &T, &Q);
    d.pop();

    auto blohi = get_blohi(Q, d);
    
    vector<vector<int>> pole(N + 1, vector<int>(M + 1, -1));

    cout << bfs({S, T}, N, M, blohi, pole) << endl;

    return 0;
}