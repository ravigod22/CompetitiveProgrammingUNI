#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i) prefix[i + 1] = prefix[i] + (a[i] > k ? -1 : 1);
    set<int> pre, tmp;
    if (prefix[1] >= 0) pre.insert(prefix[1]);
    tmp.insert(prefix[1]);
    for (int i = 2; i + 1 <= n; ++i) {
        if (prefix[n] >= prefix[i]) {
            auto it = tmp.upper_bound(prefix[i]);
            if (it != tmp.begin()) return true;
            auto it2 = pre.lower_bound(0);
            if (it2 != pre.end()) return true;
        }
        else {
            auto it = pre.upper_bound(prefix[i]);
            if (it != pre.begin()) return true;
        }
        tmp.insert(prefix[i]);
        if (prefix[i] >= 0) pre.insert(prefix[i]);
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
    return 0;
}


