#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = long long;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> x(n);
        for (auto &[a, b] : x) cin >> a >> b;
        sort(x.begin(), x.end());
        i64 ans = 0;
        ordered_set os;
        for (auto [l, r] : x) {
            ans += 0LL + os.size() - os.order_of_key(r);
            os.insert(r);
        }
        cout << ans << "\n";
    }
    return 0;
}
