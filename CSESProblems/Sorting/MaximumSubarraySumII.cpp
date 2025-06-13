#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<i64> pre(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + a[i];
    }
    deque<pair<i64, int>> Q;
    i64 ans = -1e18;
    for (int i = l; i <= n; ++i) {
        while (!Q.empty() && Q.back().first > pre[i - l]) {
            Q.pop_back();
        }
        Q.emplace_back(pre[i - l], i - l);
        ans = max(ans, pre[i] - Q.front().first);
        while (!Q.empty() && i - Q.front().second >= r) {
            Q.pop_front();
        }
    }
    cout << ans << "\n";
    return 0;
}
