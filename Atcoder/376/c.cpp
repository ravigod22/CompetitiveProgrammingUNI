#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n - 1);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int lo = a[0];
    int hi = a[n - 1] + 1;
    auto f = [&] (int mid) -> bool {
        vector<int> tmp = b;
        tmp.emplace_back(mid);
        sort(tmp.begin(), tmp.end());
        for (int i = 0; i < n; ++i) {
            if (a[i] > tmp[i]) return false;
        }
        return true;
    };
    while (lo < hi) {
        int mid = (lo + hi) / 2;    
        if (f(mid)) hi = mid;
        else lo = mid + 1;
    }
    if (f(lo)) cout << lo << "\n";
    else cout << -1 << "\n";
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




