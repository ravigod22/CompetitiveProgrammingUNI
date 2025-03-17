#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> q(n), p(n);
    for (int& e : p) cin >> e, e--;
    for (int& e : q) cin >> e, e--;
    vector<pair<int, int>> person(n);
    vector<int> written(n);
    for (int i = 0; i < n; ++i) {
        person[i] = {q[i], p[i]};
        written[q[i]] = i;
    }
    for (int i = 0; i < n; ++i) {
        auto [wear, per] = person[written[i]];
        auto [res, _] = person[per];
        cout << res + 1 << " \n"[i + 1 == n];
    }
    return 0;
}


