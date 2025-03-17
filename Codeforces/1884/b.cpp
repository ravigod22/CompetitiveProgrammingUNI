#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        reverse(s.begin(), s.end());
        vector<i64> pos(n, -1);
        int k = 0;
        i64 sum = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                sum += i - k;
                pos[k] = sum;
                k++;
            }
        }
        for (int i = 0; i < n; ++i) cout << pos[i] << " \n"[i + 1 == n];
    }
    return 0;
}
