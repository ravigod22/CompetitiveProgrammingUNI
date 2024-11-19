#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

int n, q;

void solve() {
    cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    vector<bool> flip(n, false);
    vector<tuple<int, int, int>> op;
    for (int i = 0; i < q; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int ind, x; cin >> ind >> x;
            op.emplace_back(t, ind, x);
        } 
        else {
            int x; cin >> x;
            op.emplace_back(t, -1, x);
        }
    }
    bool change = false;
    bool reset = false;
    int aux = 0;
    for (int i = 0; i < q; ++i) {
        int t, ind, x;
        tie(t, ind, x) = op[i];
        vector<pair<int, int>> tmp;
        while (i < q && t == 1) {
            tmp.emplace_back(ind - 1, x);
            ++i;      
            if (i == q) break;
            tie(t, ind, x) = op[i];
        }
        if (change) {
            for (auto e : tmp) {
                a[e.first] = aux;
            }
            change = false;
        }
        for (auto e : tmp) {
            sum += 0LL + e.second - a[e.first];
            a[e.first] = e.second;
            cout << sum << "\n";
        }
        if (i == q) break;
        sum = 1LL * x * n;
        cout << sum << "\n";
        change = true;
        aux = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}

