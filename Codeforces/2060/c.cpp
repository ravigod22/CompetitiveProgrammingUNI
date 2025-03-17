#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> cnt(2 * n + 1, 0);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    int pos = 0;
    int remain = 0;
    for (int i = 1; i <= k / 2; ++i) {
        if (2 * i == k) {
            int aux = cnt[i] / 2;
            pos += cnt[i] / 2;
            remain += cnt[i] - 2 * aux;
        }
        else {
            pos += min(cnt[i], cnt[k - i]);
            remain += abs(cnt[i] - cnt[k - i]);
        }
    }
    cout << pos << "\n";
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


