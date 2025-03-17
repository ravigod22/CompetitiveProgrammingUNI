#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k, d, w; cin >> n >> k >> d >> w;
    vector<int> t(n);
    for (int& e : t) cin >> e;
    int cnt = 0;
    for (int i = 0; i < n; ) {
        int lim = t[i] + w + d;
        int can = k;
        while (i < n && can && t[i] <= lim) {
            ++i;
            can--;
        }
        cnt++;
    }
    cout << cnt << "\n";
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


