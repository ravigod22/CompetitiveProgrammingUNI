#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> G[n + 1];
    vector<int> box(n);
    vector<int> weight(n);
    for (int& e : box) cin >> e;
    for (int& e : weight) cin >> e;
    for (int i = 0; i < n; ++i) {
        G[box[i]].emplace_back(weight[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (G[i].size() < 2) continue;
        vector<int> tmp = G[i];
        int aux = *max_element(tmp.begin(), tmp.end());
        int sum = 0;
        for (int j = 0; j < G[i].size(); ++j) sum += tmp[j];
        ans += sum - aux;
    }
    cout << ans << "\n";
    return 0;
}
