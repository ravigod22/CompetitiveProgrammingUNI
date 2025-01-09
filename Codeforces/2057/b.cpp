#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, int> cnt;
    for (int& e : a) {
        cin >> e;
        cnt[e]++;
    }
    vector<pair<int, int>> aux;
    for (auto e : cnt) {
        aux.emplace_back(e.second, e.first);
    }
    sort(aux.begin(), aux.end());
    int ans = 1;
    int res = 0;
    for (int i = 0; i < (int)aux.size(); ++i) {
        if (aux[i].first <= k) {
            res++;
            k -= aux[i].first;
        }
        else break;
    }
    cout << max(ans, (int)aux.size() - res) << "\n";
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


