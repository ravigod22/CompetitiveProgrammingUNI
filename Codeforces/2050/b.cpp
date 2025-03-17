#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool solve() {
    int n; cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    i64 acc = accumulate(a.begin(), a.end(), 0LL);
    if (acc % n) return 0;
    for (int i = 0; i + 2 < n; ++i) {
        if (a[i] == acc / n) continue;
        a[i + 2] -= (acc / n - a[i]);
        a[i] = acc / n;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] != acc / n) return 0;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}
