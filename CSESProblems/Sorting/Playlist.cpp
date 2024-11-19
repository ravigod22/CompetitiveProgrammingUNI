#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> k(n);
    for (int& e : k) cin >> e;
    set<int> s;
    deque<int> ele;
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < n; ) {
        while (i < n && !s.count(k[i])) {
            s.emplace(k[i]);
            ele.emplace_back(k[i]);
            ++i;
        }
        ans = max(ans,(int)s.size());
        while (i < n && j < n && ele.front() != k[i]) {
            s.erase(ele.front());
            ele.pop_front();
            ++j;
        }
        if (i >= n) break;
        s.erase(k[i]);
        ele.pop_front();
        ++j;
    }
    cout << ans << "\n";
    return 0;
}
