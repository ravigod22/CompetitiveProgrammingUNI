#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cntB = count(s.begin(), s.end(), 'B');
    int cntA = n - cntB;
    if (s[0] == 'A' && s[n - 1] == 'A') return true;
    if (s[0] == 'B' && s[n - 1] == 'B') return false;
    if (s[0] == 'A' && s[n - 1] == 'B') {
        if (n == 2) return true;
        if (cntB == 1) return true;
        else return false;
    }
    else if (s[0] == 'B' && s[n - 1] == 'A') {
        if (n == 2) return false;
        if (s[n - 2] == 'A') return true;
        else return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "Alice" : "Bob") << "\n";
    }
    return 0;
}


