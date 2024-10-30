#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

const int MOD = 1000000007;

struct AhoCorasick {
    struct Node {
        int next[256];
        int fail;
        bool output;

        Node() : fail(0), output(false) {
            fill(begin(next), end(next), -1);
        }
    };

    vector<Node> nodes;

    AhoCorasick() {
        nodes.emplace_back();
    }

    void addString(const string &s) {
        int current = 0;
        for (char c : s) {
            int index = (unsigned char)c;
            if (nodes[current].next[index] == -1) {
                nodes[current].next[index] = nodes.size();
                nodes.emplace_back();
            }
            current = nodes[current].next[index];
        }
        nodes[current].output = true;
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < 256; ++i) {
            if (nodes[0].next[i] != -1) {
                nodes[nodes[0].next[i]].fail = 0;
                q.push(nodes[0].next[i]);
            }
            else {
                nodes[0].next[i] = 0;
            }
        }

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            for (int i = 0; i < 256; ++i) {
                if (nodes[current].next[i] != -1) {
                    int failState = nodes[current].fail;
                    while (nodes[failState].next[i] == -1) {
                        failState = nodes[failState].fail;
                    }
                    nodes[nodes[current].next[i]].fail = nodes[failState].next[i];
                    nodes[nodes[current].next[i]].output |= nodes[nodes[failState].next[i]].output;
                    q.push(nodes[current].next[i]);
                }
            }
        }
    }
};

long long countValidStrings(int n, int m, const string &alphabet, const vector<string> &forbidden) {
    AhoCorasick ac;
    for (const auto &word : forbidden) {
        ac.addString(word);
    }
    ac.build();

    int numStates = ac.nodes.size();
    vector<vector<long long>> dp(m + 1, vector<long long>(numStates, 0));
    
    dp[0][0] = 1;

    for (int length = 0; length < m; ++length) {
        for (int state = 0; state < numStates; ++state) {
            for (char c : alphabet) {
                int nextState = state;
                while (ac.nodes[nextState].next[(unsigned char)c] == -1) {
                    nextState = ac.nodes[nextState].fail;
                }
                nextState = ac.nodes[nextState].next[(unsigned char)c];

                if (!ac.nodes[nextState].output) {
                    dp[length + 1][nextState] = (dp[length + 1][nextState] + dp[length][state]) % MOD;
                }
            }
        }
    }

    long long result = 0;
    for (int state = 0; state < numStates; ++state) {
        result = (result + dp[m][state]) % MOD;
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p;
    cin >> n >> m >> p;
    string alphabet;
    cin >> alphabet;

    vector<string> forbidden(p);
    for (int i = 0; i < p; ++i) {
        cin >> forbidden[i];
    }

    cout << countValidStrings(n, m, alphabet, forbidden) << '\n';

    return 0;
}
