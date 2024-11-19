#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> pos;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vector<pair<int,int>> result;
    for (int i = 0; i < n; ++i) {
        if (a[i] != i + 1) {
            result.emplace_back(i + 1, pos[i + 1] + 1);
            int tmp = a[i];
            int pos_ini = pos[i + 1];
            swap(a[i], a[pos[i + 1]]);
            pos[tmp] = pos_ini;
        }
    }
    int k = (result.empty() ? 0 : result.size());
    cout << k << "\n";
    for (auto e : result) {
        cout << e.first << " " << e.second << "\n";
    }
    return 0;
}
