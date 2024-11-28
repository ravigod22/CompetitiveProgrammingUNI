#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    const int n = s.size();
    set<char> ch;
    stack<char> q;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            q.emplace(s[i]);
        }
        else if (s[i] == ')') {
            if (q.empty()) {
                cout << "No\n";
                return 0;
            }
            while (!q.empty() && q.top() != '(') {
                char tmp = q.top();
                ch.erase(tmp);
                q.pop();
            }
            if (q.empty()) {
                cout << "No\n";
                return 0;
            }
            q.pop();
        }
        else {
            if (ch.count(s[i])) {
                cout << "No\n";
                return 0;
            }
            ch.emplace(s[i]);
            q.emplace(s[i]);
        }
    }
    cout << "Yes\n";
    return 0;
}
