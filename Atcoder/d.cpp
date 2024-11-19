#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t; cin >> n >> t;
    string s; cin >> s;
    vector<int> x(n);
    for (int& e : x) cin >> e;
    vector<long long> pos;
    vector<long long> neg;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') pos.emplace_back(x[i]);
        else neg.emplace_back(x[i]);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    long long cnt = 0;
    for (int i = 0; i < pos.size(); ++i) {
        auto r = upper_bound(neg.begin(), neg.end(), t + t + pos[i]);
        auto l = lower_bound(neg.begin(), neg.end(), pos[i]);
        cnt += 1ll * (r - l);
    }
    cout << cnt << "\n";
    return 0;
}
