#include <bits/stdc++.h>
using namespace std;
int n, m, q, ans;
const int maxq = 55;
int a[maxq], b[maxq], c[maxq], d[maxq];
vector<int> res;

void solve(int last) {
    if (res.size() == n) {
        int sum = 0;
        for (int i = 0; i < q; ++i) {
            if (res[b[i] - 1] - res[a[i] - 1] == c[i]) sum += d[i];
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = last; i <= m; ++i) {
        res.push_back(i);
        solve(i);
        res.pop_back();
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) 
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    ans = 0;
    solve(1);
    cout << ans << "\n";
    return 0;
}
