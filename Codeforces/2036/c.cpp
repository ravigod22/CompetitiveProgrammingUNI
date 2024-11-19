#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    string s; cin >> s;
    int q; cin >> q;
    const int n = s.size();
    vector<int> a(n, 0);
    for (int i = 0; i + 3 < n; ++i) {
        a[i] = (s.substr(i, 4) == "1100");
    }
    int ans = accumulate(a.begin(), a.end(), 0);
    for (int i = 0; i < q; ++i) {
        int pos; cin >> pos;
        char p; cin >> p;
        pos--;
        int tmp = 0;
        for (int j = max(pos - 4, 0); j <= pos; ++j) {
            if (j + 3 < n) tmp += (s.substr(j, 4) == "1100");
        }
        ans -= tmp;
        tmp = 0;
        s[pos] = p;
        for (int j = max(pos - 4, 0); j <= pos; ++j) {
            if (j + 3 < n) tmp += (s.substr(j, 4) == "1100");
        }
        ans += tmp;
        cout << (ans > 0 ? "YES\n" : "NO\n");
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


