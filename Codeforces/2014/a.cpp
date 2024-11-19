#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    int roby = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= k) {
            roby += a[i];
        }
        else if (a[i] == 0 && roby > 0) {
            roby--;
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}

