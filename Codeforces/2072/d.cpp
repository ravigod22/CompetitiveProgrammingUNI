#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 2e3 + 100;
int a[maxn];
int mine[maxn][maxn];
int maxe[maxn][maxn];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int inversion = 0;
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = i + 1; j < n; ++j) {
            cnt += (a[i] > a[j]);
        }
        inversion += cnt;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mine[i][j + 1] = mine[i][j] + (a[j] < a[i]);
            maxe[i][j + 1] = maxe[i][j] + (a[i] < a[j]);
        }
    }
    int ansL = 0, ansR = 0;
    int res = inversion;
    for (int l = 0; l + 1 < n; ++l) {
        for (int r = l + 1; r < n; ++r) {
            int inver = inversion;
            int morethan = maxe[l][r + 1] - maxe[l][l];
            int lessthan = mine[l][r + 1] - mine[l][l];
            int sumtotal = inver + morethan - lessthan;
            if (sumtotal < res) {
                res = sumtotal;
                ansL = l;
                ansR = r;
            }
        }
    }
    cout << ansL + 1 << " " << ansR + 1 << "\n";
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


