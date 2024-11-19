#include <bits/stdc++.h>
using namespace std;
int n;
const int inf = 2e9;
long long f(vector<int>& a) {
    int k = a.size();
    if (k == 1) return 1LL * a.back();
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < k / 2; ++i) A.emplace_back(a[i]);
    for (int i = k / 2; i < k; ++i) B.emplace_back(a[i]);
    long long sumA = f(A);
    long long sumB = f(B);
    int aux = -inf;
    for (int i = A.size() - 1; i >= 0; --i) {
        A[i] = max(aux, A[i]);
        aux = A[i];
    }
    aux = -inf;
    for (int i = 0; i < B.size(); ++i) {
        B[i] = max(B[i], aux);
        aux = B[i];
    }
    long long sum = 0;
    for (int i = 0, j = B.size() - 1; i < A.size() && j >= 0; ) {
        if (A[i] < B[j]) {
            sum += 1LL * B[j] * (A.size() - i);
            --j;
        }
        else {
            sum += 1LL * A[i] * (j + 1);
            ++i;
        }
    }
    return sum + sumA + sumB;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    vector<int> a(n);
    for (int& e : a) cin >> e;
    vector<int> neg(n);
    for (int i = 0; i < n; ++i) neg[i] = -a[i]; 
    long long v1 = f(a);
    long long v2 = f(neg);
    cout << v1 + v2 << "\n";
    return 0;
}
