#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;

int add(int a, int b) {
    return (a + b) % mod;
}

int mul(int a, int b) {
    return 1LL * a * b % mod;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int ans = 0;
    for (int i = 0; i < 30; ++i) {
        vector<int> b;
        for (int j = 0; j < n; ++j) {
            b.push_back((a[j] >> i) & 1);
        }
        int sumodd = 0, sumeven = 0;
        int nodd = 0, neven = 1;
        int sum = 0, res = 0;
        for (int j = 0; j < n; ++j) {
            sum += b[j];
            if (sum & 1) {
                int tmp = add(mul(neven, j + 1), mod - sumeven);
                res = add(res, tmp);
                sumodd = add(sumodd, j + 1);
                nodd += 1;
            }
            else {
                int tmp = add(mul(nodd, j + 1), mod - sumodd);
                res = add(res, tmp);
                sumeven = add(sumeven, j + 1);
                neven += 1;
            }
        }
        ans = add(ans, mul(1 << i, res));
    }
    cout << ans << "\n";
    return 0;
}
