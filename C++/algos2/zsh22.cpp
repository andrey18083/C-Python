#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insertNode(Node* root, int value){ 
    if (root == nullptr){
        return createNode(value);
    }

    if (value < root->data){
        root->left = insertNode(root->left, value);
    } else if (value > root->data){
        root->right = insertNode(root->right, value);
    }
    return root;
}

bool searchNode(Node* root, int value){
    if (root == nullptr) {
        return false;
    }
    if (root->data == value){
        return true;
    }
    if (value < root->data){
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

void derevo(Node* root, int dp){
    if (root == nullptr){
        return;
    }
    derevo(root->left, dp+1);
    for (int i = 0; i<dp; ++i){
        cout << ".";
    }
    cout << root->data << endl;
    derevo(root->right, dp+1);
}

int main(){
    Node* root = nullptr;

    string command;
    while (cin >> command){
        if (command == "ADD"){
            int value;
            cin >> value;
            if (searchNode(root, value)){
                cout << "ALREADY" << endl;
            } else {
                root = insertNode(root, value);
                cout << "DONE" << endl;
            }
        } else if (command == "SEARCH") {
            int value;
            cin >> value;
            if (searchNode(root, value)){
                cout << "YES" << endl; 
            } else {
                cout << "NO" << endl;   
            }
        } else if (command == "PRINTTREE"){
            derevo(root, 0);
        }
    }
    return 0;
}

