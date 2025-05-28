#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int cnt = 0;
    while (n) {
        int tmp = n;
        int best = 0;
        while (tmp) {
            best = max(best, tmp % 10);
            tmp /= 10;
        }
        n -= best;
        cnt++;
    }
    cout << cnt << "\n";
    return 0;
}
