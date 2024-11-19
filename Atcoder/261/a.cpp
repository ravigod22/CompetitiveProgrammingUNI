#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
    if (l1 <= l2) {
        if (r1 <= l2) cout << 0 << "\n";
        else if (r2 <= r1) cout << r2 - l2 << "\n";
        else cout << r1 - l2 << "\n"; 
    }
    else {
        if (r2 <= l1) cout << 0 << "\n";
        else if (r1 <= r2) cout << r1 - l1 << "\n";
        else cout << r2 - l1 << "\n";
    }
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


