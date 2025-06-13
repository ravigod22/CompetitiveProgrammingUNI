#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    string s;
    cin >> s;
    vector<int> cnt(3, 0);
    for (char e : s) {
        if (e == 'B') cnt[0]++;
        else if (e == 'S') cnt[1]++;
        else cnt[2]++;
    }
    vector<int> ingre(3), price(3);
    for (int& e : ingre) cin >> e;
    for (int& e : price) cin >> e;
    i64 r;
    cin >> r;
    i64 lo = 0;
    i64 hi = 1e13;
    auto f = [&] (i64 nburger) -> i64 {
        i64 cost = 0;
        for (int i = 0; i < 3; ++i) {
            i64 need = max(0LL, 1LL * cnt[i] * nburger - 1LL * ingre[i]);
            cost += 1LL * price[i] * need;
        }
        return cost;
    };
    while (lo < hi) {
        i64 mid = (lo + hi + 1) / 2;
        if (f(mid) <= r) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
