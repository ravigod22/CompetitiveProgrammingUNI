#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    map<int, int> mp;
    do {
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += lcm(i + 1, p[i]);    
        }
        mp[ans]++;
        if (ans == 137) {
            for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i + 1 == n];
        }
    } while (next_permutation(p.begin(), p.end()));
    int maxe = 0;
    for (auto [v, k] : mp) {
        maxe = max(maxe, v);
    }
    cout << maxe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



