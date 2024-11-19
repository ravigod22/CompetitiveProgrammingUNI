#include <bits/stdc++.h>
using namespace std;
int n;

long long f(vector<int>& a) {
    int k = a.size();
    if (k == 1) return 0;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < k / 2; ++i) A.emplace_back(a[i]);
    for (int i = k / 2; i < k; ++i) B.emplace_back(a[i]);
    long long sum = f(A) + f(B);
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    long long ans = f(a);
    cout << ans << "\n";
    return 0;
}
