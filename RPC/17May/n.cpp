#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
bool vis[N];

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int solve(int n) {
    int tmp = n;
    vector<int> ans;
    while (tmp--) {
        for (int i = 2; i <= n; ++i) ans.push_back(i);
    }
    int cnt = n - 1;
    int last = -1;
    for (int i = 0; i < ans.size(); ++i) {
        if (vis[ans[i]]) continue;
        if (cnt == 1) {
            last = ans[i];
            break;
        }
        int pos = -1;
        for (int j = i + 1; j < ans.size(); ++j) {
            if (vis[ans[j]]) continue;
            if (gcd(ans[i], ans[j]) > 1) {
                pos = j;
                cnt -= 1;
                break;
            }
        }
        if (pos != -1 && cnt) {
            vis[ans[pos]] = 1;
            i = pos;
        }
    }
    for (int i = 1; i <= n; ++i) vis[i] = false;
    return last;
}

int main() {
    int k;
    cin >> k;
    for (int i = 3; i <= k; ++i) {
        cout << "i - > " << i << ": " << solve(i) << "\n";
    }
    return 0;
}
