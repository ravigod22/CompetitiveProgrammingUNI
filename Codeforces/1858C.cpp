#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> result(1, 1);
    vector<bool> used(n + 1, false);
    for (int i = 2; i <= n; ++i) {
        if (used[i]) continue;
        int timer = 1;
        while (i * timer <= n && i <= n) {
            result.emplace_back(i * timer);
            used[i * timer] = true;
            timer *= 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " \n"[i + 1 == n];
    } 
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
