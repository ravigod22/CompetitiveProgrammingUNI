#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    string s; cin >> s;
    const int n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'W' && s[i + 1] == 'A') {
            int p = i;
            while (p >= 0 && p + 1 < n && s[p] == 'W' && s[p + 1] == 'A') {
                s[p] = 'A', s[p + 1] = 'C';
                p--;
            }
        }
    }
    cout << s << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


