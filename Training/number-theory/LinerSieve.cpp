#include <bits/stdc++.h>
using namespace std;
const int N = 1e7;
vector<int> lp(N + 1);
vector<int> pr;

void sieve() {
    for (int i = 2; i <= N; ++i) {
        if (lp[i] == 0) {
            // verificate if 'i' is a prime
            lp[i] = i;
            pr.emplace_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
            lp[i * pr[j]] = pr[j];
            if (lp[i] == pr[j]) break;
        }
    }
}

int main() {
    sieve();
    for (int i = 2; i <= 50; ++i) {
        cout << "i -> " << i << " , minimal prime of i -> " << lp[i] << "\n";
    }
    return 0;
}
