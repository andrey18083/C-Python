#include <iostream>
#include <vector>

int n,k;
std::vector<std::string> otv;

void gbn(std::string arr, int oc, int cs) {
    if (arr.size() == n) {
        if (oc == k) {
            otv.push_back(arr);
        }
        return;
    }
    if (oc < k){
        gbn(arr + "1", oc + 1, cs + 1);
    }
    if (n - cs >= k - oc){
        gbn(arr + "0", oc, cs + 1);
    }
}

int main() {
    std::cin >> n >> k;
    gbn("", 0, 0);
    for (int i = otv.size()-1; i>= 0; --i){
        std::cout << otv[i] << '\n';
    }
}