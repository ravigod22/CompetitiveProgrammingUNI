#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> p(n);
    for (int& e : p) cin >> e;
    int pos = n - 2;
    while (p[pos] < p[pos + 1]) pos--;
    int tmp = n - 1;
    while (p[pos] < p[tmp]) tmp--;
    swap(p[pos], p[tmp]);
    reverse(p.begin() + pos + 1, p.end());
    for (int i = 0; i < n; ++i) cout << p[i] << " \n"[i + 1 == n];
    return 0;
}
