#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int tmp = a[0];
    for (int i = 1; i < n; ++i) {
        tmp = gcd(tmp, a[i]);
    }
    if (count(a.begin(), a.end(), tmp)) {
        cout << n - count(a.begin(), a.end(), tmp) << "\n";
    }
    else {
        bool can = 0;
        for (int& e : a) e /= tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (gcd(a[i], a[j]) == 1) {
                    can = 1;
                }
                else {
                                        
                }
            }
        }
        if (can) cout << n << "\n";
        else cout << n + 1 << "\n";
    }
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


