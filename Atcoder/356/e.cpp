#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int N = 2e6 + 5;
i64 cnt[N];
i64 pre[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        cnt[a] += 1;
    }
    for (int i = 1; i < N; ++i)
        pre[i] = pre[i - 1] + cnt[i];
    i64 ans = 0;
    for (int i = 1; i <= 1e6; ++i) {
        ans += (cnt[i] * (cnt[i] - 1)) / 2;
        i64 tmp = 0;
        for (int j = i; j + i < N; j += i) {
            tmp += 1LL * (pre[j + i - 1] - pre[j - 1]) * (j / i);
        }
        tmp -= cnt[i];
        ans += cnt[i] * tmp;
    }
    cout << ans << "\n";
    return 0;
}
