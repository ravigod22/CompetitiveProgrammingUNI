#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    map<int, int> have;
    vector<int> object;
    for (auto x : a) {
        if (x < 0) {
            x = abs(x);
            if (have[x] >= 1) have[x]--;
            else {
                if (cnt >= 1) { 
                    cnt--;
                    object.emplace_back(x);
                }
                else {
                    cout << "No";
                    return;
                }
            }
        }
        else if (x == 0) {
            cnt++;
        }
        else {
            have[x]++;
        }
    }
    while (cnt--) object.emplace_back(1);
    cout << "Yes\n";
    for (auto e : object) cout << e << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    //cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



