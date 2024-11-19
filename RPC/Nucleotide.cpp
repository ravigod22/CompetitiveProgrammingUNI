#include <bits/stdc++.h>
using namespace std;
const char matrix[] = {'C', 'G', 'T', 'A'};
void solve() {
    string s;
    cin >> s;
    int k = s.length();
    vector<int> Thy(k + 1, 0);
    vector<int> Gua(k + 1, 0);
    vector<int> Ade(k + 1, 0);
    vector<int> Cyt(k + 1, 0);
    for (int i = 0; i < k; ++i) {
        Thy[i + 1] = Thy[i] + (s[i] == 'T' ? 1 : 0);
        Gua[i + 1] = Gua[i] + (s[i] == 'G' ? 1 : 0);
        Ade[i + 1] = Ade[i] + (s[i] == 'A' ? 1 : 0);
        Cyt[i + 1] = Cyt[i] + (s[i] == 'C' ? 1 : 0);
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        vector<pair<int,int>> result;
        result.emplace_back(Thy[r] - Thy[l - 1], 2);
        result.emplace_back(Gua[r] - Gua[l - 1], 1);
        result.emplace_back(Ade[r] - Ade[l - 1], 3);
        result.emplace_back(Cyt[r] - Cyt[l - 1], 0);
        sort(result.rbegin(), result.rend());
        for (int j = 0; j < 4; ++j) {
        	int ind = result[j].second;
        	cout << matrix[ind];
        }
        cout << "\n";
        result.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
