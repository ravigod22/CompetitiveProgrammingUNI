#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ++i;
            continue;
        }
        char tmp = s[i];
        int cnt = 0;
        while (i < n && tmp == s[i] && cnt < m) {
            i++;
            cnt++;
        }
        if (cnt >= m) {
            ans++;
            i += k - 1;
        }
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
