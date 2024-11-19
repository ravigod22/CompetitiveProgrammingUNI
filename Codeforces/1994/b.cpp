#include <bits/stdc++.h>
using namespace std;

bool solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if (s[0] == '0' && t[0] == '1') return false;
    if (s[0] == '1') return true;
    int s0 = n;
    int t0 = n;
    for (int i = 1; i < n; ++i) {
        if (s[i] == '1') {
            s0 = i;
            break;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (t[i] == '1') {
            t0 = i;
            break;
        }
    }
    if (t0 < s0) return false;
    else return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ?  "YES\n" : "NO\n");
    }
    return 0;
}
