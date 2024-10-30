#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> zf(const std::string& str) {
    int n = str.size();
    std::vector<int> z(n, 0);
    for (int lf = 0, rg = 0, i = 1; i < n; ++i) {
        if (i <= rg) {
            z[i] = std::min(rg - i + 1, z[i - lf]);
        }
        while (i + z[i] < n && str[z[i]] == str[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > rg) {
         lf = i;
            rg = i + z[i] - 1;
        }
    }
    return z;
}

int main() {
    std::string pat, tx;
    std::cin >> pat >> tx;

    std::string revpat = pat;
    std::string revvtx = tx;
    std::reverse(revpat.begin(), revpat.end());
    std::reverse(revvtx.begin(), revvtx.end());

    std::vector<size_t> otv;
    std::string cb = pat + "@" + tx;
    std::string rebcb = revpat + "@" + revvtx;
    std::vector<int> a = zf(cb);
    std::vector<int> b = zf(rebcb);
    for (int i = pat.size() + 1; i <= cb.size() - pat.size(); ++i) {
        if (a[i] >= pat.size() - 1 || 
            a[i] + b[b.size() - i + 1] == pat.size() - 1) {
            otv.push_back(i - pat.size());
        }
    }
    std::cout << otv.size() << "\n";
    for (const auto& pos : otv) {
        std::cout << pos << " ";
    }
    return 0;
}