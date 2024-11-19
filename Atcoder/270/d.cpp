#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int> a(k);
    for (int& e : a) cin >> e;
    int taka = 0;
    int aoki = 0;
    bool f = true;
    for (int i = k - 1; i >= 0; --i) {
        if (n < a[i]) continue;
        int tmp = n / a[i];
        if (tmp & 1) {
            if (f) {
                taka += a[i] * (tmp + 1)/ 2;
                aoki += a[i] * (tmp / 2);
                f = false;
            }
            else {
                taka += a[i] * (tmp / 2);
                aoki += a[i] * (tmp + 1) / 2;
                f = true;
            }
        }
        else {
            taka += a[i] * (tmp / 2);
            aoki += a[i] * (tmp / 2);
        }
        n -= tmp * a[i];
    }
    cout << taka << "\n";
    return 0;
}

