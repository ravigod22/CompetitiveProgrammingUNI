#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        stack<char> s1, s2;
        vector<int> color;
        if (n & 1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == ')') {
                if (s1.empty()) {
                    s2.emplace(s[i]);
                    color.emplace_back(2);
                }
                else {
                    s1.pop();
                    color.emplace_back(1);
                }
            }
            else {
                if (s2.empty()) {
                    s1.emplace(s[i]);
                    color.emplace_back(1);
                }
                else {
                    s2.pop();
                    color.emplace_back(2);
                }
            }
        }
        if (!s1.empty() or !s2.empty()) {
            cout << -1 << "\n";
            continue;
        }
        set<int> step(color.begin(), color.end());
        int k = step.size();
        cout << k << "\n";
        if (k == 1) {
            for (int e : color) cout << 1 << " ";
        }
        else for (int e : color) cout << e << " ";
        cout << "\n";
    }
    return 0;
}
