#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> one;
    one.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') one.emplace_back(i + 1);
    }
    one.emplace_back(n + 1);
    int ans = 0;
    int interval = 2 * k + 1;
    for (int i = 1; i < (int)one.size(); ++i) {
        int dis = one[i] - one[i - 1] - 1;
        if (one[i - 1] == 0 && one[i] == n + 1) {
            ans += (dis + interval - 1) / interval;
        }
        else if (one[i - 1] == 0 && one[i] < n + 1) {
            if (dis <= k) continue;
            else {
                dis -= k;
                ans += (dis + interval - 1) / interval;
            }
        }
        else if (one[i - 1] && one[i] == n + 1) {
            if (dis <= k) continue;
            else {
                dis -= k;
                ans += (dis + interval - 1) / interval;
            }
        }
        else {
            if (dis <= 2 * k) continue;
            else {
                dis -= 2 * k;
                ans += (dis + interval - 1) / interval;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}



