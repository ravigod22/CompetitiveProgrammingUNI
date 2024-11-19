#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve() {
    cin >> n;
    cin >> s;
    int cnt[2][26];
    int prefix[2][26][n];
    memset(cnt, 0, sizeof(cnt));
    memset(prefix, 0, sizeof(prefix));
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
       for (int j = 0; j < n; ++j) {
            if (j & 1) {
                prefix[1][i][j] = (j ? prefix[1][i][j - 1] : 0) + (s[j] - 'a' == i ? 1 : 0);
                prefix[0][i][j] = (j ? prefix[0][i][j - 1] : 0);
            }
            else {
                prefix[0][i][j] = (j ? prefix[0][i][j - 1] : 0) + (s[j] - 'a' == i ? 1 : 0);
                prefix[1][i][j] = (j ? prefix[1][i][j - 1] : 0);
            }
            //cout << prefix[0][i][j] << " \n"[j + 1 == n];
        }
        //for (int j = 0; j < n; ++j) cout << prefix[1][i][j] << " \n"[j + 1 == n];
    }
    for (int i = 0; i < n; ++i) {
        if (i & 1) cnt[1][s[i] - 'a']++;
        else cnt[0][s[i] - 'a']++;
    }
    if (n & 1) {
        int result = 2e9;
        if (n == 1) {
            cout << 1 << "\n";
            return;
        }
        for (int i = 0; i < n; ++i) {
            // what if s[i] is deleted
            int cnt_tmp[2][26];
            int anstmp = 0;
            memset(cnt_tmp, 0, sizeof(cnt_tmp));
            for (int j = 0; j < 26; ++j) {
                cnt_tmp[0][j] += (i ? prefix[0][j][i - 1] : 0);
                cnt_tmp[1][j] += (i ? prefix[1][j][i - 1] : 0);
                cnt_tmp[0][j] += prefix[1][j][n - 1] - prefix[1][j][i];
                cnt_tmp[1][j] += prefix[0][j][n - 1] - prefix[0][j][i];
            }
            int tmp2 = *max_element(cnt_tmp[0], cnt_tmp[0] + 26);
            int tmp1 = *max_element(cnt_tmp[1], cnt_tmp[1] + 26);
            anstmp += accumulate(cnt_tmp[0], cnt_tmp[0] + 26, 0) - tmp2;
            anstmp += accumulate(cnt_tmp[1], cnt_tmp[1] + 26, 0) - tmp1;
            result = min(result, anstmp);
        }
        ans = result + 1;
    }
    else {
        int tmp2 = *max_element(cnt[0], cnt[0] + 26);
        int tmp1 = *max_element(cnt[1], cnt[1] + 26);
        ans += accumulate(cnt[0], cnt[0] + 26, 0) - tmp2;
        ans += accumulate(cnt[1], cnt[1] + 26, 0) - tmp1;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}




