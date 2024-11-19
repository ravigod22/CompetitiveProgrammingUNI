#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 1;
int cnta[maxn];
int cntb[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            cntb[b[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            if (cnta[a[i]] < cntb[a[i]]) ans++;
            cnta[a[i]]++;
        }
        int result = (ans >= k);
        for (int i = m; i < n; ++i) {
            if (cnta[a[i - m]] <= cntb[a[i - m]]) ans--;
            cnta[a[i - m]]--;
            if (cnta[a[i]] < cntb[a[i]]) ans++;
            cnta[a[i]]++;
            result += (ans >= k);
        }
        for (int i = 0; i < m; ++i) cntb[b[i]]--;
        for (int i = 0; i < m; ++i) cnta[a[n - 1 - i]]--;
    }
	return 0;
}
