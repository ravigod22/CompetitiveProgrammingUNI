#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

using i64 = long long;

void solve() {
    int n; cin >> n;
    auto ndig = [&] (int num) -> int {
        int cnt = 0;
        while (num) {
            cnt++;
            num /= 10;
        }
        return cnt;
    };
    int t = ndig(n);
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        string tmp(t, i + '0');
        i64 num = stoll(tmp);
        if (num <= 1LL * n) ans++;
    }
    ans += 9 * (t - 1);
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


