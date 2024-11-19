#include <bits/stdc++.h>
using namespace std;

int delete_ch(int n) {
    int ans;
    for (int i = 30; i >= 0; --i) {
        if (n & (1 << i)) {
            ans = i + 1;
            break;
        }
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> result;
    for (char i = 'a'; i <= 'z'; ++i) {
        int tmp_b = -1; 
        int tmp_e = n;
        int ans = 0;
        for (int j = 0; j < n; ++j) {
            if (s[j] == i) {
                int intervalues = j - tmp_b - 1;
                ans = max(ans, (intervalues == 0 ? 0 : delete_ch(intervalues)));
                tmp_b = j;
            }
        }
        int p = tmp_e - tmp_b - 1;
        ans = max(ans, (p == 0 ? 0 : delete_ch(p)));
        result.emplace_back(ans);
    }
    int k = *min_element(result.begin(), result.end());
    cout << k << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
