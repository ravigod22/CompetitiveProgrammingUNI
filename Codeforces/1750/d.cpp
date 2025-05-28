#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
map<int, vector<int>> pr;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return (1LL * a * b) % mod;
}

vector<int> get_primes(int m) {
    vector<int> primes;
    for (int i = 2; i * i <= m; ++i) {
        if (m % i) continue;
        primes.push_back(i);
        while (m % i == 0) m /= i;
    }
    if (m > 1) primes.push_back(m);
    return primes;
}

int pie(int universe, vector<int> primes) {
    if (primes.empty()) return universe;
    int n = primes.size();
    vector<int> cnt(n + 1, 0);
    cnt[0] = universe;
    for (int i = 1; i < (1 << n); ++i) {
        int bit = __builtin_popcount(i);
        int num = 1;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) num *= primes[j];
        }
        cnt[bit] += universe / num;
    }
    int ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += (i & 1 ? -cnt[i] : cnt[i]);
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector<int> cnt(n, 0);
        cnt[0] = 1;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] < a[i]) continue;
            if (a[i - 1] % a[i]) continue;
            int num = a[i - 1] / a[i];
            if (!pr.count(num)) {
                pr[num] = get_primes(num);
            }
            int possible = pie(m / a[i], pr[num]);
            cnt[i] = mul(cnt[i - 1], possible);
        }
        cout << cnt[n - 1] << "\n";
    }
    return 0;
}
