#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (int i = 1; i < n; ++i) {
        vector<string> aux;
        for (int j = 0; j < n; j += i) aux.emplace_back(s.substr(j, i));
        for (int c = 1; c <= i; ++c) {
            string tmp;
            for (string e : aux) {
                if (e.size() >= c) tmp += e[c - 1];
            }
            if (tmp == t) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}

