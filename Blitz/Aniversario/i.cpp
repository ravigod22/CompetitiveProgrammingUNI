#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};


void solve() {
    string s; cin >> s;
    reverse(s.begin(), s.end());
    int n = s.size();
    int ans = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == '0') ans += 1;
        else ans += 2;
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

