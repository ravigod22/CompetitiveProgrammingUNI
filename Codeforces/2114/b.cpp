#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int cnt1 = count(s.begin(), s.end(), '1');
    int cnt0 = n - cnt1;
    if (cnt1 & 1) cnt1 -= 1, cnt0 -= 1;
    bool can = false;
    while (cnt1 >= 0 && cnt0 >= 0) {
        int tmp = cnt1 / 2 + cnt0 / 2;
        if (tmp == k) can = true;
        cnt1 -= 2, cnt0 -= 2;
    } 
    if (can) cout << "YES\n";
    else cout << "NO\n";
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


