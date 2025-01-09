#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n; cin >> n;
    string s; cin >> s;
    int cntdot = count(s.begin(), s.end(), '.');
    int cnts = count(s.begin(), s.end(), 's');
    int cntp = count(s.begin(), s.end(), 'p');
    if (cntdot == n || cnts == n || cntp == n) return true;
    if (cntp == 0 || cnts == 0) return true;
    vector<int> per(n);
    iota(per.rbegin(), per.rend(), 1);
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'p') {
            set<int> p;
            for (int j = i; j >= 0; --j) {
                p.emplace(per[j]);
            }
            int aux = 0;
            for (int e : p) {
                if (e == aux + 1) aux++;
            }
            if (aux < p.size()) return false;
        }
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


