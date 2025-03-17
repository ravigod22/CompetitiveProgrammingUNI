#include <bits/stdc++.h>
using namespace std;

random_device rd;
mt19937 g(rd());

#define dbg(x) cerr << #x << " = " << x << endl
#define pv(x) cerr << #x << "[]: "; for (auto e : x) cerr << e << " "; cerr << endl
#define raya cerr << string(20, '=') << endl

int ask(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    int newp; cin >> newp;
    return newp;
}


void solve() {
    int n; cin >> n;
    int lim = 75;
    int a[3] = {1, 2 ,3};
    while (lim--) {
        int newP = ask(a[0], a[1], a[2]);
        if (newP == 0) {
            cout << "! " << a[0] << " " << a[1] << " " << a[2] << endl;
            break;
        }
        shuffle(a, a + 3, g);
        swap(newP, a[2]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1; 
    cin >> tt;
    while (tt--) {
        solve();
    }
    return 0;
}


