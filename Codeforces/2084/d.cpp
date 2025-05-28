#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, m, k; cin >> n >> m >> k;
    auto f = [&] (int blocks) -> bool {
        vector<int> a(n);
        for (int i = 0; i < blocks; ++i) {
            for (int j = i; j < n; j += blocks) {
                a[j] = i;
            }
        }
        int maxe = blocks - 1;
        vector<bool> vis(n, false);
        set<int> mext;
        for (int i = 0; i < blocks + 10; ++i) mext.insert(i);
        int boxs = 0;
        for (int i = n - 1; i >= 0; ) {
            if (a[i] == maxe) {
                int cnt = 0;
                while (i >= 0 && cnt < k && boxs < m) {
                    vis[i] = true;
                    cnt++;
                    i--;
                }
                if (cnt == 0) i--;
                boxs++;
            }
            else i--;
        }
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            mext.erase(a[i]);
        }
        return *mext.begin() == blocks;
    };
    int lo = 1;
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    vector<int> ans(n);
    int boxes = lo;
    for (int i = 0; i < boxes; ++i) {
        for (int j = i; j < n; j += boxes) {
            ans[j] = i;
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i + 1 == n];
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


