#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int mod = 1e9 + 7;
const int maxn = 2e5 + 5;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}

int binpow(int a, int e) {
    int res = 1;
    while (e) {
        if (e & 1) res = mul(res, a);
        a = mul(a, a);
        e /= 2;
    }
    return res;
}

int inverse(int x) {
    return binpow(x, mod - 2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ) {
            int cur = a[i];
            int cnt = 0;
            while (i < n && cur == a[i]) i++, cnt++;
            v.emplace_back(cur, cnt);
        }
        int ans = 0, p = 0, aux = 1;
        for (int i = 0; i < (int)v.size(); ++i) {
            while (p < (int)v.size() && v[p].first - v[i].first < m) {
                aux = mul(aux, v[p].second);
                p++;
            }
            int dis = p - i;
            if (dis == m) {
                ans = add(ans, aux);
            }
            aux = mul(aux, inverse(v[i].second));
        }
        cout << ans << "\n";
    }
    return 0;
}
