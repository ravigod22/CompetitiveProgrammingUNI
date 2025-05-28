#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


bool solve() {
    int x, k; cin >> x >> k;
    bool xprime = (x == 1 ? false : true);
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) xprime = false;
    }
    if (xprime) {
        return k == 1;
    }
    else {
        if (x == 1) {
            int s = 0;
            for (int i = 0; i < k; ++i) {
                s = s * 10 + 1;
            }
            bool kprime = (s == 1 ? false : true);
            for (int j = 2; j * j <= s; ++j) {
                if (s % j == 0) kprime = false;
            }
            return kprime;
        }
        else return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}


