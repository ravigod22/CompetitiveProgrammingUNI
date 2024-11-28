#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int init, int tmp, int fin) {
    if (n == 0) return;
    hanoi(n - 1, init, fin, tmp);
    cout << "Move from " << (char)(init - 1 + 'A') << " to " << (char)(fin - 1 + 'A') << ".\n";
    hanoi(n - 1, tmp, init, fin);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt;
    cin >> tt;
    while (tt--) {
        int n; cin >> n;
        char I, F; cin >> I >> F;
        int init = I - 'A' + 1;
        int fin = F - 'A' + 1;
        int tmp = init ^ fin;
        hanoi(n, init, tmp, fin);
        cout << "Done!\n";
    }
    return 0;
}
