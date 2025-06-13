#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 1e5 + 5;
int n, k;
int a[N];

bool f(i64 umbral) {
    i64 acc = 0;
    for (int i = 0; i < n; ++i) {
        acc += min(1LL * a[i], umbral);
    }
    return acc >= 1LL * k * umbral;
}


int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    i64 lo = 1;
    i64 hi = 1e14;
    while (lo < hi) {
        i64 mid = (lo + hi + 1) / 2;
        if (f(mid)) lo = mid;
        else hi = mid - 1;
    }
    cout << lo << "\n";
    return 0;
}
