#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    do {
        bool can = true;
        for (int i = 1; i < n; ++i) {
            int maxe = max(a[i], a[i - 1]);
            int k = i + 1;
            if (maxe % k != k - 1) can = false;
        }
        if (can) {
            for (int e : a) cout << e << " ";
            cout << "\n";
        }
    } while (next_permutation(a.begin(), a.end()));
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


