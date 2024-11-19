#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int maxe = *max_element(a.begin(), a.end());   
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (maxe == a[i]) {
            if (i & 1) ans = max(ans, maxe + n / 2);
            else ans = max(ans, maxe + (n + 1) / 2);
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

