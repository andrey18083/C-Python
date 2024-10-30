#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

vector<int> lzwCompress(const string &S) {
    unordered_map<string, int> dic;
    for (int i = 0; i < 128; ++i) {
        dic[string(1, char(i))] = i;
    }
    string curr = "";
    vector<int> otv;
    int cd = 128;
    for (char c : S) {
        string b = curr + c;
        if (dic.find(b) != dic.end()) {
            curr = b;
        } else {
            otv.push_back(dic[curr]);
            dic[b] = cd++;
            curr = string(1, c);
        }
    }
    if (!curr.empty()) {
        otv.push_back(dic[curr]);
    }
    return otv;
}

int main() {
    string S;
    getline(cin, S);
    vector<int> com = lzwCompress(S);
    cout << com.size() << endl;
    for (int cd : com) {
        cout << cd << " ";
    }
    cout << endl;
    return 0;
}
