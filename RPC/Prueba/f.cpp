#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 10;

int freq[maxn];
long long FT[maxn];

void update(int pos, int val) {
	for (++pos; pos < maxn; pos += pos & -pos) {
		freq[pos] += 1;
		FT[pos] += 0ll + val;
	}
}

int sum_freq(int pos) {
	int ans = 0;
	for (++pos; pos > 0; pos -= pos & -pos) ans += freq[pos];
	return ans;
}

long long sum_values(int pos) {
	long long ans = 0;
	for (++pos; pos > 0; pos -= pos & -pos) ans += FT[pos];
	return ans;
}

int query_freq(int l, int r) {
	return sum_freq(r) - sum_freq(l - 1);
}

long long query_values(int l, int r) {
	return sum_values(r) - sum_values(l - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt = 1;
	//cin >> tt;
	while (tt--) {
		int n; cin >> n;
		vector<pair<int,int>> a;
		for (int i = 0; i < n; ++i) {
			int x; cin >> x;
			a.emplace_back(x, i);
		}
		vector<pair<int,int>> b = a;
		sort(b.rbegin(), b.rend());
		
		long long ans = 0;
		for (int i = 0; i < n; ++i) {
			update(b[i].second, b[i].first);
			ans += query_values(b[i].second, n) - 1ll * b[i].first * (query_freq(b[i].second, n)); 
		
		}
		cout << ans << "\n";
	}
	return 0;
}
