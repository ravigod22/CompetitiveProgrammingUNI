#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int& e : a) cin >> e;
    for (int& e : b) cin >> e;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a[n - 1] + b[n - 1];
    return 0;
}
