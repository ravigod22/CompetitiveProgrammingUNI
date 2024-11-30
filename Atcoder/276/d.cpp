#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return a ? gcd(b, a % b) : b;
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> times;
    int min2 = 1e9, min3 = 1e9;
    for (int& e : a) {
        cin >> e;
        int a, b;
        int cnt = 0;
        while (e % 2 == 0) e /= 2, cnt++;
        min2 = min(min2, cnt);
        a = cnt;
        cnt = 0;
        while (e % 3 == 0) e /= 3, cnt++;
        min3 = min(min3, cnt);
        b = cnt;
        times.emplace_back(a, b);
    }
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i - 1]) {
            cout << -1 << "\n";
            return 0;
        }
    }
    int ans = 0;
    assert (min2 != 1e9 && min3 != 1e9);
    for (auto [two, three] : times) {
        ans += (two - min2) + (three - min3);
    }
    cout << ans << "\n";
    return 0;
}
