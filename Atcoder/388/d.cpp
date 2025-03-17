#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    multiset<int> rest;
    i64 ans = 0;
    for (int i = 0; i < n; ++i) {
        while (!rest.empty() && i >= (*rest.begin())) {
            ans--;
            rest.erase(rest.begin());
        }
        a[i] += ans;
        int remain = min(a[i], n - i - 1);
        a[i] -= remain;
        ans++;
        rest.emplace(i + 1 + remain);
    }
    for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i + 1 == n];
    return 0;
}

