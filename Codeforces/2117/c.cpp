#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    int cnt = 1;
    set<int> carry, finded;
    carry.insert(a[0]);
    set<int> bag = carry;
    for (int i = 1; i < n; ) {
        while (i < n && !carry.empty()) {
            int cur = a[i];
            if (carry.count(cur)) carry.extract(cur);
            else finded.insert(cur);
            i++;
        }
        if (carry.empty()) cnt += 1;
        for (int e : finded) bag.insert(e);
        finded.clear();
        carry = bag;
    }
    cout << cnt << "\n";
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


