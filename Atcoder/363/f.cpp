#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
map<i64, bool> dp;
vector<i64> divi;

bool is_palin(i64 n) {
    string num = to_string(n);
    int len = num.size();
    for (int i = 0; i < len / 2; ++i) {
        if (num[i] != num[len - i - 1]) return false;
    }
    return true;
}

bool can(i64 n) {
    string num = to_string(n);
    for (char e : num) {
        if (e == '0') return false;
    }
    return true;
}

bool f(i64 n) {
    if (n == 1) return true;
    if (is_palin(n) && can(n)) return true;
    if (dp.count(n)) return dp[n];
    bool &ans = dp[n] = false;
    for (auto e : divi) {
        if (e > n) break;
        if (e == 1) continue;
        if (!can(e)) continue;
        if (n % e) continue;
        string num = to_string(e);
        reverse(num.begin(), num.end());
        i64 inv = stoll(num);
        i64 remain = n / e;
        if (remain % inv != 0) continue;
        ans |= f(remain / inv);
    }
    return ans;
}

string build(i64 n) {
    if (n == 1) return "1";
    if (is_palin(n) && can(n)) return to_string(n);
    string ans;
    for (auto e : divi) {
        if (e > n) break;
        if (e == 1) continue;
        if (!can(e)) continue;
        if (n % e) continue;
        string num = to_string(e);
        reverse(num.begin(), num.end());
        i64 inv = stoll(num);
        i64 remain = n / e;
        if (remain % inv) continue;
        if (f(remain / inv)) {
            ans = to_string(e) + "*" + build(remain / inv) + "*" + num;
            break;
        }
    }
    return ans;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    i64 n;
    cin >> n;
    for (i64 i = 1; i * i <= n; ++i) {
        if (n % i) continue;
        divi.push_back(i);
        if (i != n / i) {
            divi.push_back(n / i);
        }
    }
    sort(divi.begin(), divi.end());
    bool could = f(n);
    if (could) cout << build(n) << "\n";
    else cout << "-1\n";
    return 0;
}
