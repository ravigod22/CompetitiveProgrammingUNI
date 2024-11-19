#include <bits/stdc++.h>
using namespace std;
const int maxe = 1e6 + 10;
const int maxn = 3e5 + 10;
int n, q;
int last[maxe];
int ft[maxn];

void update(int pos, int value) {
    for (++pos; pos < maxn; pos += pos & -pos) ft[pos] += value;
}

int sum(int pos) {
    int ans = 0;
    for (++pos; pos > 0; pos -= pos & -pos) ans += ft[pos];
    return ans;
}

int range(int l, int r) {
    return sum(r) - sum(l - 1);
}

int same(int pos) {
    return sum(pos) - sum(pos - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(ft, 0, sizeof(ft));
    memset(last, -1, sizeof(last));
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    cin >> q;
    vector<tuple<int, int, int>> query;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        l--; r--;
        query.emplace_back(r, l, i);
    }
    sort(query.begin(), query.end());
    vector<int> ans(q);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int l, r, id;
        tie(r, l, id) = query[j];
        if (last[a[i]] == -1) {
            update(i, 1);
            last[a[i]] = i;
        }  
        else {
            int tmp = same(last[a[i]]);
            update(last[a[i]], -1);
            update(i, 1);
            last[a[i]] = i;
        }
        while (i == r && j < q) {
            ans[id] = range(l, r);
            j++;
            tie(r, l, id) = query[j];
        }
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
    return 0;
}
