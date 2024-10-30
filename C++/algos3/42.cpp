#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validateColor(int node, char assignedColor, const string& originalColors,
                   const vector<vector<int>>& adjacencyList, vector<bool>& isVisited,
                   string& updatedColors) {
    isVisited[node] = true;
    if (assignedColor == originalColors[node]) return false;
    char oldColor = updatedColors[node];
    updatedColors[node] = assignedColor;
    bool isValid = true;
    for (int neighbor : adjacencyList[node]) {
        if (isVisited[neighbor]) {
            if (updatedColors[neighbor] == assignedColor) {
                isValid = false; 
            }
            continue;
        }
        char newColor = (originalColors[neighbor] != 'B' && assignedColor != 'B') ? 'B' :
                        (originalColors[neighbor] == assignedColor || (originalColors[neighbor] == 'R' && assignedColor == 'B') || 
                         (originalColors[neighbor] == 'B' && assignedColor == 'R')) ? 'G' : 'R';

        if (originalColors[neighbor] != assignedColor) {
            isValid &= validateColor(neighbor, newColor, originalColors, adjacencyList, isVisited, updatedColors);
        }
    }
    if (!isValid) updatedColors[node] = oldColor;
    return isValid;
}

bool checkGraphColors(int node, char color, const string& originalColors,
                      const vector<vector<int>>& adjacencyList, string& updatedColors) {
    vector<bool> visited(originalColors.size(), false);
    return validateColor(node, color, originalColors, adjacencyList, visited, updatedColors);
}

int main() {
    int vertexCount, edgeCount;
    cin >> vertexCount >> edgeCount;
    string colors;
    cin >> colors;
    vector<vector<int>> adjacencyList(vertexCount);
    for (int i = 0; i < edgeCount; ++i) {
        int start, end;
        cin >> start >> end;
        adjacencyList[start - 1].push_back(end - 1);
        adjacencyList[end - 1].push_back(start - 1);
    }
    string updatedColors(vertexCount, ' ');
    for (int i = 0; i < vertexCount; ++i) {
        if (updatedColors[i] == ' ') {
            checkGraphColors(i, 'R', colors, adjacencyList, updatedColors);
            checkGraphColors(i, 'G', colors, adjacencyList, updatedColors);
            checkGraphColors(i, 'B', colors, adjacencyList, updatedColors);
        }
    }
    if (updatedColors.find(' ') != string::npos) {
        cout << "Impossible" << endl;
    } else {
        cout << updatedColors << endl;
    }

    return 0;
}
