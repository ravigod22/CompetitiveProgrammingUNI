#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d; cin >> n >> d;
    vector<pair<int, int>> a(n);
    for (auto& e : a) cin >> e.first >> e.second;
    for (int i = 1; i <= d; ++i) {
        int maxe = 0;
        for (auto& e : a) {
            maxe = max(maxe, e.first * (e.second + i));
        }
        cout << maxe << "\n";
    }
    return 0;
}

