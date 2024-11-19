#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    cout << a[n / 2] - a[(n - 1) / 2] << "\n";
    return 0;
}
