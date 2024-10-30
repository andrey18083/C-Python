#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26] = {nullptr}; 
    bool isEndOfWord = false;
    int uniqueChildCount = 0; 

    TrieNode() = default;
};

class Trie {
private:
    TrieNode* root;
    int totalUniqueCount;

public:
    Trie() {
        root = new TrieNode();
        totalUniqueCount = 0;
    }
    void insert(const string& word, TrieNode* startNode) {
        TrieNode* currentNode = startNode;
        for (char ch : word) {
            int index = ch - 'a'; 
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode();
                currentNode->uniqueChildCount++; 
                totalUniqueCount++; 
            }
            currentNode = currentNode->children[index];
        }
        if (!currentNode->isEndOfWord) {
            currentNode->isEndOfWord = true;
        }
    }
    int getTotalUniqueCount() const {
        return totalUniqueCount; 
    }
    TrieNode* getRoot() const {
        return root; 
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    vector<char> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
    }
    Trie trie;
    vector<TrieNode*> nodes(n + 1);
    nodes[0] = trie.getRoot(); 
    for (int i = 0; i < n; ++i) {
        string path = string(1, c[i]); 
        trie.insert(path, nodes[p[i] - 1]); 
        nodes[i + 1] = nodes[p[i] - 1]->children[c[i] - 'a']; 
        cout << trie.getTotalUniqueCount() << endl; 
    }
    return 0;
}
