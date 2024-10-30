#include <iostream>
#include <vector>

struct Man {
    int Weight;
    int Parent;
    Man(int weight = 0, int parent = 0) : Weight(weight), Parent(parent) {}
};

int main() {
    int n;
    std::cin >> n;
    std::vector<Man> snowmen(n + 1);
    snowmen[0] = Man(0, 0); 
    long long totalWeight = 0;
    for (int i = 1; i <= n; ++i) {
        int t, m;
        std::cin >> t >> m;
        if (m > 0) {
            snowmen[i] = Man(snowmen[t].Weight + m, t);
        } else {
            snowmen[i] = snowmen[snowmen[t].Parent];
        }
        totalWeight += snowmen[i].Weight;
    }
    std::cout << totalWeight << std::endl;
    return 0;
}
