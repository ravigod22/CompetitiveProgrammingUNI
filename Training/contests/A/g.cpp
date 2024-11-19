#include <bits/stdc++.h>
using namespace std;
int n, q;
const int maxn = 2e5 + 10;
int ft[maxn];
map<int, int> last;
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

int same(int x) {
    return range(x, x);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(ft, 0, sizeof(ft));
    cin >> n >> q;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<tuple<int, int, int>> query;
    for (int i = 0; i < q; ++i) {
        int l, r; cin >> l >> r;
        r--; l--;
        query.emplace_back(r, l, i);
    }
    sort(query.begin(), query.end());
    vector<int> result(q);
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int l, r, id;
        tie(r, l, id) = query[j];
        if (!last.count(a[i])) {
            last[a[i]] = i;
            update(i, 1 + same(i));
        }
        else {
            int tmp = same(last[a[i]]);
            update(last[a[i]], -tmp);
            update(i, 1 + same(i));
            last[a[i]] = i;
        }
        while (i == r && j < q) {
            result[id] = range(l, r);
            ++j;
            tie(r, l, id) = query[j];
        }
    }
    for (int i = 0; i < q; ++i) cout << result[i] << "\n";
    return 0;
}
