#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        long long k;
        int n; 
        cin >> n >> k;
        if (n == 1) {
            if (k == 0) {
                cout << "Yes\n";
                cout << "1" << "\n";
            }
            else cout << "No\n";
            continue;
        }
        if (k & 1) {
            cout << "No\n";
            continue;
        }
        long long maxk = 1ll * n * (n + 1) / 2 + 0ll - ((n + 1) / 2);
        if (k > maxk) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        vector<int> a(n + 1);
        iota(a.begin(), a.end(), 0);
        for (int i = 1, j = n; i < j; ) {
            int tmp = 2 * (a[j] - a[i]);
            while (1ll * tmp < k && i < j) {
                k -= 1ll * tmp;
                swap(a[j], a[i]);
                ++i;
                --j;
                tmp = 2 * (a[j] - a[i]);
            }
            swap(a[i + (k / 2)], a[i]);
            break;
        } 
        for (int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}

