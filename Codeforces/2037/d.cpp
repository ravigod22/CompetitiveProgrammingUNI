#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, m, L; cin >> n >> m >> L;
    vector<int> l(n), r(n);
    vector<int> x(m), v(m);
    for (int i = 0; i < n; ++i) cin >> l[i] >> r[i];
    for (int i = 0; i < m; ++i) cin >> x[i] >> v[i];
    priority_queue<int> pq;
    int power = 1;
    int cnt = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j < m && x[j] < l[i]) {
            pq.emplace(v[j]);
            ++j;
        }
        while (power <= r[i] - l[i] + 1) {
            if (pq.empty()) {
                cout << -1 << "\n";
                return;
            }
            int tmp = pq.top();
            pq.pop();
            power += tmp;
            cnt++;
        }
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




