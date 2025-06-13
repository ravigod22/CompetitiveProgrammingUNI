#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};


void solve() {
    int n;
    cin >> n;
    vector<int> vis(n, 0);
    vis[0] = 1;
    int init = 0;
    for (int i = 1; i < n; ++i) {
        init = (init + i) % n;
        vis[init] = 1;
    }
    int cnt = count(vis.begin(), vis.end(), 0);
    if (cnt) {
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) cout << i + 1 << " ";
        }        
    }
    else cout << "NONE";
    cout << endl;
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


