#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    i64 W; cin >> W;
    vector<i64> v(n), w(n);
    for (int i = 0; i < n; ++i) cin >> v[i] >> w[i];
    int p1 = n / 2, p2 = (n + 1) / 2;
    vector<pair<i64, i64>> left, right;
    for (int i = 0; i < (1 << p1); ++i) {
        i64 sumW = 0, sumV = 0;
        for (int j = 0; j < p1; ++j) {
            if ((i >> j) & 1) {
                sumW += w[j];
                sumV += v[j];
            }
        }
        left.emplace_back(sumW, sumV);
    }
    for (int i = 0; i < (1 << p2); ++i) {
        i64 sumW = 0, sumV = 0;
        for (int j = 0; j < p2; ++j) {
            if ((i >> j) & 1) {
                sumW += w[p1 + j];
                sumV += v[p1 + j];
            }
        }
        right.emplace_back(sumW, sumV);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 1; i < right.size(); ++i) {
        right[i].second = max(right[i].second, right[i - 1].second);
    }
    i64 res = 0;
    for (int i = 0, j = right.size() - 1; i < left.size(); ++i) {
        while (j > 0 && left[i].first + right[j].first > W) j--;
        if (left[i].first + right[j].first <= W) {
            res = max(res, left[i].second + right[j].second);
        }
    }
    cout << res << "\n";
    return 0;
}
