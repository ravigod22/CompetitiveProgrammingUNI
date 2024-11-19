#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    while (tt--) {
        int n; cin >> n;
        multiset<string> s;
        vector<pair<string, string>> name;
        for (int i = 0; i < n; ++i) {
            string a, b; cin >> a >> b;
            name.emplace_back(a, b);
            s.emplace(a);
            s.emplace(b);
        }
        vector<string> ans(n);
        set<string> aux;
        for (int i = 0; i < n; ++i) {
            string a = name[i].first;
            string b = name[i].second;
            if (s.count(a) > 1) {
                ans[i] = b;
                if (aux.count(ans[i])) {
                    cout << "No\n";
                    return 0;
                }
            }
            else if (s.count(b) > 1) {
                ans[i] = a;
                if (aux.count(a)) {
                    cout << "No\n";
                    return 0;
                }
            }
            aux.emplace(ans[i]);
        }
        cout << "Yes\n";
    }
    return 0;
}

