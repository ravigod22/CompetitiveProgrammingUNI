#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 f(int num) {
    vector<int> tmp;
    while (num) {
        tmp.push_back(num);
        num /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    for (int i = tmp.size() - 1; i; --i) {
        tmp[i] -= tmp[i - 1];
    }
    i64 ans = 0;
    for (int i = 0; i < tmp.size(); ++i) {
        int remain = tmp[i] % 9;
        int blocks = tmp[i] / 9;
        ans += 1LL * 45 * blocks + (1LL * remain * (remain + 1)) / 2;
    }
    return ans;
}

int base10(int x, int times) {
    int tmp = x;
    for (int i = 0; i < times; ++i) tmp *= 10;
    return tmp;
}

i64 g(int L) {
    if (L <= 0) return 0;
    i64 res = 0;
    int cnt = 0;
    while (L) {
        int remain = L % 10;
        int number = base10(remain, cnt);
        if (remain) res += f(number);
        L /= 10;
        cnt++;
    }
    return res;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    while (true) {
        cin >> x >> y;
        if (x == -1 && y == -1) break;
        cout << g(y) - g(x - 1) << "\n";
    }
    return 0;
}
