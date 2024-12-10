#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b;
	vector<int> left, right;
	while (cin >> a >> b) {
		left.emplace_back(a);
		right.emplace_back(b);
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	const int n = left.size();
	long long sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += abs(0LL + left[i] - right[i]);
	}
	cout << sum;
	return 0;
}
