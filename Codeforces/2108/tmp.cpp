#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    vector<int> ans;
    do {
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += abs(p[i] - (i + 1));
        }
        ans.push_back(sum);
    } while (next_permutation(p.begin(), p.end())); 
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    for (int e : ans) cout << e << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


