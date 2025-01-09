#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    set<int> p;
    for (int i = 1; i <= n; ++i) p.emplace(i);
    vector<int> ans(n, -1);
    int aux = 1;
    for (int i = k - 1; i < n; i += k) {
        ans[i] = aux;
        p.erase(aux);
        aux++;
    }
    for (int i = 0; i < n; ++i) {
        if (ans[i] == -1) {
            ans[i] = *p.begin();
            p.erase(p.begin());
        }
        cout << ans[i] << " \n"[i + 1 == n];
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

