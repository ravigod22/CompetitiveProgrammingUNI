#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<int> a(n);
    vector<pair<int, int>> b;
    for (int& e : a) cin >> e;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        b.emplace_back(x, i);
    }
    sort(b.rbegin(), b.rend());
    vector<int> ans(m);
    for (int i = 0, j = 0; i < m; ++i) {
        while (j < n && a[j] > b[i].first) ++j;
        if (j == n) {
            ans[b[i].second] = (a.back() <= b[i].first ? n : -1);
        }
        else {
            ans[b[i].second] = (a[j] <= b[i].first ? j + 1 : -1);
        }
    }
    for (int i = 0; i < m; ++i) cout << ans[i] << "\n";
    return 0;
}
