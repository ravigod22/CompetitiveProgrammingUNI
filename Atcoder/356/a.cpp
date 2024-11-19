#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    reverse(a.begin() + l - 1, a.begin() + r);
    for (int e : a) cout << e << " ";
    return 0;
}
