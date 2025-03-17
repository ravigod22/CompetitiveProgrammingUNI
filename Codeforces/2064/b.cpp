#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> cnt(n + 1, 0);
    for (int& e : a) cin >> e, cnt[e]++;
    int ans = 0;
    int tmp = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] == 1) tmp++;
        else {
            if (tmp > ans) {
                ans = tmp;
                r = i - 1;
                l = i - tmp;
            }
            tmp = 0;
        }
    }
    if (tmp > ans) {
        ans = tmp;
        r = n - 1;
        l = n - tmp;
    }
    if (ans == 0) cout << 0 << "\n";
    else cout << l + 1 << " " << r + 1 << "\n";
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


