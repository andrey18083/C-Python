#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> qwer(const vector<int>& a){
    int n = a.size();
    vector<int> pi(n);
    for (int i =1; i<n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && a[i] != a[j]) {
            j = pi[j-1];
        }
        if (a[i] == a[j]){
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

int main() {
    int N; 
    cin >> N;
    vector<int> numbers(N);
    for (int i = 0; i < N; ++i){
        cin >> numbers[i];
    }
    vector<int> rrr = numbers;
    rrr.pop_back();
    vector<int> pi = qwer(rrr);

    int len = N-1;
    int minn = len - pi[len - 1];

    if (len % minn == 0){
        cout << minn;
    } else {
        cout << len;
    }
}