#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    map<string, int> cnt;
    map<string, bool> exist;
    string s[n];
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    for (int i = 0; i < n; ++i) {
        if (exist.count(s[i])) {
            cout << s[i] << "(" << cnt[s[i]] << ")\n";
            cnt[s[i]]++;
        }
        else {
            cout << s[i] << "\n";
            exist[s[i]] = true;
            cnt[s[i]] = 1;
        }
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


