#include <bits/stdc++.h>
using namespace std;

vector<int> primes(int a) {
    vector<int> res;
    for (int i = 2; i * i <= a; ++i) {
        if (a % i) continue;
        while (a % i == 0) {
            res.push_back(i);
            a /= i;
        }
    }
    if (a > 1) res.push_back(a);
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> divi;
    int tmp = abs(n);
    bool sign = n < 0;
    for (int i = 1; i * i <= tmp; ++i) {
        if (tmp % i) continue;
        divi.push_back(i);
        if (tmp / i != i) {
            divi.push_back(tmp / i);
        }
    }
    sort(divi.begin(), divi.end());
    vector<vector<int>> sol;
    for (int e : divi) {
        int numL = e;
        int numR = tmp / e;
        vector<int> L = primes(numL);
        vector<int> R = primes(numR);
        reverse(L.begin(), L.end());
        vector<int> tmp;
        for (int e : L) tmp.push_back(-e);
        for (int e : R) tmp.push_back(e);
        bool aux = ((int)L.size() & 1 ? true : false);
        if (aux == sign) {
            sol.push_back(tmp);
        }
    }
    sort(sol.begin(), sol.end());
    cout << (int)sol.size() << "\n";
    for (auto e : sol) {
        for (int p : e) cout << p << " ";
        cout << "\n";
    }
    return 0;
}
