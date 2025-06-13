#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> w(m), l(m), h(m);
    for (int i = 0; i < m; ++i)
        cin >> w[i] >> l[i] >> h[i];
    vector<int> fibo(n + 2, 1);
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i <= n + 1; ++i) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }
    int base = fibo[n];
    int height = fibo[n + 1];
    for (int i = 0; i < m; ++i) {
        int A = min(w[i], l[i]);
        int B = max(w[i], l[i]);
        if (A >= base && h[i] >= height) cout << "1";
        else if (A >= base && B >= height && h[i] >= base) cout << "1";
        else cout << "0";
    }
    cout << "\n";
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


