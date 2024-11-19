#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
        string tmp = s.substr(0, i + 1);
        string aux = s.substr(i + 1);
        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
        if (tmp == aux) {
            cout << i + 1 << endl;
        }
    }
    return 0;
}
