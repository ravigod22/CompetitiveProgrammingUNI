#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> b = a;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1) {
        cout << 0 << "\n";
        return;
    }
    i64 sumin = 0, sumax = 0;
    vector<int> vis(n, true);
    int p = 30, findbit = 1;
    int best = 0;
    while (true) {
        vector<pair<int, int>> aux;
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) continue;
            bool found = false;
            for (int k = p + 1; k >= 0; --k) {
                int bit = ((a[i] >> k) & 1 ? 1 : 0);
                if (bit == findbit) {
                    aux.emplace_back(i, k);
                    last = max(last, k);
                    found = true;
                    break;
                }
            }
            if (!found) vis[i] = false;
        }
        int cnt = 0;
        for (auto [id, lb] : aux) {
            if (lb != last) vis[id] = false;
            else cnt++;
        }
        if (cnt == 1) {
            for (auto [id, lb] : aux) {
                if (!vis[id]) continue;
                best = a[id];
            }
            break;
        }
        if (aux.empty()) break;
        cout << "hola\n";
        p = last;
        findbit ^= 1;
    }
    cout << best << "\n";
    i64 res = 0;
    for (int e : b) {
        res += best ^ e;
    }
    cout << res << "\n";
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


