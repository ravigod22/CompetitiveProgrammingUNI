#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    i64 n, m, a, b;
    cin >> n >> m >> a >> b;
    int cnt = 0;
    while (n > 1 || m > 1) {
        i64 pos[] = {(a  - 1) * m, (n - a) * m, n * (b - 1), n * (m - b)};
        i64 mn = *max_element(pos, pos + 4);
        i64 h = -1, w = -1;
        for (int i = 0; i < 4; ++i) {
            if (mn == pos[i]) {
                if (i == 0) h = a - 1, w = m;
                if (i == 1) h = n - a, w = m;
                if (i == 2) h = n, w = b - 1;
                if (i == 3) h = n, w = m - b;
                break;
            }
        }
        if (h == n) {
            m -= w;
        }
        else if (w == m) {
            n -= h;
        }
        a = (n + 1) / 2;
        b = (m + 1) / 2;
        cnt += 1;
    }
    cout << cnt << "\n";
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

