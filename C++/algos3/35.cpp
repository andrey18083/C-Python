#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

void processTraversal(const string& traversal, vector<string>& codes) {
    stack<int> s; // Stack to keep track of the current position in the tree
    string currentCode; // Current binary code representing the path to a leaf
    bool atLeaf = false; // Flag to indicate if we are at a leaf

    for (char c : traversal) {
        if (c == 'D') {
            if (s.empty()) {
                // Starting out (first child)
                currentCode += '0'; // Left child
                s.push(1); // 1 means we are in a child
            } else {
                // Going down
                if (s.top() == 1) {
                    currentCode += '0'; // Left child
                    s.push(2); // 2 means we are now going to right child next
                } else {
                    currentCode += '1'; // Right child
                    s.pop(); // We are coming back up now
                }
            }
            atLeaf = false;
        } else if (c == 'U') {
            // We need to go up to the parent
            while (!s.empty() && s.top() == 2) {
                s.pop(); // Going back up right child
            }
            // After going up, we need to check if we are coming from left
            if (!s.empty() && s.top() == 1) {
                // If we are coming from the left child, go to the right of the parent
                currentCode = currentCode.substr(0, currentCode.size() - 1) + '1';
            }
            atLeaf = true;
        }

        // If it's a leaf (no more children to process)
        if (atLeaf) {
            codes.push_back(currentCode);
            if (s.empty()) {
                // Reset current code as we reached the top
                currentCode = "";
            } else {
                // Go back up to parent state
                s.pop();
                currentCode = currentCode.substr(0, currentCode.size() - 1);
            }
            atLeaf = false; // reset the leaf flag
        }
    }
}

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignore newline after number
    
    for (int i = 0; i < N; ++i) {
        string traversal;
        getline(cin, traversal);
        
        vector<string> codes;
        processTraversal(traversal, codes);
        
        cout << codes.size() << endl;
        for (const string& code : codes) {
            cout << code << endl;
        }
    }
    
    return 0;
}
