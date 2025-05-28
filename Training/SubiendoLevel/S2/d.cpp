#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 ans;
int n, u, r;
vector<int> a, b, k, p;


void back(vector<int> arr, int remain, bool firstxor) {
    if (remain % 2 == 0) {
        i64 sum = 0;
        for (int i = 0; i < n; ++i) sum += 1LL * arr[i] * k[i];
        ans = max(ans, sum);
    }
    if (remain == 0) return;
    if (!firstxor) {
        for (int i = 0; i < n; ++i) arr[i] ^= b[i];
        back(arr, remain - 1, 1);
        for (int i = 0; i < n; ++i) arr[i] ^= b[i];
    }
    vector<int> tmp = arr;
    for (int i = 0; i < n; ++i) tmp[i] = arr[p[i]] + r;
    back(tmp, remain - 1, 0);
}

int main() {
    cin >> n >> u >> r;
    a.resize(n);
    for (int& e : a) cin >> e;
    b.resize(n);
    for (int& e : b) cin >> e;
    k.resize(n);
    for (int& e : k) cin >> e;
    p.resize(n);
    for (int& e : p) cin >> e, e--;
    ans = -1e18;
    back(a, u, 0);
    cout << ans << "\n";
    return 0;
}
