#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    //cin >> tt;
    while (tt--) {
        int n, q; cin >> n >> q;
        map<pair<int,int>, bool> follow;
        for (int i = 0; i < q; ++i) {
            int t, a, b; cin >> t >> a >> b;
            pair<int, int> tmp = {a, b};
            if (t == 1) {
                if (follow[tmp]) continue;
                follow[tmp] = true;
            }
            else if (t == 2) {
                follow[tmp] = false;
            }
            else {
                pair<int ,int> vice = {b, a};
                if (follow[tmp] && follow[vice]) cout << "Yes\n";
                else cout << "No\n";
            }
        }
    }
    return 0;
}

