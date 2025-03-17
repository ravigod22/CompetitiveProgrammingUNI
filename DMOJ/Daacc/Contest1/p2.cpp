#include <bits/stdc++.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string mine; cin >> mine;
    int t; cin >> t;
    int ans = 0;
    while (t--) {
        int damage; cin >> damage;
        string pokemon; cin >> pokemon;
        if (pokemon == "FIRE") {
            if (mine == "FIRE") ans = max(ans, damage);
            else if (mine == "WATER") ans = max(ans, damage / 2);
            else ans = max(ans, 2 * damage);
        }
        else if (pokemon == "WATER") {
            if (mine == "FIRE") ans = max(ans, 2 * damage);
            else if (mine == "WATER") ans = max(ans, damage);
            else ans = max(ans, damage / 2);
        }
        else {
            if (mine == "FIRE") ans = max(ans, damage / 2);
            else if (mine == "WATER") ans = max(ans, 2 * damage);
            else ans = max(ans, damage);
        }
    }
    cout << ans << "\n";
    return 0;
}

