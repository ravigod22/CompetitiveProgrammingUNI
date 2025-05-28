#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

i64 f(i64 x, i64 y, i64 n) {
    if (n == 1) return 1;
    // 1 -> 2 ^ n - 2
    if (x <= n / 2 && y <= n / 2) {
        return f(x, y, n / 2);
    }
    else if (x <= n && y <= n / 2) {
        return (n * n) / 2 + f(x - n / 2, y, n / 2);
    }
    else if (x <= n / 2 && y <= n) {
        return (n * n) / 2 + (n * n) / 4 + f(x, y - n / 2, n / 2);
    }
    else return (n * n) / 4 + f(x - n / 2, y - n / 2 , n / 2);
}


pair<i64, i64> add(pair<i64, i64> a, pair<i64, i64> b) {
    return {a.first + b.first, a.second + b.second};
}

pair<i64, i64> g(i64 d, i64 n) {
    if (n == 2) {
        if (d == 1) return {0, 0};
        else if (d == 2) return {1, 1};
        else if (d == 3) return {1, 0};
        else return {0, 1};
    }
    if (d <= (n * n) / 4) {
        return g(d, n / 2);
    }
    else if (d <= ((n * n) / 2) + ((n * n) / 4)) {
        return add({n / 2, 0}, g(d - ((n * n) / 2), n / 2));
    }
    else if (d <= (n * n)) {
        return add({0, n / 2}, g(d - ((n * n) / 2 + (n * n) / 4), n / 2));
    }
    else {
        return add({n / 2, n / 2}, g(d - (n * n) / 4, n / 2)); 
    }
}

void solve() {
    i64 n; cin >> n;
    int q; cin >> q;
    while (q--) {
        char op[2];
        cin >> op[0] >> op[1];
        if (op[0] == '-') {
            i64 x, y; cin >> x >> y;
            cout << f(x, y, 1LL << n) << "\n";
        }
        else {
            i64 d; cin >> d;
            auto [x, y] = g(d, 1LL << n);
            cout << x + 1 << " " << y + 1 << "\n";
        }
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


