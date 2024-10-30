#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
#include <iterator>

using ull = unsigned long long;
std::vector<std::vector<unsigned long long>> mxx;

int main() {
    int n = 2147483647; 
    std::cin >> n;
    mxx.resize(44, std::vector<ull>(10));
    std::fill(mxx[1].begin() + 1, mxx[1].end(), 1);
    for (int i = 2; i < mxx.size(); ++i) {
        for (int j = 1; j < mxx[i].size(); ++j) {
            mxx[i][j] = std::accumulate(mxx[i - 1].begin() + j, mxx[i - 1].end(), 0ull);
        }
    }
    std::vector<int> vr;
    ull np{}, nc{}, rk = 1, fd = 1;
    while (rk) {
        for (int i = rk; i < mxx.size(); ++i) {
            for (int j = fd; j < mxx[i].size(); ++j) {
                np = nc;
                nc += mxx[i][j];
                if (np < n && nc >= n) {
                    nc -= mxx[i][j];
                    vr.push_back(j);
                    rk = i - 1;
                    fd = j;
                    goto cont;
                }
            }
        }
    cont: {}
    }
    std::copy(vr.begin(), vr.end(), std::ostream_iterator<int>(std::cout, ""));
    std::cout << "\n";
    return 0;
}
