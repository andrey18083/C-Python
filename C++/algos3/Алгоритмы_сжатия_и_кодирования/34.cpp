#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

string lzwdecode(const vector<int>& S) {
    unordered_map<int, string> dic;
    for (int i = 0; i < 128; ++i) {
        dic[i] = string(1, (char)i);
    }

    int ncd = 128;
    string otv;
    int pcd = S[0];
    otv += dic[pcd];

    for (size_t i = 1; i < S.size(); ++i) {
        int cur = S[i];

        string e;
        if (dic.find(cur) != dic.end()) {
            e = dic[cur];
        } else {
            e = dic[pcd] + dic[pcd][0];
        } 

        otv += e;

        if (ncd < 1048576) {
            dic[ncd++] = dic[pcd] + e[0];
        }

        pcd = cur; 
    }

    return otv;
}

int main() {
    int S;
    cin >> S; 
    vector<int> codes(S);
    for (int i = 0; i < S; ++i) {
        cin >> codes[i]; 
    }
    try {
        string b = lzwdecode(codes);
        cout << b << endl; 
    } catch (const std::exception& e) {
        cerr << e.what() << endl; 
    }
    return 0;
}
