#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    map<string,int> cnt;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        sort(s.begin(), s.end());
        ans += 0ll + cnt[s];
        cnt[s]++;
    }
    cout << ans << "\n";
    return 0;
}
