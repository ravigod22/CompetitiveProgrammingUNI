#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int k; cin >> k;
    vector<int> cnt(k + 1, 0);
    vector<int> a(k);
    int e = k - 2;
    for (int i = 0; i < k; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 1; i <= e; ++i) {
        if (e % i == 0) {
            if (cnt[i] && cnt[e / i]) {
                cout << i << " " << e / i << "\n";
                return;
            }        
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




