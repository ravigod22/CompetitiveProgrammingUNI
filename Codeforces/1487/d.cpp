#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e9;
vector<int> ans;
void init() {
    for (int a = 1; a * a <= 2 * maxn + 1; a += 2) {
        int b = ((a * a) - 1) / 2;
        if (b <= 0) continue;
        int c = b + 1;
        ans.emplace_back(c);
    }    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int lo = 0; 
        int hi = ans.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (ans[mid] <= n) lo = mid;
            else hi = mid - 1;
        }
        if (n <= 4) lo = -1;
        cout << lo + 1 << "\n";
    }
    return 0;
}
