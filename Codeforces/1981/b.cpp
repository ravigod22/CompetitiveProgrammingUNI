#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        long long n, m; cin >> n >> m;
        if (m == 0) {
            cout << n << "\n";
            continue;
        }
        long long t = n + 2 * m + 1;
        long long ans = 0;
        vector<int> bits;
        for (int i = 32; i >= 0; --i) {
            if (t & (1ll << i)) {
                bits.emplace_back(i);
            }
        }
        int pos = -1;
        bool exist = false;
        for (int i = 1; i <= bits.size(); ++i) {
            if (bits[i] - bits[i - 1] == 1) {
                pos = bits[i];
                exist = true;
            }
        }
        if (exist) {
            int k = bits.size();
            for (int i = 0; i < k; ++i) {
                if (bits[i] != pos) {
                    ans |= (1ll << bits[i]);
                }
                else {
                    long long tmp = (1ll << (pos + 1)) - 1;
                    ans |= tmp;
                    break;
                }
            }
        }
        else {
            long long tmp = (1ll << (bits[0] + 1)) - 1;
            ans |= tmp;
        }
        cout << ans << "\n";
    }
    return 0;
}

