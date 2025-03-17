#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, t, k; cin >> n >> t >> k;
    auto ask = [&] (int l, int r) -> int {
        cout << "? " << l << " " << r << endl;
        int x; cin >> x;
        return x;
    };
    int lo = 1;
    int hi = n;
    int cnt = 0;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int sum = ask(1, mid);
        cnt++;
        if (k <= mid - sum) hi = mid;
        else lo = mid + 1;
    }
    assert (cnt <= 20);
    cout << "! " << lo << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


