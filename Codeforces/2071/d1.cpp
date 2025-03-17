#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 2e5 + 5;
int n;
int a[maxn];
int prefix[maxn];

int f(i64 x) {
    if (x <= n) return a[x];
    i64 mid = x / 2;
    if (mid <= n) return prefix[mid];
    int ans = prefix[n];
    if (x % 2 == 0) ans ^= f(x);
    return ans;
}


void solve() {
    cin >> n;
    i64 l, r; cin >> l >> r;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i - 1] ^ a[i];
    }
    if (n % 2 == 0) {
        n++;
        a[n] = prefix[n / 2];
        prefix[n] = prefix[n - 1] ^ a[n / 2];
    }
    cout << f(l) << "\n";
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




