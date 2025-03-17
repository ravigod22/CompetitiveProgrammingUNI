#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    stack<int> st;
    for (int i = 0; i < 100; ++i) st.push(0);
    while (q--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            st.push(x);
        }
        else {
            int ans = st.top();
            st.pop();
            cout << ans << "\n";
        }
    }
    return 0;
}

