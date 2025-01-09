#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e8;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int myRand(int b) {
	return (unsigned int)rng() % b;
}

int main() {
	int n = 3000;
	cout << n << "\n";
    for (int i = 0; i < n; ++i) cout << myRand(maxn) << " "; 
    return 0;
}
