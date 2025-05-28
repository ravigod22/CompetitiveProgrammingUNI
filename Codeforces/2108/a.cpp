#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    reverse(p.begin(), p.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += abs(p[i] - (i + 1));
    }
    cout << res / 2 + 1 << "\n";
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


