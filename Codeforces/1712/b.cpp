#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 1);
    if (n & 1) {
        for (int i = 2; i < n; i += 2) {
            swap(ans[i], ans[i - 1]);
        }
    }
    else {
        for (int i = 1; i < n; i += 2) {
            swap(ans[i], ans[i - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


