#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int maxn = 1e7 + 5;
int id[maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> classes(m);
    for (int i = 0; i < m; ++i) {
        cin >> classes[i];
    }
    vector<int> tmp = classes;
    sort(tmp.begin(), tmp.end());
    int l = 0, r = m - 1;
    vector<int> ans(n);
    vector<int> rev(n);
    int p = 0, q = n - 1;
    int cnt = n;
    while (cnt > 0) {
        if (cnt == 1) {
            ans[p] = tmp[l];
            rev[q] = tmp[r];
            break;
        }
        ans[p] = tmp[l];
        ans[q] = tmp[r];
        rev[p] = tmp[r];
        rev[q] = tmp[l];
        p++, l++;
        q--, r--;
        cnt -= 2;
    }
    // pv(ans);
    // pv(rev);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << ans[i] << " " << rev[i] << " ";
        }
        cout << "\n";
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


