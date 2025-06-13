#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    i64 acc = accumulate(a.begin(), a.end(), 0LL);
    i64 f = n * (n + 1) / 2;
    if (acc % f) return false;
    int p = acc / f;
    int y = a[0] - p;
    if (y < 0) return false;
    y /= n - 1;
    int x = p - y;
    if (x < 0) return false;
    
    for (int i = 0; i < n; ++i) {
        i64 num = 1LL * x * (i + 1) + 1LL * (n - i) * y;
        if (1LL * a[i] != num) return false;
    }
    return true;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}


