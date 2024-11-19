#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int pos = 1, neg = 0;
	int tmp = 1;
	for (int i = 0; i < n; ++i) {
		if (a[i] < 0) tmp *= -1;
		if (tmp > 0) {
			pos++;
		}
		else {
			neg++;
		}
	}
	long long total = (1ll * n * (n + 1)) / 2;
	long long result = 1ll * pos * neg;
	cout << result << " " << total - result << "\n";
	return 0;
}
