#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
#define i128 __int128

const int maxn = 1e5 + 5;
vector<int> divi[maxn];

i128 sum(long long x0, long long n, long long r) {
    long long tmp = ((n - 1) * n )/ 2;
    return (i128)n * x0 + (i128)tmp * r;
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
    long long A, S, L, R;
    cin >> A >> S >> L >> R;
    int cnt = 0;
    map<tuple<long long, long long, long long>, int> mp;
    for (long long i = L; i <= R; ++i) {
        auto pos = [&] (long long x0, long long r) -> long long {
            long long lo = 1;
            long long hi = 1e5 + 2;
            while (lo < hi) {
                long long mid = (lo + hi) / 2;
                if (sum(x0, mid, r) >= (i128)S) hi = mid;
                else lo = mid + 1;
            }
            return (sum(x0, lo, r) == (i128)S ? lo : -1);
        };
        if (A < i) {
            long long dis = i - A;
            for (int r : divi[dis]) {
                long long last = pos(A, r);
                if (last == -1) continue;
                long long tmp = A + (last - 1) * r;
                if (tmp > R) continue;
                long long acc = sum(A, last, r);
                assert(acc == S);
                mp[{A, last, r}]++;
            }
        }
        else if (A == i) {
            if (A == S) cnt++;
        }
        else {
            long long dis = A - i;
            for (int r : divi[dis]) {
                long long last = pos(i, r);
                if (last == -1) continue;
                long long tmp = i + (last - 1) * r;
                if (tmp > R) continue;
                if (tmp < A) continue;
                long long acc = sum(i, last, r);
                assert(acc == S);
                mp[{i, last, r}]++;
            }
        }
    }
    cout << mp.size() + cnt << "\n";
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




