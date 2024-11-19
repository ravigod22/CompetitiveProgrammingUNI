#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    long long k; cin >> k;
    long long lo = 1;
    long long hi = 3e18;
    auto f = [&] (long long x) -> long long {
        return x - (long long)sqrtl(x);
    };
    while (lo < hi) {
        long long mid = (lo + hi) / 2;
        if (f(mid) >= k) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
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


