#include <bits/stdc++.h>
using namespace std;

int main() {
    int p[5];
    for (int i = 0; i < 5; ++i) cin >> p[i];
    vector<pair<int, string>> ans;
    for (int i = 0; i < (1 << 5); ++i) {
        string tmp;
        int sum = 0;
        for (int j = 0; j < 5; ++j) {
            if (i & (1 << j)) {
                tmp += (char)(j + 'A');
                sum += p[j];
            }
        }
        ans.emplace_back(sum, tmp);
    }
    sort(ans.rbegin(), ans.rend());
    ans.pop_back();
    vector<string> res;
    for (int i = 0; i < (int)ans.size(); ) {
        vector<string> tmp;
        int aux = ans[i].first;
        while (i < (int)ans.size() && aux == ans[i].first) tmp.emplace_back(ans[i++].second);
        sort(tmp.begin(), tmp.end());
        for (auto e : tmp) res.emplace_back(e);
    }
    for (auto e : res) cout << e << "\n";
    return 0;
}
