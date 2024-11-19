#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int a, b, c; cin >> a >> b >> c;
    int h, w; cin >> h >> w;
    auto f = [&] (int x, int y, int z) -> bool {
        if (2 * (x + z) <= h && 2 * x + y <= w) return true;
        if (2 * (x + z) <= w && 2 * x + y <= h) return true;
        if (2 * (x + z) <= h && x + y + z <= w) return true;
        if (2 * (x + z) <= w && x + y + z <= h) return true;
        if (x + 2 * z + y <= h && 2 * x + y <= w) return true;
        if (x + 2 * z + y <= w && 2 * x + y <= h) return true;
        if (x + y + z <= h && 2 * x + y + z <= w) return true;
        if (x + y + z <= w && 2 * x + y + z <= h) return true;
        if (x + y + z <= h && x + 2 * y + z <= w) return true;
        if (x + y + z <= w && x + 2 * y + z <= h) return true;
        if (2 * x + y + z <= w && 2 * z + y <= h) return true;
        if (2 * x + y + z <= h && 2 * z + y <= w) return true;
        if (3 * y + x + z <= w && x + z <= h) return true;
        if (3 * y + x + z <= h && x + z <= w) return true;
        return false;
    };
    if (f(a, b, c)) return true;
    if (f(a, c, b)) return true;
    if (f(b, a, c)) return true;
    if (f(b, c, a)) return true;
    if (f(c, a, b)) return true;
    if (f(c, b, a)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        cout << (solve() ? "Yes" : "No");
    }
    return 0;
}



