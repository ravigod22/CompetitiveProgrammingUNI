#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    set<int> s;
    for (int i = 1; i <= 2 * n + 1; ++i) s.emplace(i);
    for (int i = 0; i < n + 1; ++i) {
        int tmp = *s.begin();
        s.erase(s.begin());
        cout << tmp << endl;
        int x; cin >> x;
        if (x != 0) {
            s.erase(x);
        }
        else break;
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

