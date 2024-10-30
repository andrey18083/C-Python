#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> window(const vector<int>&nums, int k){
    int n = nums.size();
    deque<int> dq;
    vector<int> otv;
    for (int i = 0; i<n; ++i){
        if (!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] > nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if (i>=k-1){
            otv.push_back(nums[dq.front()]);
        }
    }
    return otv;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i<n; ++i){
        cin >> nums[i];
    }
    vector<int> otv = window(nums, k);
    for (int v:otv){
        cout<<v<<"\n";
    }
}