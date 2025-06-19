#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    vector<pair<int, int>> pos(2 * n + 1);
    for (int i = 0; i < n; ++i) {
        pos[a[i]] = {i, 0};
        pos[b[i]] = {i, 1};
    }
    vector<pair<int, int>> step;
    for (int w = 1; w <= 2 * n; ++w) {
        auto &cur = pos[w];
        pair<int, int> need = {(w - 1) / 2, (w % 2 ? 0 : 1)};
        if (cur.second != need.second) {
            if (need.second == 0) {
                // up
                step.emplace_back(3, cur.first);
                int e = a[cur.first];
                auto aux = pos[e];
                a[cur.first] = w;
                b[cur.first] = e;
                pos[e] = cur;
                cur = aux;
            }
            else {
                // down
                step.emplace_back(3, cur.first);
                int e = b[cur.first];
                auto aux = pos[e];
                b[cur.first] = w;
                a[cur.first] = e;
                pos[e] = cur;
                cur = aux;
            }
        }
        if (cur.first > need.first) {
            while (cur != need) {
                int prv = cur.first - 1;
                int r = need.second;
                int e = (r ? b[prv] : a[prv]);
                auto aux = pos[e];
                if (r == 0) {
                    a[prv] = w;
                    a[cur.first] = e;
                }
                else {
                    b[prv] = w;
                    b[cur.first] = e;
                }
                pos[e] = cur;
                cur = aux;
                step.emplace_back((r == 0 ? 1 : 2), prv);
            }
        }
        else {
            // cur -> need
            while (cur != need) {
                int nxt = cur.first + 1;
                int r = need.second;
                int e = (r == 0 ? a[nxt] : b [nxt]);
                auto aux = pos[e];
                if (r == 0) {
                    a[nxt] = w;
                    a[cur.first] = e;
                }
                else {
                    b[nxt] = w;
                    b[cur.first] = e;
                }
                pos[e] = cur;
                cur = aux;
                step.emplace_back((r == 0 ? 1 : 2), nxt);
            }
        }
    }
    int k = step.size();
    cout << k << "\n";
    for (auto [id, pos] : step)
        cout << id << " "<< pos + 1 << "\n";
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


