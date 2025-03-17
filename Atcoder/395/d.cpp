#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, q; cin >> n >> q;
    vector<int> par(n, 0), id(n, 0), inver(n, 0);
    set<int> pos[n];
    for (int i = 0; i < n; ++i) {
        pos[i].insert(i);
        par[i] = id[i] = inver[i] = i;
    }
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int a, b; cin >> a >> b;
            a--, b--;
            int cur = par[a];
            int to = inver[b];
            pos[cur].erase(a);
            pos[to].insert(a);
            par[a] = to;
        }
        else if (op == 2) {
            int a, b; cin >> a >> b;
            a--, b--;
            int pa = inver[a];
            int pb = inver[b];
            swap(id[pa], id[pb]);
            inver[id[pa]] = pa;
            inver[id[pb]] = pb;
        }
        else if (op == 3) {
            int a; cin >> a;
            a--;
            cout << id[par[a]] + 1 << "\n";
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

