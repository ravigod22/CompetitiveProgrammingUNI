#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    string s; cin >> s;    
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] != '.') cout << s[i];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    int tt = 1;
    //cin >> tt;
    while(tt--) {
        solve();
    }
    return 0;
}


