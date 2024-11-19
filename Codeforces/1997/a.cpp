#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        vector<pair<char, int>> times;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int cnt = 0;
            while (s[i] == tmp && i < n) {
                ++cnt;
                ++i;
            }
            times.emplace_back(tmp, cnt);
        }
        int tmp = -1;
        int id = -1;
        for (int i = 0; i < times.size(); ++i) {
            if (times[i].second > tmp) {
                tmp = times[i].second;
                id = i;
            }
        }
        if (tmp == 1) {
            s += (s[n - 1] == 'z' ? 'a' : s[n - 1] + 1);
            cout << s << "\n";
            continue;
        }
        string ans;
        for (int i = 0; i < times.size(); ++i) {
            if (i == id) {
                ans += times[i].first;
                ans += (times[i].first == 'z' ? 'a' : times[i].first + 1);
                for (int j = 1; j < times[i].second; ++j) ans += times[i].first;
            }
            else {
                for (int j = 0; j < times[i].second; ++j) ans += times[i].first;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
