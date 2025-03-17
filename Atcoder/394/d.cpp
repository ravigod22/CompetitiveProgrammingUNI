#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl


void solve() {
    string s; cin >> s;
    const int n = s.size();
    stack<char> st;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(' || s[i] == '<' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if (!st.empty()) {
                char tmp = st.top();
                if (s[i] == ')') {
                    if (tmp == '(') st.pop();
                    else st.push(s[i]);
                }
                else if (s[i] == '>') {
                    if (tmp == '<') st.pop();
                    else st.push(s[i]);
                }
                else {
                    if (tmp == '[') st.pop();
                    else st.push(s[i]);
                }
            }
            else st.push(s[i]);
        }
    }
    cout << (st.empty() ? "Yes" : "No") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    // cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


