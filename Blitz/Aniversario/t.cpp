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
    for (int i = 0; i < n; ) {
        char cur = s[i];
        int cnt = 0;
        while (i < n && cur == s[i]) ++i, cnt++;
        if (i == n) {
            if (cnt == 1) break;
            else {
                ans += cnt + 1;
            }
        }
        else {
            if (cur == '1') {
                ans += cnt + 1;
                s[i] = '1';
            }
            else {
                ans += cnt;
            }
        }
    }
    cout << ans << endl;
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


