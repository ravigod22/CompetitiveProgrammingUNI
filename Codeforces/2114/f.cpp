#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl
const int N = 1e6 + 5;
vector<int> divi[N];

void init() {
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            divi[j].push_back(i);
}

int distance(int E, int k) {
    vector<int> dis(divi[E].size(), -1);
    dis[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
        int current = divi[E][pos];
        for (int i = pos + 1; i < divi[E].size(); ++i) {
            int nt = divi[E][i];
            if (nt % current || nt / current > k) continue;
            if (dis[i] == -1) {
                dis[i] = 1 + dis[pos];
                q.push(i);
            }
        }
    }
    return dis.back();
}


void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    int d1 = x / gcd(x, y);
    int d2 = y / gcd(x, y);
    int A = distance(d1, k);
    int B = distance(d2, k);
    if (A == -1 || B == -1) cout << -1 << "\n";
    else cout << A + B << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



