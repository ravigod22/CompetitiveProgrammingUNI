#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n; cin >> n;
    if (n <= 4) {
        cout << "-1\n";
        return;
    }
    vector<int> a[2];
    for (int i = 1; i <= n; ++i) {
        a[i % 2].emplace_back(i);   
    }
    int l1 = a[1].size();
    int l2 = a[0].size();
    int id4 = find(a[0].begin(), a[0].end(), 4) - a[0].begin();
    int id5 = find(a[1].begin(), a[1].end(), 5) - a[1].begin(); 
    swap(a[0][id4], a[0].back());
    swap(a[1][id5], a[1].front());
    for (int e : a[0]) cout << e << " ";
    for (int e : a[1]) cout << e << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




