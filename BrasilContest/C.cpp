#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define eb emplace_back
#define ff first
#define ss second

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    int n,m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        int B,G;
        cin >> B >> G;
        vector<array<int,3>> r(n);
        for (int i = 0; i < n; i++) {
            r[i][0] = abs(a[i] - G);
            r[i][1] = i;
            r[i][2] = a[i];
        }
        sort(all(r));
        for (int i = 0; i < B; i++) cout << r[i][2] << " ";
        cout << '\n';

        r.resize(m);

        for (int i = 0; i < m; i++) {
            r[i][0] = abs(b[i] - G);
            r[i][1] = i;
            r[i][2] = b[i];
        }
        sort(all(r));
        for (int i = 0; i < B; i++) cout << r[i][2] << " ";
        cout << '\n';

    }
    return 0;
}

