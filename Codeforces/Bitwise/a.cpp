#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<int> a(n);
		for (int& e : a) cin >> e;
		int ans = a[0];
        for (int i = 1; i < n; ++i) ans &= a[i];
		cout << ans << "\n";
	}
	return 0;
}
