#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        priority_queue<int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            a.push(x);
        }
        for (int i = 0; i < m; ++i) {
            int x; cin >> x;
            b.push(x);
        }
        int times = n - m;
        bool can = true;
        while (times && !a.empty() && !b.empty()) {
            if (a.top() == b.top()) {
                a.pop();
                b.pop();
                continue;
            }
            else if (a.top() < b.top()) {
                int aux = b.top();
                b.pop();
                b.push((aux + 1) / 2);
                b.push(aux / 2);
                times--;
            }
            else {
                can = false;
                break;
            }
        }
        if (!can) {
            cout << "NO\n";
            continue;
        }
        if (a.size() == b.size()) {
            while (!a.empty()) {
                if (a.top() == b.top()) a.pop(), b.pop();
                else {
                    can = false;
                    break;
                }
            }
            cout << (can ? "YES" : "NO") << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}

