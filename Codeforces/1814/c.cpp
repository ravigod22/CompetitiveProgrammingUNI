#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<int> r(n);
    for (auto& e : r) cin >> e;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&] (int& a, int& b) {
        return r[a] > r[b];
    });
    vector<int> time1(n, 0), time2(n, 0);
    for (int i = 0; i < n; ++i) {
        time1[i] = s1 * (i + 1);
        time2[i] = s2 * (i + 1);
    }
    vector<int> f, s;
    int p = 0, q = 0;
    if (s1 > s2) {
        for (int i = 0; i < n; ++i) {
            if (time1[p] >= time2[q]) {
                s.push_back(order[i] + 1);
                q++;
            }
            else {
                f.push_back(order[i] + 1);
                p++;
            }
        }
    }
    else {
        swap(time1, time2);
        // time1 == s2
        // time2 == s1
        // s1 < s2
        for (int i = 0; i < n; ++i) {
            if (time1[p] < time2[q]) {
                s.push_back(order[i] + 1);
                p++;
            }
            else {
                f.push_back(order[i] + 1);
                q++;
            }
        }  
    }
    cout << (int)f.size() << " \n"[f.empty()];
    for (int i = 0; i < (int)f.size(); ++i) cout << f[i] << " \n"[i + 1 == (int)f.size()];
    cout << (int)s.size() << " \n"[s.empty()];
    for (int i = 0; i < (int)s.size(); ++i) cout << s[i] << " \n"[i + 1 == (int)s.size()];
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
