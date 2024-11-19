#include <bits/stdc++.h>
using namespace std;
bool solve() {
    long long n; cin >> n;
    string tmp = to_string(n);
    int l = tmp.size();
    reverse(tmp.begin(), tmp.end());
    long long tmp1 = n / 2;
    string another = to_string(tmp1);
    if (tmp.size() == another.size()) return 0;
    if (tmp[0] == '9' || tmp[(int)tmp.size() - 1] == '9') return 0;
    int carry = 0;
    for (int i = 0; i < l - 1; ++i) {
        if (i == 0) {
            int p = 10 + (tmp[i] - '0') + carry;
            carry = -1;
            if (p < 10) return 0;
        }
        else {
            int q = 10 + (tmp[i] - '0') + carry;
            if (q == 19) return 0;
            if (q < 10) return 0;
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        cout << (solve() ? "YES\n" : "NO\n");
    }
    return 0;
}

