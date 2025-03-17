#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int maxn = 1e5;

vector<pair<int, int>> divi(int x) {
    vector<pair<int, int>> d;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i) continue;
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        d.emplace_back(i, cnt);
    }
    if (x > 1) d.emplace_back(x, 1);
    return d;
}

int main() {
    for (int i = 1; i <= maxn; ++i) {
        auto f = divi(i);
        auto s = divi(i + 1);
        map<int, int> total;
        for (auto[pr, times] : f) {
            total[pr] += times;
        }
        for (auto[pr, times] : s) {
            total[pr] += times;
        }
        total[2]--;
        int tdivi = 1;
        for (auto [pr, times] : total) tdivi *= (times + 1);
        if (tdivi > 500) {
            cout << 1LL * i * (i + 1) / 2 << "\n";
            break;
        }
    }
    return 0;
}
