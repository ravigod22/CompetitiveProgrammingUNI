#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    int kevin = a[0];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> pos(m);
    for (int i = 0; i < m; ++i) {
        int id = lower_bound(a.begin(), a.end(), b[i]) - a.begin();
        if (a[id] <= kevin) pos[i] = 1;
        else pos[i] = n - id + 1;
    }
    sort(pos.begin(), pos.end());
    for (int i = 1; i <= m; ++i) {
        i64 sum = 0;
        for (int j = i; j <= m; j += i) {
            sum += pos[j - 1];
        }
        cout << sum << " \n"[i == m];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
