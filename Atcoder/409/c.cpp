#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<int> d(n - 1);
    for (int& e : d) cin >> e;
    vector<int> cnt(l);
    int init = 0;
    cnt[0] = 1;
    for (int e : d) {
        init = (init + e) % l;
        cnt[init] += 1;
    }
    long long ans = 0;
    if (l % 3 == 0) {
        int dis = l / 3;
        for (int i = 0; i < dis; ++i) {
            int a = cnt[i], b = cnt[i + dis], c = cnt[i + 2 * dis];
            ans += 1LL * a * b * c;
        }
    }
    cout << ans << "\n";
    return 0;
}
