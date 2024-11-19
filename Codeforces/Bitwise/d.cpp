#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    vector<int> num;
    map<int,int> exist;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        vector<int> times(27, 0);
        for (int j = 0; j < s.size(); ++j) {
            times[s[j] - 'a']++;
        }
        int tmp = 0;
        for (int j = 0; j < 27; ++j) {
            tmp |= ((times[j] & 1 ? 1 : 0) << j);
        }
        num.emplace_back(tmp);
        exist[tmp]++;
    }
    long long ans = 0; 
    for (int i = 0; i < n; ++i) {
        int tmp = num[i];
        ans += exist[tmp] - 1;
        for (int j = 26; j >= 0; --j) {
            int tmp = num[i] ^ (1 << j);
            ans += 0ll + exist[tmp];
        }
        exist[num[i]]--;
    }
    cout << ans << "\n";
    return 0;
}
