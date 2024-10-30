#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class AhoCorasick {
private:
    struct Node {
        vector<int> children;
        int fail;
        vector<int> output;
        
        Node(int alphabet_size) : fail(-1), children(alphabet_size, -1) {}
    };

    vector<Node> trie;
    const int ALPHABET_SIZE = 26;

public:
    AhoCorasick() {
        trie.push_back(Node(ALPHABET_SIZE)); 
    }

    void addPattern(const string &pattern, int index) {
        int node = 0;
        for (char c : pattern) {
            int idx = c - 'a';
            if (trie[node].children[idx] == -1) {
                trie[node].children[idx] = trie.size();
                trie.push_back(Node(ALPHABET_SIZE));
            }
            node = trie[node].children[idx];
        }
        trie[node].output.push_back(index);
    }

    void build() {
        queue<int> q;
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (trie[0].children[i] != -1) {
                q.push(trie[0].children[i]);
                trie[trie[0].children[i]].fail = 0;
            }
        }

        while (!q.empty()) {
            int state = q.front();
            q.pop();

            for (int i = 0; i < ALPHABET_SIZE; ++i) {
                if (trie[state].children[i] != -1) {
                    int nextState = trie[state].children[i];
                    int fail = trie[state].fail;
                    while (fail != -1 && trie[fail].children[i] == -1) {
                        fail = trie[fail].fail;
                    }

                    trie[nextState].fail = (fail == -1) ? 0 : trie[fail].children[i];
                    if (trie[nextState].fail != -1) {
                        trie[nextState].output.insert(trie[nextState].output.end(), 
                                                       trie[trie[nextState].fail].output.begin(),
                                                       trie[trie[nextState].fail].output.end());
                    }
                    q.push(nextState);
                }
            }
        }
    }

    vector<int> search(const string &text) {
        vector<int> result;
        int node = 0;

        for (char c : text) {
            int idx = c - 'a'; 
            while (node != -1 && trie[node].children[idx] == -1) {
                node = trie[node].fail;
            }

            if (node == -1) {
                node = 0;
                continue;
            }

            node = trie[node].children[idx];

            if (!trie[node].output.empty()) {
                for (int index : trie[node].output) {
                    result.push_back(index);
                }
            }
        }

        return result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<string> passwords(n);
    for (int i = 0; i < n; i++) {
        cin >> passwords[i];
    }

    AhoCorasick ac;
    for (int i = 0; i < n; i++) {
        ac.addPattern(passwords[i], i);
    }
    ac.build();

    long long count = 0;

    for (int i = 0; i < n; i++) {
        vector<int> matches = ac.search(passwords[i]);
        unordered_set<int> unique_matches;

        for (int match : matches) {
            if (match != i) {
                unique_matches.insert(match);
            }
        }

        count += unique_matches.size();
    }

    cout << count << endl;
    return 0;
}
