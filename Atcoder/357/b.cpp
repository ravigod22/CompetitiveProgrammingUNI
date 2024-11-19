#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] >= 'a' && s[i] <= 'z') cnt++;
    }
    int another = n - cnt;
    if (cnt > another) {
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') continue;
            int tmp = s[i] - 'A';
            s[i] = (char)(tmp + 'a');
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z') continue;
            int tmp = s[i] - 'a';
            s[i] = (char) (tmp + 'A');
        }
    }
    cout << s << "\n";
    return 0;
}

