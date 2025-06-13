#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n;
    cin >> n;
    int l = 0;
    int h = n - 1;
    int num = 1;
    vector<int> res(n);
    while (l <= h) {
        if (l == h) {
            res[l] = num;
            break;
        }
        res[l] = num++;
        res[h] = num++;
        l++, h--;
    } 
    for (int i = 0; i < n; ++i) cout << res[i] << " \n"[i + 1 == n];
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


