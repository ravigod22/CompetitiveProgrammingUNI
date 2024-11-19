#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> score(4, 0);
        for (int i = 0; i < 4 * n; ++i) {
            if (s[i] == '?') continue;
            score[s[i] - 'A']++;
            score[s[i] - 'A'] = min(n, score[s[i] - 'A']);
        }
        int ans = accumulate(score.begin(), score.end(), 0);
        cout << ans << "\n";
    }
    return 0;
}
