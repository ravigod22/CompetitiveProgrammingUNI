#include <bits/stdc++.h>
using namespace std;
const char t[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n, m; cin >> n >> m;
        map<char,int> s;
        for (int i = 0; i < n; ++i) {
            char y; cin >> y;
            s[y]++;
        }
        int sum = 0;
        for (int i = 0; i < 7; ++i) {
            if (s[t[i]] < m) sum += m - s[t[i]]; 
        }
        cout << sum << "\n";
    }
    return 0;
}
