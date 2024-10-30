#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Dictionary {
private:
    struct Node {
        string slova;
        int count;
        Node* left;
        Node* right;
        Node(const string& val) : slova(val), count(1), left(nullptr), right(nullptr) {}
    };
    Node* root;
    void insert(Node*& node, const string& s) {
        if (!node) {
            node = new Node(s);
            return;
        }
        if (s == node->slova) {
            return;
        }
        if (s < node->slova) {
            insert(node->left, s);
        } else {
            insert(node->right, s);
        }
        node->count = 1 + (node->left ? node->left->count : 0) + (node->right ? node->right->count : 0);
    }
    string get_kth(Node* node, int k) {
        int left_count = node->left ? node->left->count : 0;
        if (k <= left_count) {
            return get_kth(node->left, k);
        } else if (k == left_count + 1) {
            return node->slova;
        } else {
            return get_kth(node->right, k - left_count - 1);
        }
    }

public:
    Dictionary() : root(nullptr) {}
    void add(const string& s) {
        insert(root, s);
    }
    string get_kth(int k) {
        return get_kth(root, k);
    }
};

int main() {
    int N;
    cin >> N;
    Dictionary dict;
    for (int i = 0; i < N; ++i) {
        int cm;
        cin >> cm;
        if (cm == 1) {
            string S;
            cin >> S;
            dict.add(S);
        } else if (cm == 2) {
            int k;
            cin >> k;
            cout << dict.get_kth(k) << endl;
        }
    }
    return 0;
}