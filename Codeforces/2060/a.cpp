#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map<int, int> cnt;
    cnt[a + b]++;
    cnt[c - b]++;
    cnt[d - c]++;
    int ans = 1;
    for (auto e : cnt) ans = max(ans, e.second);
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


