#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Структура для представления состояния в автомате Ахо-Корасика
struct TrieNode {
    unordered_map<char, TrieNode*> children;
    TrieNode* fail; // Указатель на состояние для неудачного перехода
    vector<int> output; // Входящие слова, которые заканчиваются в этом состоянии

    TrieNode() : fail(nullptr) {}
};

// Класс для создания и использования автомат Ахо-Корасика
class AhoCorasick {
public:
    AhoCorasick() {
        root = new TrieNode();
    }

    ~AhoCorasick() {
        clear(root);
    }

    void insert(const string& word, int index) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->output.push_back(index);
    }

    void build() {
        queue<TrieNode*> q;
        root->fail = root;
        for (auto it = root->children.begin(); it != root->children.end(); ++it) {
            it->second->fail = root;
            q.push(it->second);
        }

        while (!q.empty()) {
            TrieNode* node = q.front();
            q.pop();

            for (auto it = node->children.begin(); it != node->children.end(); ++it) {
                char c = it->first;
                TrieNode* child = it->second;

                TrieNode* fail = node->fail;
                while (fail != root && !fail->children.count(c)) {
                    fail = fail->fail;
                }
                if (fail->children.count(c)) {
                    child->fail = fail->children[c];
                } else {
                    child->fail = root;
                }
                child->output.insert(child->output.end(), child->fail->output.begin(), child->fail->output.end());
                q.push(child);
            }
        }
    }

    void search(const string& text, vector<vector<int>>& result) {
        TrieNode* node = root;
        for (int i = 0; i < text.size(); ++i) {
            char c = text[i];

            while (node != root && !node->children.count(c)) {
                node = node->fail;
            }
            if (node->children.count(c)) {
                node = node->children[c];
            }

            // Обрабатываем выходящие слова
            for (int index : node->output) {
                result[index].push_back(i);
            }
        }
    }

private:
    TrieNode* root;

    void clear(TrieNode* node) {
        for (auto it = node->children.begin(); it != node->children.end(); ++it) {
            clear(it->second);
        }
        delete node;
    }
};

int main() {
    string text;
    cin >> text;

    int N;
    cin >> N;

    AhoCorasick ahoCorasick;
    vector<string> dictionary(N);
    
    // Ввод словарика
    for (int i = 0; i < N; ++i) {
        cin >> dictionary[i];
        ahoCorasick.insert(dictionary[i], i);
    }
    
    ahoCorasick.build();

    // Результаты для каждого слова из словаря
    vector<vector<int>> result(N);
    ahoCorasick.search(text, result);

    // Форматируем и выводим результат
    for (int i = 0; i < N; ++i) {
        cout << result[i].size();
        for (int index : result[i]) {
            cout << " " << index; // 1-based indexing
        }
        cout << endl;
    }

    return 0;
}
