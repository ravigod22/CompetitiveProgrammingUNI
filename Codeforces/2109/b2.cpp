#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    i64 mprime = m, nprime = n;
    i64 row = min(a, n - a);
    i64 col = min(b, m - b);

    auto f = [&] (i64 N, i64 M, i64 A, i64 B) -> int {
        int cnt = 1;
        i64 res = min(A, N - A + 1);
        i64 tmp = 1;
        while (tmp < res) {
            tmp *= 2;
            cnt += 1;
        }
        tmp = 1;
        while (tmp < M) {
            tmp *= 2;
            cnt += 1;
        }
        return cnt;
    };
    cout << min(f(n, m, a, b), f(m, n, b, a)) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


