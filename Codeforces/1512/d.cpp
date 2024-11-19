#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        n += 2;
        vector<int> a(n);
        for (int& e : a) cin >> e;
        sort(a.begin(), a.end());
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        bool could = false;
        for (int i = 0; i < n; ++i) {
            if (i != n - 1) {
                long long tmp = sum - a[i];
                long long tmp2 = a[n - 1];
                if (tmp - a[n - 1] == tmp2) {
                    swap(a[i], a[n - 1]);
                    swap(a[i], a[n - 2]);
                    could = true;
                    break;
                }
            }
            else {
                long long tmp = sum - a[i];
                long long tmp2 = a[n - 2];
                if (tmp - a[n - 2] == tmp2) {
                    could = true;
                    break;
                }
            }
        }
        if (could) {
            n -= 2;
            a.pop_back();
            a.pop_back();
            sort(a.begin(), a.end());
            for (int i = 0; i < n; ++i) cout << a[i] << " \n"[i + 1 == n];
        }
        else cout << -1 << "\n";
    }
    return 0;
}

