#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int findkth(int n, i64 pos) {
    if (n == 1) return 1;
    if (pos < (1LL << (n - 1))) {
        return findkth(n - 1, pos);
    }
    else if (pos == (1LL << (n - 1))) {
        return n;
    }
    else if (pos < (1LL << n)) {
        return findkth(n - 1, pos - (1LL << (n - 1)));
    }
    return 1;
}

int main() {
    int n; cin >> n;
    i64 k; cin >> k;
    cout << findkth(n, k) << "\n";
    return 0;
}
