#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    int cnt = 0;
    while (n >= k && k > 1) {
        int tmp = n;
        int remain = 1;
        while (tmp >= k) {
            tmp /= k;
            remain *= k;
        }
        n -= remain;
        cnt++;
    }
    cout << cnt + n << "\n";
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

