#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n = 11;
    vector<int> a(n);
    iota(a.begin(), a.end(), 1);
    set<int> elem;
    cout << n << "\n";
    do {
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            v[i] = abs(i + 1 - a[i]);
            sum += v[i];
        }
        /*
        cout << "permutation ";
        for (int i = 0; i < n; ++i) {
            cout << v[i] << " \n"[i + 1 == n];
        }
        cout << "sum -> " << sum;
        */
        elem.emplace(sum);
    } while (next_permutation(a.begin(), a.end()));
    for (int e : elem) cout << e << " ";
    return 0;
}
