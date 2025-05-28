#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int maxn = 1e7;
int lp[maxn + 1];
vector<int> pr;

void precomputation() {
    for (int i = 2; i <= maxn; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= maxn; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

bool f(int pos, vector<int> num) {
    i64 sum = 0;
    for (int i = pos, j = 0; i < num.size(); ++i, ++j) {
        sum += num[i] - pr[j];
    }
    return sum >= 0;
}



void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    sort(a.begin(), a.end());
    int lo = 0;
    int hi = n - 1;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (f(mid, a)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precomputation();
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


