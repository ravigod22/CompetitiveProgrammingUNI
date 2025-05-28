#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(), a.rend());
    int cnt = 1;
    vector<int> ans(n);
    for (int i = 0; i < n; ) {
        int cur = a[i].first;
        int jump = 0;
        while (i < n && cur == a[i].first) {
            ans[a[i].second] = cnt;
            jump++;
            i++;
        }
        cnt += jump;
    }
    for (int e : ans) cout << e << "\n";
    return 0;
}
