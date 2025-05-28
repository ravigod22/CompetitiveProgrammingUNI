#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int a, b, c; cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum % 3) return false;
    int eq = sum / 3;
    if (b > eq) return false;
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


