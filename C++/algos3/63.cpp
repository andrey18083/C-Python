#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TreapNode {
    int key, priority;
    TreapNode* left;
    TreapNode* right;

    TreapNode(int k) : key(k), priority(rand()), left(nullptr), right(nullptr) {}
};

using Treap = TreapNode*;

void split(Treap t, int key, Treap &left, Treap &right) {
    if (!t) {
        left = right = nullptr;
    } else if (key < t->key) {
        split(t->left, key, left, t->left);
        right = t;
    } else {
        split(t->right, key, t->right, right);
        left = t;
    }
}

Treap merge(Treap left, Treap right) {
    if (!left || !right) {
        return left ? left : right;
    }
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        return left;
    } else {
        right->left = merge(left, right->left);
        return right;
    }
}

Treap insert(Treap t, int key) {
    Treap new_node = new TreapNode(key);
    Treap left, right;
    split(t, key, left, right);
    return merge(merge(left, new_node), right);
}

Treap erase(Treap t, int key) {
    if (t->key == key) {
        Treap temp = t;
        t = merge(t->left, t->right);
        delete temp;
    } else if (key < t->key) {
        t->left = erase(t->left, key);
    } else {
        t->right = erase(t->right, key);
    }
    return t;
}

Treap root = nullptr;

int main() {
    srand(time(0));
    int n, act, t, m;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> act;

        if (act == 1) {
            cin >> t >> m;
            root = insert(root, m);
        } else {
            cin >> t;
            Treap left, right;
            split(root, t, left, right);
            cout << left->key << endl;
            root = merge(left, right);
            root = erase(root, left->key);
        }
    }

    return 0;
}
