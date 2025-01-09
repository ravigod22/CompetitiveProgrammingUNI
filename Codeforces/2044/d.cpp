#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> s;
    for (int i = 1; i <= n; ++i) s.emplace(i);
    for (int& e : a) cin >> e; 
    vector<int> b;
    for (int i = 0; i < n; ++i) {
        if (s.count(a[i])) {
            b.emplace_back(a[i]);
            s.erase(a[i]);
        }
        else b.emplace_back(-1);
    }
    for (int i = 0; i < n; ++i) {
        if (b[i] == -1) {
            b[i] = *s.begin();
            s.erase(s.begin());
        }
        cout << b[i] << " \n"[i + 1 == n];
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

