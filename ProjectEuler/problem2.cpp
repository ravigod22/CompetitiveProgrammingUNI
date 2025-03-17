#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    i64 sum = 0;
    vector<int> fibo = {1, 1};
    while (true) {
        int next = fibo[(int)fibo.size() - 1] + fibo[(int)fibo.size() - 2];
        if (next >= 4e6) break;
        if (next % 2 == 0) sum += next;
        fibo.push_back(next);
    }
    cout << sum << "\n";
    return 0;
}
