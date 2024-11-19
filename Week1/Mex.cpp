#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (auto e : cnt) {
        if(e.second == 0) continue;
        set<int> s;
        map<int,int> cnt_tmp = cnt;
        for (int i = 0; i <= n + 1; ++i) {
            if(cnt[i]) continue;
            s.insert(i);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
