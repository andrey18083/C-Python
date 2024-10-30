#include <iostream>
#include <vector>
using namespace std;

const int maxn = 1e9;

int n;
vector<vector<int>>m,res;

void floyd(){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            for (int k = 0; k<n; k++) {
                if (m[j][i] < maxn && m[i][k] < maxn){
                    if (m[j][i] + m[i][k] < m[j][k]) { 
                        m[j][k] = m[j][i]+m[j][k];
                    }
                    if (m[j][k] < -maxn) { 
                        m[j][k] = -maxn;
                    }
                }
            }
        }
    }
}

int main(){
    cin >>n;
    m.resize(n, vector<int>(n));
    res.resize(n, vector<int>(n));
    for (int i=0; i<n; i++){
        for (int j=0; j<n;j++){
            cin >> m[i][j];
            if (m[i][j] == 0 && i!=j){
                m[i][j] = maxn;
            }
        }
    }
    floyd();
    for (int i=0; i<n; i++){
        for (int j=0; j<n;j++){
            if (m[i][j] == maxn){
                res[i][j] = 0;
            } else {
                res[i][j]=1;
                for (int k=0; k<n; k++){
                    if (m[k][k]<0 && m[i][k]<maxn && m[k][j]<maxn){
                        res[i][k] = res[i][j]=res[k][j]=2;
                    }
                }
            }
        }
    }
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cout <<res[i][j]<<" ";
        }
        cout << endl;
    }
    return 0;
}