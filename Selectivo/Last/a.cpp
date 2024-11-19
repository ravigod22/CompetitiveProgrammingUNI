#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int cnt = 0;
            while (i < n && tmp == s[i]) {
                ++i;
                cnt++;
            }
            if (tmp == 'N') ans += (cnt / 2);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    while (tt--) {
        solve();
    }
    return 0;
}


