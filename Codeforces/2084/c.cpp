#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    vector<int> pos_a(n + 1), pos_b(n + 1);
    int cnt_equal = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == b[i]) cnt_equal += 1;
    }
    for (int i = 0; i < n; ++i) {
        pos_a[a[i]] = i;
        pos_b[b[i]] = i;
    }
    if (n & 1) {
        if (cnt_equal != 1) {
            cout << -1 << "\n";
            return;
        }
    }
    if (n % 2 == 0) {
        if (cnt_equal != 0) {
            cout << -1 << "\n";
            return;
        }
    }
    vector<pair<int, int>> op;
    auto change = [&] (int posa, int posb, int pos_to_a, int pos_to_b) -> void {
        int fromA = a[posa];
        int fromB = b[posb];
        int toA = a[pos_to_a];
        int toB = b[pos_to_b];
        swap(a[posa], a[pos_to_a]);
        swap(b[posb], b[pos_to_b]);
        pos_a[fromA] = pos_to_a;
        pos_b[fromB] = pos_to_b;
        pos_a[toA] = posa;
        pos_b[toB] = posb;
    };
    if (n & 1) {
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {
                if (pos_a[a[i]] == n / 2) continue;
                change(i, i, n / 2, n / 2);
                op.emplace_back(i, n / 2);
            }
        }
    }
    for (int i = 0; i < n / 2; ++i) {
        // a[i] , b[i]
        int find_a = b[i];
        int find_b = a[i];
        if (pos_a[find_a] != pos_b[find_b]) {
            cout << -1 << "\n";
            return;
        }
        if (pos_a[find_a] == n - i - 1) continue;
        op.emplace_back(pos_a[find_a], n - i - 1);
        change(pos_a[find_a], pos_b[find_b], n - i - 1, n - i - 1);
    }
    cout << op.size() << "\n";
    for (auto [p1, p2] : op) {
        assert (p1 != p2);
        cout << min(p1, p2) + 1 << " " << max(p1, p2) + 1 << "\n";
    }
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


