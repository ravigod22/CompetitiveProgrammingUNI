#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> t(n), v(n);
    for (int i = 0; i < n; ++i) cin >> t[i] >> v[i];
    int sum = v[0];
    for (int i = 1; i < n; ++i) {
        sum -= (t[i] - t[i - 1]);
        sum = max(sum, 0);
        sum += v[i];
    }
    cout << sum << "\n";
    return 0;
}
