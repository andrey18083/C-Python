#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    void inseart(const std::string& word) {
        TrieNode* curr = root;
        for (char ch: word) {
            if (!curr->children.count(ch)) {
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
    }
    int countCharacters() {
        return countCharacters(root);
    }
private:
    int countCharacters(TrieNode* node) {
        int count = 0;
        for (const auto& pair : node->children){
            count +=1 + countCharacters(pair.second);
        }
        return count;
    }
};

int main() {
    int N;
    std::cin >> N;

    std::vector<std::string> words(N);
    int total = 0;
    Trie trie;

    for (int i = 0; i<N; ++i){
        std::cin >> words[i];
        total += words[i].length();
        trie.inseart(words[i]);
    }
    int trieChars = trie.countCharacters();

    int differense = total - trieChars;
    std::cout << differense;

    return 0;
}