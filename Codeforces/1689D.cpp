#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int lo = 1;
        int hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << lo << " " << mid << endl;
            int cnt = 0;
            for (int i = lo; i <= mid; ++i) {
                int p; cin >> p;
                if (p >= lo && p <= mid) ++cnt;
            }
            if (cnt & 1) hi = mid;
            else lo = mid + 1;
        }
        cout << "! " << lo << endl;
    }
    return 0;
}
