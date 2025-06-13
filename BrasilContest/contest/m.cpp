#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n,A,B;
    cin >> n >> A >> B;
    vector<int> a(n);
    int now = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        now += a[i];
        a[i] = now;
    }
    int k; cin >> k;
    k--;
    int H = B + a[k];
    for (int i = 0; i < n; i++) {
        if (i == k) continue;
        if (a[i] + A >= H) {
            cout << "SIM\n";
            cout << i + 1 << "\n";
            return 0;
        }
    }
    cout << "NAO\n";

    return 0;
}
