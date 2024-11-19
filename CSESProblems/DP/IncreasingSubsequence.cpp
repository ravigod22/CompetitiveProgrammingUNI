#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;
const int maxn = 2e5 + 5;
int n;
int dis[maxn];
int x[maxn];

int LIS() {
    fill(dis, dis + n + 1, inf);
    dis[0] = -inf;
    for (int i = 0; i < n; ++i) {
        int ind = upper_bound(dis, dis + n + 1, x[i]) - dis;
        // LIS -> i - 1 <<< a[i] <<< LIS -> i
        if (dis[ind - 1] < x[i] && x[i] < dis[ind]) {
            dis[ind] = x[i];
        }
    }
    int ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (dis[i] < inf) ans = i;
    }
    return ans;
}


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> x[i];
    int ans = LIS();
    cout << ans;
    return 0;
}
