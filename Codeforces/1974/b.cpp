#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
        int k; cin >> k;
		string s; cin >> s;
        if (k == 1) {
            cout << s << "\n";
            continue;
        }
        set<char> tmp;
        for (int i = 0; i < k; ++i) tmp.emplace(s[i]);
        map<char,char> decode;
        vector<char> result;
        for (auto e : tmp) result.emplace_back(e);
        int n = result.size();
        for (int i = n - 1, j = 0; i >= (n / 2) && j < (n / 2); --i, ++j) {
            decode[result[i]] = result[j];
            decode[result[j]] = result[i];
        }
        if (n & 1) {
            decode[result[n / 2]] = result[n / 2];
        }
        string ans;
        for (int i = 0; i < k; ++i) {
            cout << decode[s[i]];
        }
        cout << "\n";
	}
	return 0;
}
