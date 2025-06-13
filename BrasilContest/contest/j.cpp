#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    int cnt = count(s.begin(), s.end(), '.');
    k = min(cnt, k);
    cnt = 0;
    for (int i = 1; i <= k; i++) {
        cnt += s[i] == 'o';
    }
    string ans = string(k, '.') + "#";
    for (int i = k + 1; i < n; i++) {
        if (cnt  and s[i] == '.') {
            ans += "o";
            cnt--;
        } else {
            ans += s[i];
        }
    }
    cout << ans << '\n';


    return 0;
}
