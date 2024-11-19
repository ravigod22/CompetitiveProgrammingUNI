#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n; cin >> n;
        if (n == -1) break;
        if (n == 1) {
            cout << "Y\n";
            continue;
        }
        n -= 1;
        if (n % 3) {
            cout << "N\n";
            continue;
        }
        n /= 3;
        long long tmp = 1LL * 4 * n + 1;
        long long k = sqrtl(tmp);
        if (k * k != tmp) {
            cout << "N\n";
            continue;
        }
        if (k % 2 == 0) {
            cout << "N\n";
            continue;
        }
        cout << "Y\n";
    }
    return 0;
}
