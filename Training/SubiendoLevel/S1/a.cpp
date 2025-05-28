#include <bits/stdc++.h>
using namespace std;

int f(int n) {
    if (n <= 100) return 91;
    return n - 10;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        cout << "f91(" << n << ") = " << f(n) << "\n";
    }
    return 0;
}
