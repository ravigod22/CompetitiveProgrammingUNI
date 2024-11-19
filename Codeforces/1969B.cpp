#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		int n = s.size();
		vector<pair<char,int>> times;
		for (int i = 0; i < n; ) {
			char tmp = s[i];
			int cnt = 0;
			while (s[i] == tmp && i < n) {
				++i;
				++cnt;
			}
			times.emplace_back(tmp, cnt);
		}
		int k = times.size();
		if (k == 1) {
			cout << 0 << "\n";
			continue;
		}
		if (k == 2 && times[0].first == '0') {
			cout << 0 << "\n";
			continue;
		}
		int ind = (times[0].first == '0' ? 1 : 0);
		long long ans = 0;
		int carry = 0;
		for (int i = ind; i < k; i += 2) {
			if (i + 1 < k && i < k) {
				int n_ones = times[i].second;
				int n_zeros = times[i + 1].second;
				//cout << n_ones << " " << n_zeros << " " << carry << "\n";
				ans += 1ll * n_zeros * (n_ones + carry + 1);
				carry += n_ones;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
