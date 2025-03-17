#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


i64 binpow(int a, int e) {
    i64 res = 1;
    while (e) {
        if (e & 1) res = 1LL * res * a;
        a = 1LL * a * a;
        e /= 2;
    }
    return res;
}

void solve() {
    string s; cin >> s;
    i64 num = stoll(s);
    reverse(s.begin(), s.end());
    const int n = s.size();
    int ent = (s[0] - '0');
    int ans = (ent >= 7 ? ent - 7 : 10 + ent - 7);
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 8; ++j) {
            i64 res = num + j * (binpow(10, i + 1) - 1);
            string number = to_string(res);
            for (auto e : number) {
                if (e == '7') {
                    ans = min(ans, j);
                }
            }
        }
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




