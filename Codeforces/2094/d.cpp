#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    string s, p; cin >> p >> s;
    vector<int> repes, repep;
    for (int i = 0; i < s.size(); ) {
        char cur = s[i];
        int cnt = 0;
        while (i < s.size() && cur == s[i]) cnt++, i++;
        repes.push_back(cnt);
    }
    for (int i = 0; i < p.size(); ) {
        char cur = p[i];
        int cnt = 0;
        while (i < s.size() && cur == p[i]) cnt++, i++;
        repep.push_back(cnt);
    }
    if (s.front() != p.front()) return false;
    if (repes.size() != repep.size()) return false;
    for (int i = 0; i < repep.size(); ++i) {
        int times = repep[i];
        if (times > repes[i]) return false;
        if (repes[i] > 2 * times) return false;
    }
    return true;
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


