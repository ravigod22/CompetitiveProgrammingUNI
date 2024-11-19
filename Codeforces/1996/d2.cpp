#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int myrand(int x) {
    uniform_int_distribution<int> dis(1, x);
    return dis(rng);
}

long long solve1(int n, int x) {
    long long ans = 0;
    for (int a = 1; a <= n; ++a) {
        for (int b = 1; a * b <= n && a + b <= x; ++b) {
            ans += min((n - a * b) / (a + b), x - a - b);
        }   
    }
    return ans;
}

long long solve2(int n, int x) {
    ll count = 0;
    vector<vector<int>> factors(n + 1);
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = i; j <= n; j += i)
        {
            factors[j].push_back(i);
        }
    }
 
    // store all factors for a number from 1 to n
    for (ll p1 = 1; p1 < n; p1++)
    {
        for (auto j : factors[p1])
        {
 
            ll sum = j + p1 / j;
            ll rem1 = x - sum;
            ll rem2 = (n - p1) / sum;
            count += max(0ll, min(rem1, rem2));
        }
    }
    return count;
}    

int main() {
    /*
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    */
    for (int i = 0; i < 10; ++i) {
        int n = myrand(1e6 + 1);
        int x = myrand(1e6 + 1);
        //cout << "test " << i + 1 << " input -> " << n << " " << x << "\n";
        long long ans1 = solve1(n, x); 
        long long ans2 = solve2(n, x);
        if (ans1 != ans2) {
            cout << "test failed\n";
            cout << n << " " << x << "\n";
            break;
        }
    }    
    return 0;
}


