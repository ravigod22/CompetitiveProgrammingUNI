#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; cin >> n >> m;
    set<int> mext;
    vector<int> cnt(n + 11, 0);
    vector<int> a(n);
    for (int& e : a) cin >> e;
    for (int i = 0; i <= n + 10; ++i) mext.insert(i);
    int ans = n + 10;
    for (int i = 0; i < n; ++i) {
        mext.erase(a[i]);
        cnt[a[i]]++;
        if (i + 1 >= m) {
            ans = min(ans, *mext.begin());
            if (cnt[a[i + 1 - m]] == 1) mext.insert(a[i + 1 - m]);
            cnt[a[i + 1 - m]]--;
        }
    }
    cout << ans << "\n";
    return 0;
}

