#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt; cin >> tt;
    while (tt--) {
        int a[2], b[2];
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        vector<int> turn = {1, 2};
        int ans = 0;
        do {
            vector<int> turn2 = {1, 2};
            do {
                int cnt = 0;
                vector<int> one;
                vector<int> two;
                for (int i = 0; i < 2; ++i) {
                    if (turn[i] == 1) one.emplace_back(a[i]);
                    else two.emplace_back(a[i]);
                }
                for (int i = 0; i < 2; ++i) {
                    if (turn2[i] == 1) one.emplace_back(b[i]);
                    else two.emplace_back(b[i]);
                }
                if (one[0] > one[1]) cnt++;
                else if (one[0] < one[1]) cnt--;
                if (two[0] > two[1]) cnt++;
                else if (two[0] < two[1]) cnt--;
                if (cnt > 0) ans++;
            } while (next_permutation(turn2.begin(), turn2.end()));
        } while (next_permutation(turn.begin(), turn.end()));
        cout << ans << "\n";
    }
    return 0;
}

