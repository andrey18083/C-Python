#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cmath>

int Count(const std::vector<std::vector<bool>>& graph, const std::vector<int>& ind){
    int otv = 0;
    for (const auto& i: ind){
        bool prov = true;
        for (const auto& j : ind){
            if (i != j && !graph[i][j]){
                prov = false;
                break;
            }
        }
        if (prov) {
            ++otv;
        }
    }
    return otv;
}

double rnd(){
    return double(rand()) / RAND_MAX;
}

int main(){
    int v, s, e;
    std::cin >> v >> s >> e;
    std::vector<std::vector<bool>> graph(v+1, std::vector<bool>(v+1, false));
    for (int k = 0; k<e; ++k){
        int x,y;
        std::cin >> x >> y;
        graph[x][y] = true;
        graph[y][x] = true;
    }
    std::vector<int> qq(s);
    std::iota(qq.begin(), qq.end(),1);
    if (s > v){
        std::cout << "NO";
        return 0;
    }
    if (v == s) {
        if (Count(graph, qq) != s){
            std::cout << "NO";
        } else {
            std::cout << "YES";
        }
        return 0;
    }
    std::vector<int> pp(v - s);
    std::iota(pp.begin(), pp.end(), s+1);
    std::random_device rd;
    std::mt19937 rng(rd());
    int cur = Count(graph, qq);
    double t = 1;
    for (int i = 0; i < 1e5; ++i) {
        if (cur == s){
            break;
        }
        t *= 0.98;
        int p1 = rng()%qq.size();
        int p2 = rng()%pp.size();
        std::swap(qq[p1], pp[p2]);
        int val = Count(graph, qq);
        if (val > cur || rnd() < exp((val - cur)/t)){
            cur = val;
        } else {
            std::swap(qq[p1], pp[p2]);
        }
    }
    if (cur == s) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
}