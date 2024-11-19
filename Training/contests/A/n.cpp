#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 2e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        s = "1" + s;
        s += "1";
        vector<int> a(n + 2);
        a[0] = -inf;
        a[n + 1] = inf;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> intervals;
        for (int i = 0; i < a.size(); ++i) {
            if (s[i] == '1') intervals.emplace_back(i);
        }
        i64 sum = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            int x = intervals[i];
            int y = intervals[i - 1];
            vector<int> e;
            for (int j = y + 1; j <= x; ++j) e.emplace_back(a[j] - a[j - 1]); 
            int maxe = *max_element(e.begin(), e.end());
            i64 tmp = accumulate(e.begin(), e.end(), 0LL);
            sum += tmp + 0LL - maxe;
        }
        cout << sum << "\n";
    }
    return 0;
}
