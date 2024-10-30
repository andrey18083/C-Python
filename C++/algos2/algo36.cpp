#include <fstream>
#include <iostream>
#include <sstream>
#include <deque>
#include <vector>
#include <unordered_set>

std::string bfs(std::vector<std::unordered_set<int>>& lines, int M, int A, int B) {
    std::deque<std::pair<std::vector<int>, int>> current;
    std::unordered_set<int> founded;
    current.push_back({{A}, 0});
    founded.insert(A);

    while (!current.empty()) {
        auto [verts, prev_step] = current.front();
        current.pop_front();

        for (int vert : verts) {
            for (int el : lines[vert]) {
                if (founded.find(el) == founded.end()) {
                    current.push_back({{el}, prev_step + 1});
                    founded.insert(el);
                }
            }
        }

        if (founded.find(B) != founded.end()) {
            return std::to_string(prev_step);
        }
    }

    return "-1";
}

std::vector<std::unordered_set<int>> get_lines(int N, int M, std::deque<std::string>& d) {
    std::vector<std::unordered_set<int>> lines(N + 1);

    for (int i = 0; i < M; ++i) {
        std::istringstream iss(d.front());
        d.pop_front();
        std::vector<int> line;
        int num;
        iss >> num;
        while (iss >> num) {
            line.push_back(num);
        }
        while (!line.empty()) {
            int vert = line.back();
            line.pop_back();
            for (int l : line) {
                lines[vert].insert(l);
                lines[l].insert(vert);
            }
        }
    }

    return lines;
}

int main() {
    std::ifstream f_in("input.txt");
    std::ofstream f_out("output.txt");

    int N, M;
    f_in >> N >> M;
    std::deque<std::string> d;
    std::string line;

    std::getline(f_in, line); // Read and discard the newline after M
    for (int i = 0; i < N + M + 1; ++i) {
        std::getline(f_in, line);
        d.push_back(line);
    }

    std::vector<std::unordered_set<int>> lines = get_lines(N, M, d);
    int A, B;
    std::istringstream iss(d.front());
    iss >> A >> B;

    f_out << bfs(lines, M, A, B);

    f_in.close();
    f_out.close();

    return 0;
}