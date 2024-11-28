#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        int sum = 0;
        int cntL = 0;
        vector<pair<char, int>> cnt;
        for (int i = 0; i < n; ) {
            char tmp = s[i];
            int aux = 0;
            while (i < n && tmp == s[i]) {
                ++i;
                aux++;
            }
            if (tmp == 'W') sum += 2 * aux - 1;
            else cntL += aux;
            cnt.emplace_back(tmp, aux);
        }
        if (cnt.size() == 1 && cntL > 0) {
            cout << max(0, 2 * k - 1) << "\n";
            continue;
        }
        multiset<int> times;
        for (int i = 1; i + 1 < cnt.size(); ++i) {
            if (cnt[i].first == 'W') continue;
            times.emplace(cnt[i].second);
        }
        while (!times.empty() && *times.begin() <= k) {
            k -= *times.begin();
            cntL -= *times.begin();
            sum += 2 * (*times.begin()) + 1;
            times.erase(times.begin());
        }
        int remain = min(k, cntL);
        sum += 2 * remain;
        cout << sum << "\n";
    }
    return 0;
}
