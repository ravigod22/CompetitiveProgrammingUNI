#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i].first;
        w[i].second = i + 1;
    }
    sort(w.begin(), w.end());
    string s; cin >> s;
    set<pair<int, int>> pos;
    int j = 0;
    for (auto e : s) {
        if (e == '1') {
            auto it = *prev(pos.end());
            pos.erase(prev(pos.end()));
            cout << it.second << " ";
        }
        else {
            pos.emplace(w[j]);
            cout << w[j++].second << " ";
        }
    }
    cout << "\n";
    return 0;
}
