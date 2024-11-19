#include <bits/stdc++.h>
using namespace std;

int main() {
    cout << fixed << setprecision(6);
    int n; cin >> n;
    vector<int> a(5 * n);
    for (int& e : a) cin >> e;
    sort(a.begin(), a.end());
    double sum = 0;
    for (int i = n; i < 4 * n; ++i) {
        sum += a[i];
    }
    cout << sum / (3 * n);
    return 0;
}
