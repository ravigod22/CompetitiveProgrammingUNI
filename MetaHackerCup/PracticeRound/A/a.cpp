#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (auto& e : a) cin >> e;
    long long ans = 0;
    if (n == 1) {
        ans = a[0];
        return (ans <= k);
    }
    int mine = *min_element(a.begin(), a.end());
    ans = 1LL * mine * (2LL * n - 3); 
    return (ans <= k);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    for (int i = 1; i <= tt; ++i) {
        cout << "Case #" << i << ": " << (solve() ? "YES" : "NO");
        if (i != tt) cout << "\n";
    }
    return 0;
}

