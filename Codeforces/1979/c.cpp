#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> k(n);
        for (int& e : k) cin >> e;
        int result = 1;
        for (int e : k) result = lcm(result, e);
        vector<int> tmp(n);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            tmp[i] = result / k[i];
            sum += 0ll + tmp[i];
        }
        if (sum >= result) cout << "-1\n";
        else {
            for (int i = 0; i < n; ++i) cout << tmp[i] << " \n"[i + 1 == n];
        }
    }
    return 0;
}
