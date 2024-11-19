#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int tmp = a[0];
    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] - tmp >= c) {
            cnt++;
            tmp = a[i];
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



