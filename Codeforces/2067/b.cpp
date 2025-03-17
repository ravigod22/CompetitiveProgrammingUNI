#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n; cin >> n;
    vector<int> cnt(2 * n + 1, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 1) return 0;
        cnt[i + 1] += max(0, cnt[i] - 2);
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes" : "No") << "\n";
    }
    return 0;
}



