#include <iostream>
#include <stack>
#include <vector>
#include <string>

bool chuchu(std::string lineyka) {
    std::stack<char> hihihaha;
    int i = 0;
    while (i < lineyka.size()) {
        if (lineyka[i] == '(' || lineyka[i] == '[') {
            hihihaha.push(lineyka[i]);
        } else if (hihihaha.empty()) {
            return false;
        } else {
            if (lineyka[i] == ')') {
                if (hihihaha.top() == '(') {
                    hihihaha.pop();
                } else {
                    return false;
                }
            } else {
                if (hihihaha.top() == '[') {
                    hihihaha.pop();
                } else {
                    return false;
                }
            }
        }
        ++i;
    }
    return hihihaha.empty();
}

void Search(int choto, std::string lineyka, std::vector<std::string> hihihaha) {
    if (choto == 0) {
        if (chuchu(lineyka)) {
            std::cout << lineyka << "\n";
        }
        return;
    }
    if (hihihaha.size() > choto) {
        return;
    }
    hihihaha.emplace_back("(");
    Search(choto - 1, lineyka + "(", hihihaha);
    hihihaha.pop_back();
    hihihaha.emplace_back("[");
    Search(choto - 1, lineyka + "[", hihihaha);
    hihihaha.pop_back();
    if (!hihihaha.empty()) {
        if (hihihaha.back() == "[") {
            hihihaha.pop_back();
            Search(choto - 1, lineyka + "]", hihihaha);
        } else if (hihihaha.back() == "(") {
            hihihaha.pop_back();
            Search(choto - 1, lineyka + ")", hihihaha);
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    if (n % 2 == 1) {
        return 0;
    }
    Search(n, "", {});
    return 0;
}