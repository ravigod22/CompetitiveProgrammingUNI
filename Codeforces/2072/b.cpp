#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cnt1 = count(s.begin(), s.end(), '-');
    int cnt2 = count(s.begin(), s.end(), '_');
    cout << 1LL * (cnt1 / 2) * cnt2 * ((cnt1 + 1) / 2) << "\n";
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


