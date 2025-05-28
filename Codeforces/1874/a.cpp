#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n), b(m);
        for (int& e : a) cin >> e;
        for (int& e : b) cin >> e;
        int minA = min_element(a.begin(), a.end()) - a.begin();
        int maxB = max_element(b.begin(), b.end()) - b.begin();
        if (a[minA] < b[maxB]) swap(a[minA], b[maxB]);
        if (k % 2 == 0) {
            int maxA = max_element(a.begin(), a.end()) - a.begin();
            int minB = min_element(b.begin(), b.end()) - b.begin();
            if (a[maxA] > b[minB]) swap(a[maxA], b[minB]);
        }
        cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
    }
    return 0;
}
