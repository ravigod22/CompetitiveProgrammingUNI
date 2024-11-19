#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
#define i128 __int128

const int maxn = 1e5 + 5;
vector<int> divi[maxn];

i128 sum(i128 x0, i128 n, i128 r) {
    i128 tmp = ((n - 1) * n) / 2;
    return n * x0 + tmp * r;
}

void init() {
    for (int i = 1; i < maxn; ++i) {
        vector<int> divitmp;
        for (int j = 1; j * j <= i; ++j) {
            if (i % j == 0) {
                divitmp.emplace_back(j);
                if (i / j != j) divitmp.emplace_back(i / j);
            }
        }
        divi[i] = divitmp;
    }
}

void solve() {
    i128 A, S, L, R;
    long long A_ll, S_ll, L_ll, R_ll;
    cin >> A_ll >> S_ll >> L_ll >> R_ll;
    A = A_ll; S = S_ll; L = L_ll; R = R_ll;

    int cnt = 0;
    map<tuple<i128, i128, i128>, int> mp;

    for (i128 i = L; i <= R; ++i) {
        auto pos = [&] (i128 x0, i128 r) -> i128 {
            i128 lo = 1;
            i128 hi = 1e5 + 2;
            while (lo < hi) {
                i128 mid = (lo + hi) / 2;
                if (sum(x0, mid, r) >= S) hi = mid;
                else lo = mid + 1;
            }
            return (sum(x0, lo, r) == S ? lo : -1);
        };

        if (A < i) {
            i128 dis = i - A;
            for (int r : divi[dis]) {
                i128 last = pos(A, r);
                if (last == -1) continue;
                i128 tmp = A + (last - 1) * r;
                if (tmp > R) continue;
                i128 acc = sum(A, last, r);
                assert(acc == S);
                mp[{A, last, r}]++;
            }
        }
        else if (A == i) {
            if (A == S) cnt++;
        }
        else {
            i128 dis = A - i;
            for (int r : divi[dis]) {
                i128 last = pos(i, r);
                if (last == -1) continue;
                i128 tmp = i + (last - 1) * r;
                if (tmp > R) continue;
                if (tmp < A) continue;
                i128 acc = sum(i, last, r);
                assert(acc == S);
                mp[{i, last, r}]++;
            }
        }
    }
    cout << (long long)mp.size() + cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}

