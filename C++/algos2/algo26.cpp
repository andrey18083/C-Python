#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Detail {
    int time;
    int dependency_count;
    vector<int> dependencies;
};

int main() {
    int n;
    cin >> n;

    vector<Detail> details(n + 1); // 1-based indexing

    for (int i = 1; i <= n; ++i) {
        cin >> details[i].time;
    }

    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;

        details[i].dependency_count = k;

        for (int j = 0; j < k; ++j) {
            int dependency;
            cin >> dependency;
            details[dependency].dependencies.push_back(i);
        }
    }

    vector<int> earliest_time(n + 1, 0);
    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (details[i].dependency_count == 0) {
            q.push(i);
            earliest_time[i] = details[i].time;
        }
    }

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : details[current].dependencies) {
            earliest_time[next] = max(earliest_time[next], earliest_time[current] + details[next].time);

            if (--details[next].dependency_count == 0) {
                q.push(next);
            }
        }
    }

    int min_time = earliest_time[1];
    int count = 0;
    vector<int> order;

    for (int i = 1; i <= n; ++i) {
        if (earliest_time[i] == min_time) {
            count++;
            order.push_back(i);
        }
    }

    cout << min_time << " " << count << endl;
    for (int i = 0; i < count; ++i) {
        cout << order[i] << " ";
    }

    return 0;
}