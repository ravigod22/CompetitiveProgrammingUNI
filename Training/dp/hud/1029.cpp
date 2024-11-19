#include <iostream>
#include <map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (cin >> n) {
        map<int, int> cnt;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cnt[x]++;
            if (cnt[x] >= (n + 1) / 2) {
                ans = x;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
