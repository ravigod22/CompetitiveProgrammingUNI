#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 gdc(i64 a, i64 b) {
    return b ? gcd(b, a % b) : a;
}

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int n; cin >> n;
    vector<i64> a(n);
    for (auto& e : a) cin >> e;
    i64 mine = *min_element(a.begin(), a.end());
    if (n == 2) {
        return a[0] == a[1];
    }
    i64 cnt = count(a.begin(), a.end(), mine);
    if (cnt > 1) return true;
    vector<i64> tmp;
    for (int i = 0; i < n; ++i) {
        if (a[i] == mine) continue;
        if (gcd(mine, a[i]) == mine) tmp.push_back(a[i] / mine);
    }
    if (tmp.size() < 2) return false;
    bool exist = false;
    i64 aux = tmp[0];
    for (int i = 1; i < tmp.size(); ++i) {
        aux = gcd(aux, tmp[i]);
    }
    return aux == 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes" : "No") << "\n";
    }
    return 0;
}


