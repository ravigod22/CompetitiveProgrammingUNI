#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int cnt = count(a.begin(), a.end(), 1);
    if (cnt == n) return false;
    for (int i = 1; i < n; ++i) {
        if (a[i] == a[i - 1] && a[i] == 0) return false;
    } 
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "NO" : "YES") << "\n";
    }
    return 0;
}
