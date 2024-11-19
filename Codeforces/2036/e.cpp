#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int inf = 2e9 + 5;

void solve() {
    int n, k, q; cin >> n >> k >> q;
    int a[n][k];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            a[i][j] |= a[i - 1][j];
        }
    }
    vector<int> L(k, 0);
    vector<int> R(k, inf);
    for (int i = 0; i < q; ++i) {
        int m; cin >> m;
        int ltmp = 0, rtmp = inf;
        set<int> reg;
        for (int j = 0; j < m; ++j) {
            int r, c;
            char op;
            cin >> r >> op >> c;
            r--;
            reg.emplace(r);
            if (op == '<') R[r] = min(R[r], c);
            else L[r] = max(L[r], c);
        }
        for (int e : reg) {
            //dbg(e + 1);
            int lo = 0;
            int hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (L[e] < a[mid][e]) hi = mid;
                else lo = mid + 1;
            }
            //dbg(lo);
            if (L[e] >= a[lo][e]) lo++;
            ltmp = max(ltmp, lo);
            lo = 0;
            hi = n - 1;
            while (lo < hi) {
                int mid = (lo + hi + 1) / 2;
                if (a[mid][e] < R[e]) lo = mid;
                else hi = mid - 1;
            }
            if (a[lo][e] >= R[e]) lo--;
            //dbg(lo);
            rtmp = min(rtmp, lo);
            //dbg(ltmp);
            //dbg(rtmp);
        }
        if (ltmp > rtmp) cout << -1 << "\n";
        else cout << ltmp + 1 << "\n";
        for (int e : reg) {
            L[e] = 0;
            R[e] = inf;
        }
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


