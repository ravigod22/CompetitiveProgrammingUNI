#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, d, k; cin >> n >> d >> k;
    vector<pair<int, int>> in;
    vector<pair<int, int>> out;
    vector<pair<int, int>> job(k);
    for (int i = 0; i < k; ++i) {
        int l, r; cin >> l >> r;
        in.emplace_back(l, i);
        out.emplace_back(r, i);
    }
    sort(in.begin(), in.end());
    sort(out.begin(), out.end());
    int cnt = 0;
    int p = 0;
    int q = 0;
    int mom = 1e9, bro = 0;
    int dmom = -1, dbro = -1;
    set<int> idx;
    for (int i = 1; i <= n; ++i) {
        while (p < k && in[p].first == i) {
            idx.emplace(in[p].second);
            cnt++;
            ++p;
        }
        while (q < k && out[q].first == i - d) {
            idx.erase(out[q].second);
            cnt--;
            q++;
        }
        if (i >= d && cnt < mom) {
            mom = cnt;
            dmom = i - d + 1;
        }
        if (i >= d && bro < cnt) {
            bro = cnt;
            dbro = i - d + 1;
        }
    }
    cout << dbro << " " << dmom << "\n";
}  

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}


