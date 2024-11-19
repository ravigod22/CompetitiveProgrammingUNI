#include <bits/stdc++.h>
using namespace std;


#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    int ans = n - 1;
    for (int i = 0; i + 1 < n; ++i) {
        int sum = a[i] + a[i + 1];
        int lo = 0;
        int hi = (int)a.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (sum > a[mid]) lo = mid;
            else hi = mid - 1;
        }
        int dis = n - (lo - i + 1);
        ans = min(ans, dis);
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


