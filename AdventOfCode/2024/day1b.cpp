#include<iostream>
#include<map>
#include <vector>
using namespace std;

int main() {
    int a, b;
    vector<int> left, right;
    map<int, int> cnt;
    while (cin >> a >> b) {
        left.emplace_back(a);
        cnt[b]++;
    }
    long long sum = 0;
    const int n = left.size();
    for (int i = 0; i < n; ++i) {
        sum += 1LL * left[i] * cnt[left[i]];
    }
    cout << sum;
    return 0;
}
