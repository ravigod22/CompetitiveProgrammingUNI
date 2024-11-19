#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, f, k; cin >> n >> f >> k;
        vector<pair<int,int>> a;
        int cnt[101];
        memset(cnt, 0, sizeof(cnt));
        int num = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
            if (i + 1 == f) num = x;
            a.emplace_back(x, i + 1);
        }
        int tmp = cnt[num];
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < k; ++i) {
            cnt[a[i].first]--;
        }
        if (cnt[num] == 0) cout << "YES\n";
        else if (cnt[num] > 0 && cnt[num] < tmp) cout << "MAYBE\n";
        else cout << "NO\n";
    }
    return 0;
}
