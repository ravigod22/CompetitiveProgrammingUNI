#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);
    set<string> res;
    do {
        string tmp;
        for (int i = 0; i < n; ++i) {
            tmp += s[a[i]];
        }
        res.emplace(tmp);
    } while (next_permutation(a.begin(), a.end()));
    cout << res.size() << "\n";
    for (auto e : res) cout << e << "\n";
    return 0;
}
