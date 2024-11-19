#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char,bool> belong;
    for (int i = 0; i < k; ++i) {
        char x;
        cin >> x;
        belong[x] = true;
    }
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        long long cnt = 0;
        while (belong[s[i]] && i < n) {
            ++cnt;
            ++i;
        }
        sum += (cnt * (cnt + 1)) / 2; 
    }
    cout << sum << "\n";

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int test = 1;
    //cin >> test;
    while (test--) {
        solve();
    }
    return 0;
}
