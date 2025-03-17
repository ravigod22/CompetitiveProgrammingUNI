#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

const int maxn = 2e6;
int vis[maxn + 1];

int main() {
    vector<int> pr;
    for (int i = 2; i <= maxn; ++i) {
        if (vis[i]) continue;
        pr.push_back(i);
        for (int j = i; j <= maxn; j += i) vis[j] = 1;
    }
    i64 sum = accumulate(pr.begin(), pr.end(), 0LL);
    cout << sum << "\n";
    return 0;
}
