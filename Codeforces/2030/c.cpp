#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (s.back() == '1' || s[0] == '1') return true;
    for (int i = 0; i < n; ) {
        char tmp = s[i];
        int cnt = 0;
        while (i < n && tmp == s[i]) cnt++, i++;
        if (tmp == '1') {
            if (cnt > 1) return true;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}

