#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<i64> b(n);
    for (auto& e : b) cin >> e;
    vector<pair<int, i64>> mask[20];
    for (int i = 0; i < (1 << n); ++i) {
        int cnt = 0;
        i64 sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cnt++;
                sum += b[j];
            }
        }
        mask[cnt].emplace_back(i, sum);
    }
    return 0;
}



