#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int main(){
    int N;
    cin >> N;

    vector<int> freuq(N);
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for(int i = 0; i < N; ++i){
        cin >> freuq[i];
        minHeap.push(freuq[i]);
    }

    int total = 0;
    while (minHeap.size() > 1){
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();

        int newfreuq = first + second;

        total +=newfreuq;

        minHeap.push(newfreuq);
    }
    cout << total;
    return 0;
}