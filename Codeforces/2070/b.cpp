#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

void solve() {
    int n, x; cin >> n >> x;
    i64 k; cin >> k;
    string s; cin >> s;
    i64 time = 0;
    int last = -1;
    for (int i = 0; i < n && time < k; ++i) {
        if (s[i] == 'L') x--;
        else x++;
        time++;
        if (x == 0) {
            last = i;
            break;
        }
    }
    if (last == -1) {
        cout << 0 << "\n";
        return;
    }
    if (time == k) {
        cout << 1 << "\n";
        return;
    }
    i64 cnt = 1;
    int lastnew = -1;
    int newx = 0;
    for (int i = 0; i < n && time < k; ++i) {
        if (s[i] == 'L') x--;
        else x++;
        time++;
        if (x == 0) {
            lastnew = i;
            break;
        }
    }
    if (lastnew == -1) {
        cout << cnt << "\n";
        return;
    }
    cnt++;
    if (time == k) {
        cout << cnt << "\n";
        return;
    }
    i64 remain = k - time;
    cnt += (remain / (lastnew + 1));
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}



