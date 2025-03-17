#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k, p;
    cin >> n >> k >> p;
    if (k < 0) {
        int aux = -k;
        int tmp = (aux + p - 1) / p;
        if (tmp > n) cout << -1 << "\n";
        else cout << tmp << "\n";
    }
    else if (k == 0) {
        cout << 0 << "\n";
    }
    else {
        int tmp = (k + p - 1) / p;
        if (tmp > n) cout << -1 << "\n";
        else cout << tmp << "\n";
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


