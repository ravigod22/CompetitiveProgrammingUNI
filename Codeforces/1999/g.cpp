#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int lo = 1;
        int hi = 1000;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            cout << "? " << mid << " " << mid << endl;
            int x; cin >> x;
            if (x == mid * mid) lo = mid + 1;
            else hi = mid;
        }
        cout << "! "<< lo << "\n";
    }
    return 0;
}

