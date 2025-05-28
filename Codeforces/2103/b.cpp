#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> repe;
    for (int i = 0; i < n; ) {
        char cur = s[i];
        int cnt = 0;
        while (i < n && cur == s[i]) i++, cnt++;
        repe.push_back(cnt);
    }
    if (repe.size() == 1) {
        cout << (s.front() == '1' ? 1 : 0) + n << "\n";
        return;
    }
    else if (repe.size() == 2) {
        cout << n + 1 << "\n";
        return;
    }
    else if (repe.size() == 3) {
        cout << n + 1 << "\n";
    }
    else cout << n + repe.size() - 2 + (s.front() == '0' ? -1 : 0) << "\n";
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


