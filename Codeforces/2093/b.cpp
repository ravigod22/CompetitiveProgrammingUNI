#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    string s; cin >> s;
    const int n = s.size();
    int ans = 1e9;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') continue;
        int cnt = 0;
        for (int j = 0; j < i; ++j) {
            if (s[j] == '0') cnt++;
        }
        ans = min(ans, n - cnt - 1);
    }
    cout << ans << "\n";
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


