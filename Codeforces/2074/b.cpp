#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    multiset<int> a;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        a.insert(x);
    }
    while (a.size() != 1) {
        int f = *a.begin();
        a.erase(a.begin());
        int s = *a.begin();
        a.erase(a.begin());
        a.insert(f + s - 1);
    }
    cout << *a.begin() << "\n";
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


