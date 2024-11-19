#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> primes;
        int ans = 0;
        int optimal = 0;
        for (int i = 2; i <= n; ++i) {
            int cnt = n / i;
            int tmp = (cnt * (cnt + 1)) / 2;
            if (ans < i * tmp) {
                optimal = i;
                ans = tmp * i;
            }
        }
        cout << optimal << "\n";
    }
    return 0;
}
