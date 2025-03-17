#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> used(27, 0);
    bool can = true;
    for (int i = 0; i < n; ) {
        char tmp = s[i];
        while (i < n && tmp == s[i]) i++;
        if (used[tmp - 'A']) {
            can = false;
            break;
        }
        else {
            used[tmp - 'A'] = 1;
        }
    }
    cout << (can ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


