#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, q; cin >> n >> q;
    int posL = 0;
    int posR = 1;
    vector<char> pos(n, false);
    pos[0] = 'L';
    pos[1] = 'R';
    int ans = 0;
    for (int j = 0; j < q; ++j) {
        char h; cin >> h;
        int x; cin >> x;
        x--;
        if (h == 'R') {
            bool can = true;
            for (int i = 0; i <= n; ++i) {
                if (pos[(posR + i) % n] == 'L') {
                    can = false;
                    break;
                }
                if ((posR + i) % n == x) {
                    pos[posR] = 'N';
                    ans += i;
                    posR = x;
                    pos[posR] = 'R';
                    break;
                }
            }
            if (can) continue;
            for (int i = 0; i <= n; ++i) {
                if ((posR - i + n) % n == x) {
                    pos[posR] = 'N';
                    ans += i;
                    posR = x;
                    pos[posR] = 'R';
                    break;
                }
            }
        }
        else {
            bool can = true;
            for (int i = 0; i <= n; ++i) {
                if (pos[(posL + i) % n] == 'R') {
                    can = false;
                    break;
                }
                if ((posL + i) % n == x) {
                    pos[posL] = 'N';
                    ans += i;
                    posL = x;
                    pos[posL] = 'L';
                    break;
                }
            }
            if (can) continue;
            for (int i = 0; i <= n; ++i) {
                if ((posL - i + n) % n == x) {
                    pos[posL] = 'N';
                    ans += i;
                    posL = x;
                    pos[posL] = 'L';
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




