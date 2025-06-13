#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int mod = 1e9 + 7;
const int N = 1 << 17 + 5;
int n, q;
int a[N];
int T[4 * N];
bool init;

void build(int id = 1, int tl = 0, int tr = (1 << n) - 1, bool op = init) {
    if (tl == tr) {
        T[id] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * id, tl, tm, op ^ 1);
    build(2 * id + 1, tm + 1, tr, op ^ 1);
    if (op) T[id] = (T[2 * id] | T[2 * id + 1]);
    else T[id] = (T[2 * id] ^ T[2 * id + 1]);
}

void update(int pos, int id = 1, int tl = 0, int tr = (1 << n) - 1, bool op = init) {
    if (tl == tr) {
        T[id] = a[pos];
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos > tm) update(pos, 2 * id + 1, tm + 1, tr, op ^ 1);
    else update(pos, 2 * id, tl, tm, op ^ 1);
    if (op) T[id] = (T[2 * id] | T[2 * id + 1]);
    else T[id] = (T[2 * id] ^ T[2 * id + 1]);
}

void solve() {
    cin >> n >> q;
    for (int i = 0; i < (1 << n); ++i) {
        cin >> a[i];
    }
    init = (n & 1 ? 1 : 0);
    build();
    while (q--) {
        int p, b;
        cin >> p >> b;
        p--;
        a[p] = b;
        update(p);
        cout << T[1] << "\n";
    }
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

