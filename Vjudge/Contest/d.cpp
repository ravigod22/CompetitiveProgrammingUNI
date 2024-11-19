#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int a[maxn];
int ft[maxn];

void update(int pos, int value) {
    for (++pos; pos < maxn; pos += pos & -pos) ft[pos] += value;
}

int sum(int pos) {
    int ans = 0;
    for (++pos; pos > 0; pos -= pos & -pos) ans += ft[pos];
    return ans;
}

int query(int l, int r) {
    return sum(r) - sum(l - 1);
}

int main() {
    int n; cin >> n;
    vector<pair<int,int>> q;
    for (int i = 0; i < n; ++i) {
        int l, r; cin >> l >> r;
        q.emplace_back(l, r);
    }
    sort(q.begin(), q.end());
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += 0ll + sum(q[i].first);
        update(q[i].first, 1);
        update(q[i].second + 1, -1);
    }
    cout << ans << "\n";
    return 0;
}


