#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int cows = n / 4;
        int chicken = (n - cows * 4) / 2;
        cout << cows + chicken << "\n";
    }
    return 0;
}
