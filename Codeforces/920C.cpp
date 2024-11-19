#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string steps;
    cin >> steps;
    for (int i = 0; i < n - 1; ) {
        int ini = i;
        int endi = i;
        while (steps[i] == '1' && i < n - 1) {
            ++i;
        } 
        endi = i;
        if (ini == endi) {
            ++i;
            continue;
        }
        //endi++;
        sort(a.begin() + ini, a.begin() + endi + 1);
    }
    bool ans = true;
    for (int i = 1; i < n; ++i) {
        if (a[i - 1] > a[i]) {
            ans = false;
        } 
    }
    cout << (ans ? "YES\n" : "NO\n");
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
