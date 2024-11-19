#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, m, L; cin >> n >> m >> L;
    vector<tuple<int, int, int>> line;
    // 1 -> hurdles
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        line.emplace_back(l, r, 1);
    }
    // 0 -> power
    i64 power = 1;
    for (int i = 0; i < m; ++i) {
        int x, p; cin >> x >> p;
        power += p;
        line.emplace_back(x, p, 0);
    }
    line.emplace_back(1, 0, 0);
    sort(line.rbegin(), line.rend());
    int cnt = m;
    int len = line.size();
    for (int i = 0; i < len; ) {
        int l, r, id;
        tie(l, r, id) = line[i];
        int jump = 0;
        while (i < len && id == 1) {
            jump = max(jump, r - l + 1);
            ++i;
            if (i < len) tie(l, r, id) = line[i];
        }
        if (i == len) break;
        int x, p;
        tie(x, p, id) = line[i];
        vector<int> take;
        while (i < len && id == 0) {
            take.emplace_back(p);
            if (p) cnt--;
            power -= p;
            ++i;
            if (i < len) tie(x, p, id) = line[i];
        }
        sort(take.rbegin(), take.rend());
        pv(take);
        dbg(jump);
        dbg(power);
        i64 tmp = power;
        for (int k = 0; k < take.size(); ++k) {
            if (tmp > 1LL * jump) {
                break;
            }
            else {
                tmp += 1LL * take[k];
                cnt++;
            }
        }
        if (tmp <= jump) {
            cout << -1 << "\n";
            return;
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





