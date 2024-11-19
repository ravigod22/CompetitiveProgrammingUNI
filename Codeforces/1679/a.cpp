#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

long long n;

void solve() {
    cin >> n;
    if (n & 1) {
        cout << -1 << "\n";
        return;
    } 
    n /= 2;
    if (n < 2) {
        cout << -1 << "\n";
        return;
    }
    long long mine = 0;
    long long maxe = 0;
    if (n % 3 == 0) mine = n / 3;
    else if (n % 3 == 1) mine = max((n / 3) - 1, 0LL) + 2;
    else mine = n / 3 + 1;
    if (n % 2) maxe = max((n / 2) - 1, 0LL) + 1;
    else maxe = n / 2;
    cout << mine << " " << maxe << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}
