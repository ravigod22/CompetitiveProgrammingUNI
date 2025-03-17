#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        multiset<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.emplace(x);
        }
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            b.emplace(x);
        }
        auto ndig = [&] (int e) -> int {
            int cnt = 0;
            while (e) {
                e /= 10;
                cnt++;
            }
            return cnt;
        };
        int ans = 0;
        multiset<int> tmpa = a, tmpb = b;
        for (int e : tmpa) {
            if (b.count(e)) {
                a.extract(e);
                b.extract(e);
            }
        }
        tmpa = a, tmpb = b;
        for (int e : tmpa) {
            if (e < 10) continue;
            a.extract(e);
            a.emplace(ndig(e));
            ans++;
        }
        for (int e : tmpb) {
            if (e < 10) continue;
            b.extract(e);
            b.emplace(ndig(e));
            ans++;
        }
        tmpa = a, tmpb = b;
        for (int e : tmpa) {
            if (b.count(e)) {
                a.extract(e);
                b.extract(e);
            }
        }
        tmpa = a, tmpb = b;
        for (int e : tmpa) {
            if (e == 1) continue;
            a.extract(e);
            a.emplace(1);
            ans++;
        }
        for (int e : tmpb) {
            if (e == 1) continue;
            b.extract(e);
            b.emplace(1);
            ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}


