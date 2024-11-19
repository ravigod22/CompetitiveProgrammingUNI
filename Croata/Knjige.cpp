#include <bits/stdc++.h>
using namespace std;

void solve() {
	long long n, t, a, b;
	cin >> n >> t >> a >> b;
	vector<int> values(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> values[i];
	}
	vector<long long> prefix(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		prefix[i] = 1ll * values[i] + prefix[i - 1];
	}
	if (n == 1) {
		if (t < a) {
			cout << 0 << '\n';
		}
		else {
			cout << values[0] << '\n';
		}
	}
	/*
	if (n * a <= t) {
		cout << prefix[n] << '\n';
		return;
	}
	*/
	long long maximums = t / a;
	if (maximums < 1) {
		cout << 0 << '\n';
		return;
	} 
	
	long long n_minimuns = t - (maximums * a);
	long long minimums = n_minimuns / b;
	//cout << maximums << " " << minimums << '\n';
	if (maximums + minimums > n) {
		cout << prefix[n] - prefix[n - maximums < 0 ? 0 : n - maximums] << '\n';
	}
	else {
		cout << prefix[maximums + minimums] - prefix[minimums] << '\n';
	}
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
